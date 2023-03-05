/*
* 
* main.c - contains the entry point of HConsole
* The Hconsole Project is made by Copy05
* 
* (c) Copy05 2020-2023
* ~~~~~~~~~~~~~[ Author ]~~~~~~~~~~~~~~~~~~~~~~
*	Copy05 [https://github.com/Copy05/]
*/

#pragma warning( disable : 6031 )

#include "stdheads.h"
#include "hcommands.h"

#if __unix
const char* _print_user(){
	struct passwd *pw = getpwuid(geteuid());
	return pw ? pw->pw_name : "user";
}
#endif

int main(int argc, char** argv) {
	char cmd[128];
	char f[128];
	char opts[128];

	printf("%c]0;%s%c", '\033', "HConsole", '\007');

	while (1) {
		#if __unix
		printf("%shc:~$ ", _print_user());
		#else
		printf("hc:~$ ");
		#endif
		scanf("%127s%127s%127s", cmd, f, opts);

		handle_cmd(cmd, f, opts);

		// free the arrays for the next use
		memset(&cmd[0], 0, sizeof(cmd));
		memset(&f[0], 0, sizeof(f));
		memset(&opts[0], 0, sizeof(opts));
	}

	return 0x00;
}