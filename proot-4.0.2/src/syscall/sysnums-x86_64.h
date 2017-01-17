#include "syscall/sysnum.h"

static const Sysnum sysnums_x86_64[] = {
	[ 0 ] = PR_read,
	[ 1 ] = PR_write,
	[ 2 ] = PR_open,
	[ 3 ] = PR_close,
	[ 4 ] = PR_stat,
	[ 5 ] = PR_fstat,
	[ 6 ] = PR_lstat,
	[ 7 ] = PR_poll,
	[ 8 ] = PR_lseek,
	[ 9 ] = PR_mmap,
	[ 10 ] = PR_mprotect,
	[ 11 ] = PR_munmap,
	[ 12 ] = PR_brk,
	[ 13 ] = PR_rt_sigaction,
	[ 14 ] = PR_rt_sigprocmask,
	[ 15 ] = PR_rt_sigreturn,
	[ 16 ] = PR_ioctl,
	[ 17 ] = PR_pread64,
	[ 18 ] = PR_pwrite64,
	[ 19 ] = PR_readv,
	[ 20 ] = PR_writev,
	[ 21 ] = PR_access,
	[ 22 ] = PR_pipe,
	[ 23 ] = PR_select,
	[ 24 ] = PR_sched_yield,
	[ 25 ] = PR_mremap,
	[ 26 ] = PR_msync,
	[ 27 ] = PR_mincore,
	[ 28 ] = PR_madvise,
	[ 29 ] = PR_shmget,
	[ 30 ] = PR_shmat,
	[ 31 ] = PR_shmctl,
	[ 32 ] = PR_dup,
	[ 33 ] = PR_dup2,
	[ 34 ] = PR_pause,
	[ 35 ] = PR_nanosleep,
	[ 36 ] = PR_getitimer,
	[ 37 ] = PR_alarm,
	[ 38 ] = PR_setitimer,
	[ 39 ] = PR_getpid,
	[ 40 ] = PR_sendfile,
	[ 41 ] = PR_socket,
	[ 42 ] = PR_connect,
	[ 43 ] = PR_accept,
	[ 44 ] = PR_sendto,
	[ 45 ] = PR_recvfrom,
	[ 46 ] = PR_sendmsg,
	[ 47 ] = PR_recvmsg,
	[ 48 ] = PR_shutdown,
	[ 49 ] = PR_bind,
	[ 50 ] = PR_listen,
	[ 51 ] = PR_getsockname,
	[ 52 ] = PR_getpeername,
	[ 53 ] = PR_socketpair,
	[ 54 ] = PR_setsockopt,
	[ 55 ] = PR_getsockopt,
	[ 56 ] = PR_clone,
	[ 57 ] = PR_fork,
	[ 58 ] = PR_vfork,
	[ 59 ] = PR_execve,
	[ 60 ] = PR_exit,
	[ 61 ] = PR_wait4,
	[ 62 ] = PR_kill,
	[ 63 ] = PR_uname,
	[ 64 ] = PR_semget,
	[ 65 ] = PR_semop,
	[ 66 ] = PR_semctl,
	[ 67 ] = PR_shmdt,
	[ 68 ] = PR_msgget,
	[ 69 ] = PR_msgsnd,
	[ 70 ] = PR_msgrcv,
	[ 71 ] = PR_msgctl,
	[ 72 ] = PR_fcntl,
	[ 73 ] = PR_flock,
	[ 74 ] = PR_fsync,
	[ 75 ] = PR_fdatasync,
	[ 76 ] = PR_truncate,
	[ 77 ] = PR_ftruncate,
	[ 78 ] = PR_getdents,
	[ 79 ] = PR_getcwd,
	[ 80 ] = PR_chdir,
	[ 81 ] = PR_fchdir,
	[ 82 ] = PR_rename,
	[ 83 ] = PR_mkdir,
	[ 84 ] = PR_rmdir,
	[ 85 ] = PR_creat,
	[ 86 ] = PR_link,
	[ 87 ] = PR_unlink,
	[ 88 ] = PR_symlink,
	[ 89 ] = PR_readlink,
	[ 90 ] = PR_chmod,
	[ 91 ] = PR_fchmod,
	[ 92 ] = PR_chown,
	[ 93 ] = PR_fchown,
	[ 94 ] = PR_lchown,
	[ 95 ] = PR_umask,
	[ 96 ] = PR_gettimeofday,
	[ 97 ] = PR_getrlimit,
	[ 98 ] = PR_getrusage,
	[ 99 ] = PR_sysinfo,
	[ 100 ] = PR_times,
	[ 101 ] = PR_ptrace,
	[ 102 ] = PR_getuid,
	[ 103 ] = PR_syslog,
	[ 104 ] = PR_getgid,
	[ 105 ] = PR_setuid,
	[ 106 ] = PR_setgid,
	[ 107 ] = PR_geteuid,
	[ 108 ] = PR_getegid,
	[ 109 ] = PR_setpgid,
	[ 110 ] = PR_getppid,
	[ 111 ] = PR_getpgrp,
	[ 112 ] = PR_setsid,
	[ 113 ] = PR_setreuid,
	[ 114 ] = PR_setregid,
	[ 115 ] = PR_getgroups,
	[ 116 ] = PR_setgroups,
	[ 117 ] = PR_setresuid,
	[ 118 ] = PR_getresuid,
	[ 119 ] = PR_setresgid,
	[ 120 ] = PR_getresgid,
	[ 121 ] = PR_getpgid,
	[ 122 ] = PR_setfsuid,
	[ 123 ] = PR_setfsgid,
	[ 124 ] = PR_getsid,
	[ 125 ] = PR_capget,
	[ 126 ] = PR_capset,
	[ 127 ] = PR_rt_sigpending,
	[ 128 ] = PR_rt_sigtimedwait,
	[ 129 ] = PR_rt_sigqueueinfo,
	[ 130 ] = PR_rt_sigsuspend,
	[ 131 ] = PR_sigaltstack,
	[ 132 ] = PR_utime,
	[ 133 ] = PR_mknod,
	[ 134 ] = PR_uselib,
	[ 135 ] = PR_personality,
	[ 136 ] = PR_ustat,
	[ 137 ] = PR_statfs,
	[ 138 ] = PR_fstatfs,
	[ 139 ] = PR_sysfs,
	[ 140 ] = PR_getpriority,
	[ 141 ] = PR_setpriority,
	[ 142 ] = PR_sched_setparam,
	[ 143 ] = PR_sched_getparam,
	[ 144 ] = PR_sched_setscheduler,
	[ 145 ] = PR_sched_getscheduler,
	[ 146 ] = PR_sched_get_priority_max,
	[ 147 ] = PR_sched_get_priority_min,
	[ 148 ] = PR_sched_rr_get_interval,
	[ 149 ] = PR_mlock,
	[ 150 ] = PR_munlock,
	[ 151 ] = PR_mlockall,
	[ 152 ] = PR_munlockall,
	[ 153 ] = PR_vhangup,
	[ 154 ] = PR_modify_ldt,
	[ 155 ] = PR_pivot_root,
	[ 156 ] = PR__sysctl,
	[ 157 ] = PR_prctl,
	[ 158 ] = PR_arch_prctl,
	[ 159 ] = PR_adjtimex,
	[ 160 ] = PR_setrlimit,
	[ 161 ] = PR_chroot,
	[ 162 ] = PR_sync,
	[ 163 ] = PR_acct,
	[ 164 ] = PR_settimeofday,
	[ 165 ] = PR_mount,
	[ 166 ] = PR_umount2,
	[ 167 ] = PR_swapon,
	[ 168 ] = PR_swapoff,
	[ 169 ] = PR_reboot,
	[ 170 ] = PR_sethostname,
	[ 171 ] = PR_setdomainname,
	[ 172 ] = PR_iopl,
	[ 173 ] = PR_ioperm,
	[ 174 ] = PR_create_module,
	[ 175 ] = PR_init_module,
	[ 176 ] = PR_delete_module,
	[ 177 ] = PR_get_kernel_syms,
	[ 178 ] = PR_query_module,
	[ 179 ] = PR_quotactl,
	[ 180 ] = PR_nfsservctl,
	[ 181 ] = PR_getpmsg,
	[ 182 ] = PR_putpmsg,
	[ 183 ] = PR_afs_syscall,
	[ 184 ] = PR_tuxcall,
	[ 185 ] = PR_security,
	[ 186 ] = PR_gettid,
	[ 187 ] = PR_readahead,
	[ 188 ] = PR_setxattr,
	[ 189 ] = PR_lsetxattr,
	[ 190 ] = PR_fsetxattr,
	[ 191 ] = PR_getxattr,
	[ 192 ] = PR_lgetxattr,
	[ 193 ] = PR_fgetxattr,
	[ 194 ] = PR_listxattr,
	[ 195 ] = PR_llistxattr,
	[ 196 ] = PR_flistxattr,
	[ 197 ] = PR_removexattr,
	[ 198 ] = PR_lremovexattr,
	[ 199 ] = PR_fremovexattr,
	[ 200 ] = PR_tkill,
	[ 201 ] = PR_time,
	[ 202 ] = PR_futex,
	[ 203 ] = PR_sched_setaffinity,
	[ 204 ] = PR_sched_getaffinity,
	[ 205 ] = PR_set_thread_area,
	[ 206 ] = PR_io_setup,
	[ 207 ] = PR_io_destroy,
	[ 208 ] = PR_io_getevents,
	[ 209 ] = PR_io_submit,
	[ 210 ] = PR_io_cancel,
	[ 211 ] = PR_get_thread_area,
	[ 212 ] = PR_lookup_dcookie,
	[ 213 ] = PR_epoll_create,
	[ 214 ] = PR_epoll_ctl_old,
	[ 215 ] = PR_epoll_wait_old,
	[ 216 ] = PR_remap_file_pages,
	[ 217 ] = PR_getdents64,
	[ 218 ] = PR_set_tid_address,
	[ 219 ] = PR_restart_syscall,
	[ 220 ] = PR_semtimedop,
	[ 221 ] = PR_fadvise64,
	[ 222 ] = PR_timer_create,
	[ 223 ] = PR_timer_settime,
	[ 224 ] = PR_timer_gettime,
	[ 225 ] = PR_timer_getoverrun,
	[ 226 ] = PR_timer_delete,
	[ 227 ] = PR_clock_settime,
	[ 228 ] = PR_clock_gettime,
	[ 229 ] = PR_clock_getres,
	[ 230 ] = PR_clock_nanosleep,
	[ 231 ] = PR_exit_group,
	[ 232 ] = PR_epoll_wait,
	[ 233 ] = PR_epoll_ctl,
	[ 234 ] = PR_tgkill,
	[ 235 ] = PR_utimes,
	[ 236 ] = PR_vserver,
	[ 237 ] = PR_mbind,
	[ 238 ] = PR_set_mempolicy,
	[ 239 ] = PR_get_mempolicy,
	[ 240 ] = PR_mq_open,
	[ 241 ] = PR_mq_unlink,
	[ 242 ] = PR_mq_timedsend,
	[ 243 ] = PR_mq_timedreceive,
	[ 244 ] = PR_mq_notify,
	[ 245 ] = PR_mq_getsetattr,
	[ 246 ] = PR_kexec_load,
	[ 247 ] = PR_waitid,
	[ 248 ] = PR_add_key,
	[ 249 ] = PR_request_key,
	[ 250 ] = PR_keyctl,
	[ 251 ] = PR_ioprio_set,
	[ 252 ] = PR_ioprio_get,
	[ 253 ] = PR_inotify_init,
	[ 254 ] = PR_inotify_add_watch,
	[ 255 ] = PR_inotify_rm_watch,
	[ 256 ] = PR_migrate_pages,
	[ 257 ] = PR_openat,
	[ 258 ] = PR_mkdirat,
	[ 259 ] = PR_mknodat,
	[ 260 ] = PR_fchownat,
	[ 261 ] = PR_futimesat,
	[ 262 ] = PR_newfstatat,
	[ 263 ] = PR_unlinkat,
	[ 264 ] = PR_renameat,
	[ 265 ] = PR_linkat,
	[ 266 ] = PR_symlinkat,
	[ 267 ] = PR_readlinkat,
	[ 268 ] = PR_fchmodat,
	[ 269 ] = PR_faccessat,
	[ 270 ] = PR_pselect6,
	[ 271 ] = PR_ppoll,
	[ 272 ] = PR_unshare,
	[ 273 ] = PR_set_robust_list,
	[ 274 ] = PR_get_robust_list,
	[ 275 ] = PR_splice,
	[ 276 ] = PR_tee,
	[ 277 ] = PR_sync_file_range,
	[ 278 ] = PR_vmsplice,
	[ 279 ] = PR_move_pages,
	[ 280 ] = PR_utimensat,
	[ 281 ] = PR_epoll_pwait,
	[ 282 ] = PR_signalfd,
	[ 283 ] = PR_timerfd_create,
	[ 284 ] = PR_eventfd,
	[ 285 ] = PR_fallocate,
	[ 286 ] = PR_timerfd_settime,
	[ 287 ] = PR_timerfd_gettime,
	[ 288 ] = PR_accept4,
	[ 289 ] = PR_signalfd4,
	[ 290 ] = PR_eventfd2,
	[ 291 ] = PR_epoll_create1,
	[ 292 ] = PR_dup3,
	[ 293 ] = PR_pipe2,
	[ 294 ] = PR_inotify_init1,
	[ 295 ] = PR_preadv,
	[ 296 ] = PR_pwritev,
	[ 297 ] = PR_rt_tgsigqueueinfo,
	[ 298 ] = PR_perf_event_open,
	[ 299 ] = PR_recvmmsg,
	[ 300 ] = PR_fanotify_init,
	[ 301 ] = PR_fanotify_mark,
	[ 302 ] = PR_prlimit64,
	[ 303 ] = PR_name_to_handle_at,
	[ 304 ] = PR_open_by_handle_at,
	[ 305 ] = PR_clock_adjtime,
	[ 306 ] = PR_syncfs,
	[ 307 ] = PR_sendmmsg,
	[ 308 ] = PR_setns,
	[ 309 ] = PR_getcpu,
	[ 310 ] = PR_process_vm_readv,
	[ 311 ] = PR_process_vm_writev,
	[ 312 ] = PR_kcmp,
};
