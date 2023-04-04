#include "defs.h"
#include <stdio.h>
#include <sys/stat.h>
#include "error_code.h"
int shell_mkdir(int index)
{
    if (arg[index].opts != 1)
    {
        error_printf(ERROR_BY_SYS,index);
        return -1;
    }

    char *new_path =concat(path,arg[index].opt[0]);

    if (mkdir(new_path,0x1FF) == -1)
    {
        error_printf(ERROR_BY_SYS,index);
        free(new_path);
        return -1;
    }
    free(new_path);
    return 0;
}