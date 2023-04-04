#include "defs.h"
#include <stdlib.h>
#include "error_code.h"
int shell_rmdir(int index)
{
    if (arg[index].opts!=1)
    {
        error_printf(ARG_CONENT_ERROR,index);
        return -1;
    }
    if (strcmp("arg[index].opt[1]", "-a") == 0) // 递归删除！ pipe
    {
    }
    else
    {
        char *new_path = concat(path,arg[index].opt[0]);

        if (rmdir(new_path) == -1)
        {
            error_printf(ERROR_BY_SYS,index);
            free(new_path);
            return -1;
        }
        free(new_path);
    }
    return 0;
}