/*
 * @Author: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-04-01 12:00:59
 * @LastEditors: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-04 14:40:39
 * @FilePath: /linux_shell/src/output.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include "defs.h"
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
// 重定向功能实现
void outputfile(int index)
{
    int fd = 0;
    char *new_path=NULL;
    if (arg[index].remap_out_file == NULL)
        perror("");

    // 尝试把参数当作路径➕文件
    if ((fd = open(arg[index].remap_out_file, O_RDWR | O_CREAT |O_APPEND, 0777)) == -1)
    {
        new_path = concat(path, arg[index].remap_out_file);
        if ((fd = open(new_path, O_RDWR | O_CREAT|O_APPEND, 0777)) == -1)
        {
            perror("");
            return ;
        }
    }

    if (write(fd, result_out, result_out_count) == -1)
    {
        perror("");
    }
    if(new_path!=NULL)free(new_path);
    close(fd);
}
// 多管道的实现
void outputpipe() //
{
    close(RX_FD[PIPE_READ]);
    write(RX_FD[PIPE_WRITE], result_out, result_out_count);
}
// 输出函数 函数形式建立的功能都需要调用此函数输出
void output(int index)
{
    if (arg[index].remap_out == 1) // 如果重定向了那么就不应该写pipe了
    {
        outputfile(index);
    }
    else if (arg[index].write_to_pipe == 1)
    { // 如果写pipe就不应该直接输出
        outputpipe();
    }
    else // 直接输出
    {
        printf("%s", result_out);
    }
    delete_result();
}
