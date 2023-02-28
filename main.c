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

int main(int argc, char** argv) {
	char cmd[128];
	char f[128];
	char opts[128];

	while (1) {
		printf("hc:~$ ");
		scanf("%127s%127s%127s", cmd, f, opts);

		handle_cmd(cmd, f, opts);

		memset(&cmd[0], 0, sizeof(cmd));
		memset(&f[0], 0, sizeof(f));
		memset(&opts[0], 0, sizeof(opts));
	}

	return 0x00;
}