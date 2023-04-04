#include "defs.h"
#include "error_code.h"
#include <dirent.h>
#include <sys/stat.h>
int shell_chmod(int index)
{
    // chmod quanxian feile or dir
    if (arg[index].opts != 2)
    {
        error_printf(ARG_NUM_ERROR, index);
        return -1;
    }
    struct stat st;
    char *new_path= concat(path, arg[index].opt[1]);

    if (stat(new_path, &st) == -1)
    {
        error_printf(ERROR_BY_SYS, 1);
        return -1;
    }
    mode_t new_mode = 0x0000;
    for (size_t i = 0; i < 3; i++)
    {
        char tem = arg[index].opt[0][i];
        uint num = atoi(&tem);
        new_mode = new_mode | num << (2 - i) * 3;
    }
    if (-1 == chmod(new_path, new_mode))
    {
        free(new_path);
        error_printf(ERROR_BY_SYS, index);
        return -1;
    }
    free(new_path);
    return 0;
}