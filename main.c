#include "defs.h"
#include "error_code.h"
// motify
// 为了更好支持多管道，参数从字符串更改为结构体

// 函数指针数组 保存可执行的命令
int (*functions[])(int) = {ls, echo, cd, pwd, date, whoami, cat, shell_chmod, shell_rmdir, shell_mkdir, rm, who, shell_kill, shell_exit, history, wc, shell_exec};

// 将参数设为全局变量
static char *function_name[] = {"ls", "echo", "cd", "pwd", "date", "whoami", "cat", "chmod", "rmdir", "mkdir", "rm", "who", "kill", "exit", "!!", "wc", "exec", "help", "!"};

// 读取一行输入 用户按下回车为止
int read_command(char *in_buf)
{
    int char_count = 0;
    int ch = 0; // 临时字符
                // 读取字符 直到换行 如果使用scanf读取 那么读到空格会停止 \n检测不出来
                // 采用getchar读取所有字符直到\n停止 然后strtok分割

    while ((ch = getchar()) != '\n' && char_count < MAX_LINE)
        in_buf[char_count++] = ch;
    if (strcmp(in_buf, "") == 0)
        return 1; // 如果没有输入则进入下一次
    return 0;
}
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
void init_backend_process()
{
    if (arg[com_num - 1].opts == 0)
        return;
    char *last_arg = arg[com_num - 1].opt[arg[com_num - 1].opts - 1];
    if (strcmp(last_arg, "&") == 0)
        is_multi = 1;
}

int shell_loop()
{
    while (1)
    {
        printf(GREEN "%s" GREEN "@" BLUE "%s" WHITE "$", uname, path);
        fflush(stdout); // 清空输出缓存

        char in_buf[MAX_LINE] = {'\0'}; // 本次键入的命令

        if (read_command(in_buf))
            continue;

        char *save_in_buf = (char *)malloc(sizeof(char) * strlen(in_buf)); // 防止split修改 注意释放

        memcpy(save_in_buf, in_buf, strlen(in_buf));
        if (split_command(in_buf) == 0)
            continue;
        if (com_num > 1)
        {
            init_pipe_process();
        }

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
    }
}
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
int main(void) // 不需要这两个参数
{
    init_shell();
    shell_loop();
}

int exec_function(int i, int j)
{
    pipe(fd);
    int pid = fork();
    if (pid < 0)
    {
        error_printf(ERROR_BY_SYS, j);
    }
    else if (pid == 0) // child
    {
        if (arg[j].write_to_pipe == 1)
        {
            close(fd[PIPE_READ]);
            dup2(fd[PIPE_WRITE], STDOUT_FILENO); // 输出重定向到 下一个进程
        }
        

        functions[i](j);
        exit(1);
    }
    else // father
    {
        close(fd[PIPE_WRITE]);
        // 等待结束
        if (is_multi == 0) // 等待子进程结束
        {
            wait(NULL);
        }
 char *buf = (char *)malloc(sizeof(char) * 1024 * 4);
            memset(buf, '\0', 1024 * 4);
            read(fd[PIPE_READ], buf, sizeof(char) * 1024 * 4);
        // 如果有下一条命令那么 给下一条命令
        if (j + 1 < MAXPROCESSNUM && arg[j + 1].read_from_pipe == 1)
        {
           
            arg[j + 1].opt[arg[j + 1].opts++] = buf;
        }
        else if(arg[j].remap_out==1) //输出重定向
        {
            delete_result();
            build_result(buf,strlen(buf));
            output(j);
        }
        free(buf);
    }
}