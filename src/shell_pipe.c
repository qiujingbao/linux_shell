/*
 * @Author: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-04-04 18:58:35
 * @LastEditors: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-20 10:04:44
 * @FilePath: /linux_shell/src/shell_pipe.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "defs.h"

int init_pipe_process()
{
    if (com_num == 1)
    {
        return 0;
    }
    else if (com_num == 2)
    {
        arg[0].write_to_pipe = 1;
        arg[1].read_from_pipe = 1;
    }
    else
    {
        arg[0].write_to_pipe = 1;
        for (size_t i = 1; i < com_num - 1; i++)
        {
            arg[i].read_from_pipe = 1;
            arg[i].write_to_pipe = 1;
        }
        arg[com_num - 1].read_from_pipe = 1;
        arg[com_num - 1].write_to_pipe = 0;
    }
}