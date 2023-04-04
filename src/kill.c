#include "defs.h"
#include <sys/types.h>
#include <signal.h>
#include "error_code.h"
int shell_kill(int index)
{
    if (arg[index].opts != 2)
    {
        error_printf(ERROR_BY_SYS,index);
        return -1;
    }
    int sig = atoi(arg[index].opt[0]);
    int pid = atoi(arg[index].opt[1]);
    if (sig == 0 || pid == 0)
    {
        error_printf(CONVERT_ERROR,index);
        return -1;
    }
    if(kill(pid, sig)==-1)
    {
        error_printf(ERROR_BY_SYS,index);
        return -1;
    }
    return 0;
}