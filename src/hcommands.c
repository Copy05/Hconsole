/*
*
* hcommand.c - contains the commands from HConsole
* The Hconsole Project is made by Copy05
*
* (c) Copy05 2020-2023
* ~~~~~~~~~~~~~[ Author ]~~~~~~~~~~~~~~~~~~~~~~
*   Copy05 [https://github.com/Copy05/]
*   MRAXXX [https://github.com/MRAXXX/]
*/

#pragma warning(disable : 4996)
#pragma warning(disable : 6262)

#include "hcommands.h"
#include "stdheads.h"
#include <Hconsole/commands.h>

void print_ver(void)
{
    const int MAJV = 0x00;
    const int MIV = 0x02;
    const char* PROJURL = "https://github.com/Copy05/hconsole";

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("HConsole v%d.%d [%s]\nCopyright Copy05 2020-%d\n\n", MAJV, MIV, PROJURL, tm.tm_year + 0x076C);
}

void handle_cmd(const char* cmd, const char* f, const char* opts)
{
    if (strcmp(cmd, "help") == 0x00)
        print_help(f);
    else if (strcmp(cmd, "exit") == 0x00)
        exit(0x00);
    else if (strcmp(cmd, "subenum") == 0x00)
        subdomain_enumeration(f, opts);
    else if (strcmp(cmd, "portscan") == 0x00)
        port_scan(f, atoi(opts));
    else
        printf("The command \"%s\" has not been found.\n", cmd);
}

void print_help(const char* _cmd)
{
    print_ver();

    if (strcmp(_cmd, "subenum") == 0x00) {
        printf("Usage: subenum [domain]\n"
        "[domain]\t\t\t Is the domain you want to scan for subdomains\n");
        return;
    }
    if (strcmp(_cmd, "portscan") == 0x00) {
        printf("Usage: portscan [domain] [port]\n"
        "[domain]\t\t\t Is the domain you want to scan for\n"
        "[port]\t\t\t The Port you want to scan for\n");
        return;
    }
    if (strcmp(_cmd, "help") == 0x00) {
        printf("Usage: help [cmd]\n"
            "[cmd]\t\t\t The command you want to get details about it\n");
        return;
    }
    if (strcmp(_cmd, "exit") == 0x00) {
        printf("Usage: exit\n"
            "Exits Hconsole\n");
        return;
    }
    else {
        printf("Usage: [command] [options]\n"
            "HELP\t\tShows all available commands\n"
            "EXIT\t\tExits Hconsole\n"
            "PORTSCAN\t\tScans a port to see if it's open or not\n"
            "SUBENUM\t\tenumerates through the passed domain for subdomains\n");
    }
}