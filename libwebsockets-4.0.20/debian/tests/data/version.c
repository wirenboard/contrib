#include <stdio.h>

#include <libwebsockets.h>

int
main(void)
{
	puts(lws_get_library_version());
	return 0;
}
