/*
*
* stdheads.h - contains the standart C Library
* The Hconsole Project is made by Copy05
*
* (c) Copy05 2020-2023
* ~~~~~~~~~~~~~[ Author ]~~~~~~~~~~~~~~~~~~~~~~
*   Copy05 [https://github.com/Copy05/]
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#if __unix
#include <unistd.h>
#include <pwd.h>
#endif

typedef unsigned int u32;
typedef unsigned long long ull;
typedef const char* nstr;