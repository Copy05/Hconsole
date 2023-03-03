/*
*
* hcommand.h - contains the commands from HConsole
* The Hconsole Project is made by Copy05
*
* (c) Copy05 2020-2023
* ~~~~~~~~~~~~~[ Author ]~~~~~~~~~~~~~~~~~~~~~~
*   Copy05 [https://github.com/Copy05/]
*/

#pragma once

void print_ver(void);
void handle_cmd(const char* cmd, const char* f, const char* opts);
void print_help(const char* _cmd);