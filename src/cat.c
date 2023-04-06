/*
 * @Author: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-04-04 18:58:35
 * @LastEditors: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-06 16:53:22
 * @FilePath: /linux_shell/src/cat.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "defs.h"
#include <unistd.h>
#include <fcntl.h>
#include "error_code.h"
int cat(int index)
{
    if (arg[index].opts >= 2)
        return 0;
    int cat_fd;
    delete_result();
    if (arg[index].read_from_pipe == 1)
    {
        char *buf = (char *)malloc(sizeof(char) * 1024 * 4);

        read(TX_FD[PIPE_READ], buf, sizeof(char) * 1024 * 4);
        build_result(buf, strlen(buf));
        free(buf);
        output(index);
    }
    else if ((cat_fd = open(arg[index].opt[0], O_RDONLY)) != -1) // read only
    {
        int num = 0;
        char buf[1024];
        while ((num = read(cat_fd, buf, sizeof(char) * 1024)) != 0)
        {
            build_result(buf, num);
            memset(buf, '\0', sizeof(char) * 1024);
        }
        build_result("\n", strlen("\n"));
        output(index);
    }
    else
    {
        error_printf(ERROR_BY_SYS, 0);
        return -1;
    }
    return 0;
}