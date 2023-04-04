#include "defs.h"
#include "error_code.h"
int cd(int index)
{
    if (chdir(args[1]) == 0)
    {
        path=getcwd(NULL,0);
        return 0;
    }
    error_printf(PATH_ERROR,1);
    return -1;
}