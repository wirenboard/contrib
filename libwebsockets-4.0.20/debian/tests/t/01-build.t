#!/usr/bin/perl

use v5.014;
use strict;
use warnings;

use File::Temp;
use Path::Tiny;
use Test::More;
use Test::Command;
use Text::ParseWords qw(shellwords);

my ($lws_version, @lws_cflags, @lws_libs);

sub get_program_output($; $ $) {
	my ($cmd, $exp_exit, $exp_stderr) = @_;
	$exp_exit //= 0;

	my $cmd_str = join ' ', @$cmd;
	my $c = Test::Command->new(cmd => $cmd);
	$c->exit_is_num($exp_exit, "'$cmd_str' completed as expected");
	if ($exp_stderr) {
		$c->stderr_isnt_eq('',
		    "'$cmd_str' output some errors");
	} else {
		$c->stderr_is_eq('',
		    "'$cmd_str' did not output any errors");
	}
	return ($c->stdout_value, $c->stderr_value);
}

plan tests => 2;

subtest 'Get the libwebsockets data from pkg-config' => sub {
	plan tests => 10;
	my ($pc, $mod) = ('pkg-config', 'libwebsockets');

	my ($out, $err) = get_program_output [$pc, '--modversion', '--', $mod];
	my @lines = split /\r*\n/, $out;
	is @lines, 1, "'$pc --modversion $mod' output a single line";
	like $lines[0], qr/^ (?: \d+ ) (?: \. \d+ )* $/x,
	    "'$pc --modversion $mod' output a version-number-like string";
	$lws_version = $lines[0];

	($out, $err) = get_program_output [$pc, '--cflags', '--', $mod];
	@lines = split /\r*\n/, $out;
	if (@lines == 0) {
		ok 1, "'$pc --cflags $mod' did not output anything";
		@lws_cflags = ();
	} else {
		is @lines, 1, "'$pc --cflags $mod' output a single line";
		@lws_cflags = parse_line $lines[0];
	}

	($out, $err) = get_program_output [$pc, '--libs', '--', $mod];
	@lines = split /\r*\n/, $out;
	is @lines, 1, "'$pc --libs $mod' output a single line";
	@lws_libs = shellwords $lines[0];
};

my $tempd_f = File::Temp->newdir(TMPDIR => 1);
my $tempd = path($tempd_f);

subtest 'Compile a simple program' => sub {
	plan tests => 8;

	my ($obj, $bin) =
	    ($tempd->child('version.o'), $tempd->child('version'));
	get_program_output
	    ['cc', '-c', '-o', $obj, @lws_cflags, 'data/version.c'];
	get_program_output
	    ['cc', '-o', $bin, $obj, @lws_libs];

	my ($out, $err) = get_program_output [$bin];
	my @lines = split /\r*\n/, $out;
	is @lines, 1, 'The test program output a single line';
	like $lines[0], qr/^ \Q$lws_version\E \b /x,
	    'The test program output the correct library version';
};
