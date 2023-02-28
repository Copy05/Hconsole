/*
*
* hcommand.c - contains the commands from HConsole
* The Hconsole Project is made by Copy05
*
* (c) Copy05 2020-2023
* ~~~~~~~~~~~~~[ Author ]~~~~~~~~~~~~~~~~~~~~~~
*   Copy05 [https://github.com/Copy05/]
*/

#include "hcommands.h"
#include "stdheads.h"

#include <time.h>

void print_ver(void)
{
    const int MAJV = 0x00;
    const int MIV = 0x01;
    const char* PROJURL = "https://github.com/Copy05/hconsole";

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("HConsole v%d.%d [%s]\nCopyright Copy05 2020-%d\n\n", MAJV, MIV, PROJURL, tm.tm_year + 0x076C);
}

void handle_cmd(const char* cmd, const char* f, const char* opts)
{
    if (strcmp(cmd, "help") == 0x00)
        print_help();
    else if (strcmp(cmd, "exit") == 0x00)
        exit(0x00);
    else
        printf("The command \"%s\" has not been found.\n", cmd);
}

void print_help(void)
{
    print_ver();
    printf("Usage: ./Hconsole [command] [options]\n"
    "HELP\t\tShows all available commands\n"
    "EXIT\t\tExits Hconsole\n");
}