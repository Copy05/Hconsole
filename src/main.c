/*
*
* main.c - contains the entry point of HConsole
* The Hconsole Project is made by Copy05
*
* (c) Copy05 2020-2023
* ~~~~~~~~~~~~~[ Author ]~~~~~~~~~~~~~~~~~~~~~~
*	Copy05 [https://github.com/Copy05/]
*	MRAXXX [https://github.com/MRAXXX/]
*/

#pragma warning( disable : 6031 ) // VS2022

#include "stdheads.h"
#include "hcommands.h"

#if __unix
const char* _print_user() {
	struct passwd* pw = getpwuid(geteuid());
	return pw ? pw->pw_name : "user";
}
#endif

int main(int argc, char** argv) {
	char cmd[0x080], f[0x080], opts[0x080];

	while (1) {
	#if __unix
		printf("%s@hc:~$ ", _print_user());
	#else
		printf("hc:~$ ");
	#endif
		scanf("%127s%127s%127s", cmd, f, opts);

		handle_cmd(cmd, f, opts);

		// free the arrays for the next use
		memset(&cmd[0x00], 0x00, sizeof(cmd));
		memset(&f[0x00], 0x00, sizeof(f));
		memset(&opts[0x00], 0x00, sizeof(opts));
	}

	return 0x00;
}