/*
 * @Author: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-03-29 20:58:22
 * @LastEditors: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-04 20:46:16
 * @FilePath: /linux_shell/main.c
 * @Description: 
 * 
 * Copyright (c) 2023 by qiujingbao, All Rights Reserved. 
 */

#include "defs.h"
#include "error_code.h"
// motify
// 为了更好支持多管道，参数从字符串更改为结构体

// 函数指针数组 保存可执行的命令
int (*functions[])(int) = {ls, echo, cd, pwd, date, whoami, cat, shell_chmod, shell_rmdir, shell_mkdir, rm, who, shell_kill, shell_exit, history, wc, shell_exec};

// 将参数设为全局变量
static char *function_name[] = {"ls", "echo", "cd", "pwd", "date", "whoami", "cat", "chmod", "rmdir", "mkdir", "rm", "who", "kill", "exit", "!!", "wc", "exec", "help", "!"};

/**
 * @description: 读取用户输入 根据 ‘|‘ 分割成不同指令 根据 空格 分割参数
 * @return {*} 写入全局变量 in_buf
 */
int read_command(char *in_buf)
{
    int char_count = 0;
    int ch = 0; 
    while ((ch = getchar()) != '\n' && char_count < MAX_LINE)
        in_buf[char_count++] = ch;
    if (strcmp(in_buf, "") == 0)
        return 1; // 如果没有输入则进入下一次
    return 0;
}
/**
 * @description: 初始化结构体 包括指针指向空 int初始化为0
 * @return {*} 修改全局变量 arg
 */
void reinit_arg()
{
    for (size_t i = 0; i < MAXPROCESSNUM; i++)
    {
        arg[i].file = NULL;
        arg[i].name = NULL;
        arg[i].read_from_pipe = 0;
        arg[i].write_to_pipe = 0;
        arg[i].remap_in = 0;
        arg[i].remap_in_file = NULL;
        arg[i].remap_out = 0;
        arg[i].remap_out_file = NULL;
        arg[i].opts = 0;
        for (size_t j = 0; j < MAXOPTS; j++)
        {
            arg[i].opt[j] = NULL;
        }
    }
    com_num = 0;
}
/**
 * @description: 判断参数里面是否有 & 是否为后台进程 并将&参数删除掉
 * @return {*} 修改全局变量
 */
void init_backend_process()
{
    if (arg[com_num - 1].opts == 0)
        return;
    char *last_arg = arg[com_num - 1].opt[arg[com_num - 1].opts - 1];
    if (strcmp(last_arg, "&") == 0)
    {
        is_multi = 1;
        arg[com_num - 1].opts=arg[com_num - 1].opts-1;
    }
}
/**
 * @description: 循环监听用户输入 然后执行 知道exit函数被调用
 * @return {*}
 */
int shell_loop()
{
    char in_buf[MAX_LINE] = {'\0'}; // 本次键入的命令
    while (1)
    {
        printf(GREEN "%s" GREEN "@" BLUE "%s" WHITE "$", uname, path);
        fflush(stdout); // 清空输出缓存

        if (read_command(in_buf))
            continue;

        char *save_in_buf = (char *)malloc(sizeof(char) * strlen(in_buf)); // 防止split修改 注意释放

        memcpy(save_in_buf, in_buf, strlen(in_buf));
        if (split_command(in_buf) == 0)
            continue;

        init_backend_process();

        for (int j = 0; j < com_num; j++)
        {
            // 匹配命令
            for (size_t i = 0; i < LIB_FUN_NUM; i++)
            {
                if (strcmp(arg[j].name, function_name[i]) == 0)
                {
                    // 匹配成功
                    // is_muitl_exec(arg_count);                 // 检查是否最后一个参数为&如果是则并发执行
                    add_command(&history_queen, save_in_buf); // 将当前命令加入历史队列

                    exec_function(i, j);
                    // 执行
                    break; // 结束此次for
                }
            }
        }

        free(save_in_buf); // 不是命令 不用保存 直接释放
        reinit_arg();
        is_multi = 0; // 清除flag
        memset(in_buf, '\0', MAX_LINE * sizeof(char));
    }
}

/**
 * @description: 初始化路径及用户名
 * @return {*}
 */
void init_shell()
{
    is_multi = 0;
    // 初始化当前路径
    path = getcwd(NULL, 0);
    if (!path)
        path = "";
    // 获取用户名
    uname = getenv(USER);
    if (!uname)
        uname = "";
    reinit_arg();
}
/**
 * @description: 函数入口
 * @return {*}
 */
int main(void) // 不需要这两个参数
{
    init_shell();
    shell_loop();
}
/**
 * @description: 执行函数 创建两个管道并根据情况dup2 用以完成多管道的情况
 * @param {int} i 指令所在函数指针数组的索引
 * @param {int} j 第几个命令的索引
 * @return {*}
 */
void exec_function(int i, int j)
{
    if (strcmp(function_name[i], "exit") == 0 ||strcmp(function_name[i], "cd") == 0)
    {
        functions[i](j);
        return;
    }
    // RX_FD 用于exec -> result TX_FD 用于 result -> exec
    if(pipe(RX_FD)==-1 || pipe(TX_FD)==-1)
    {
        error_printf(ERROR_BY_SYS, j);
    }

    int pid = fork();
    if (pid < 0)
    {
        error_printf(ERROR_BY_SYS, j);
    }
    else if (pid == 0) // child
    {
        // get
        if (arg[j].read_from_pipe == 1)
        {
            close(TX_FD[PIPE_WRITE]);
            dup2(TX_FD[PIPE_READ], STDIN_FILENO); // main的printf会被父进程获取
        }
        // 当前是exec进程
        // 如果是内置函数则会直接写RX——FD
        if (strcmp(function_name[i], "exec") == 0 && arg[j].write_to_pipe == 1)
        {
            close(RX_FD[PIPE_READ]);
            dup2(RX_FD[PIPE_WRITE], STDOUT_FILENO); // main的printf会被父进程获取
        }

        // 这里的函数有两种形式
        // 一种是以函数形式存在的
        // 一种是外部加载的
        functions[i](j);

        exit(1);
    }
    else // father
    {
        if (arg[j].read_from_pipe == 1)
        {
            close(TX_FD[PIPE_READ]);
            write(TX_FD[PIPE_WRITE], result_out, sizeof(char) * 1024 * 4);
            close(TX_FD[PIPE_WRITE]);
        }
        // 等待结束
        if (is_multi == 0) // 等待子进程结束
        {
            wait(NULL);
        }
        if (arg[j].write_to_pipe == 1)
        {
            close(RX_FD[PIPE_WRITE]);
            // 获取上个进程的管道输出
            result_out = (char *)malloc(sizeof(char) * 1024 * 4);
            read(RX_FD[PIPE_READ], result_out, sizeof(char) * 1024 * 4);
        }

        // exec函数只能printf 所以在这完成 remapout
        // 其余函数在内部完成remapout
        // 如果是没有重定向 没有管道 那么则在main内部完成打印
        if (arg[j].remap_out == 1 && strcmp(function_name[i], "exec"))
        {
            output(j);
        }
    }
}