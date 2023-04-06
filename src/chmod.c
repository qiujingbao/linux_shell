/*
 * @Author: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-04-04 18:58:35
 * @LastEditors: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-06 16:23:39
 * @FilePath: /linux_shell/src/chmod.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

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