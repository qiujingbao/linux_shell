#include "defs.h"
#include <unistd.h>
#include "error_code.h"

int rm_file(char *p,int index)
{
    if (unlink(p) == -1)
    {
        error_printf(ERROR_BY_SYS,index);
        return -1;
    }
    free(p);
    return 0;
}
int rm(int index)
{
    if (arg[index].opts != 1)
    {
        error_printf(ARG_CONENT_ERROR,0);
        return -1;
    }

    char *new_path =concat(path,arg[index].opt[0]);

    return rm_file(new_path,index);
}
