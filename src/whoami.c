#include "defs.h"
int whoami(int index)
{
    char* uname = getenv(USER);
    if (!uname) uname="";
    printf("%s\n",uname);
}