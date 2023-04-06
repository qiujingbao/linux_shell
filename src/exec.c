/*
 * @Author: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-04-04 18:58:35
 * @LastEditors: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-06 16:05:37
 * @FilePath: /linux_shell/src/exec.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "defs.h"
#include "error_code.h"
int shell_exec(int index)
{
    if (arg[index].opts < 1)
    {
        error_printf(ARG_CONENT_ERROR, index);
        return -1;
    }

    char *new_path = concat(path, arg[index].opt[0]);

    int pid = fork();
    if (pid < 0)
    {
        error_printf(ERROR_BY_SYS, index);
    }
    else if (pid == 0) //child
    {
        char * child_arg=(char*)malloc(sizeof(char)*1024);
        int len=0;
        for (size_t i = 1; i < arg[index].opts; i++)
        {
            len=append(child_arg,arg[index].opt[i],len,strlen(arg[index].opt[i]));
        }
        
        if(execl(new_path,child_arg,NULL)==-1)
        {
            error_printf(ERROR_BY_SYS,index);
        }
        
    }
    else //father
    {
        //等待结束
        wait(NULL);
    }
}