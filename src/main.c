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

int main(int argc, char** argv) {
	char cmd[0x080], f[0x80], opts[0x80];

	printf("%c]0;%s%c", '\033', "HConsole", '\007');

	while (1) {
		printf("hc:~$ ");
		scanf("%127s%127s%127s", cmd, f, opts);

		handle_cmd(cmd, f, opts);

		// free the arrays for the next use
		memset(&cmd[0x00], 0x00, sizeof(cmd));
		memset(&f[0x00], 0x00, sizeof(f));
		memset(&opts[0x00], 0x00, sizeof(opts));
	}

	return 0x00;
}
