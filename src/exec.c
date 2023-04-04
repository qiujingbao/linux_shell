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



// 执行命令
/*
void exec_command(int is_multi,void* func,char *args)
{
    int pid = fork();
    if (pid < 0)
    {
        printf("fork 失败！\n");
        exit(-1);
    }
    else if (pid == 0) // child
    {
        if (execvp(args[0], args) == -1)
        {
            perror("osh>error "); // 打印出错原因
        }
        exit(0);
    }
    else if (pid > 0) // father
    {
        if (is_multi == 0)
            wait(NULL);
    }
}
*/
