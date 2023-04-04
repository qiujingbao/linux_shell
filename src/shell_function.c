#include "defs.h"
char *get_command_index(int index)
{
    int j = 1; // to show how num
    for (int i = history_queen.head; i != history_queen.end; i = ((i + 1) % MAX_QUEEN))
    {
        if (j++ == index)
            return history_queen.data[i];
    }
    return NULL;
}

int history()
{
    int j = 1; // to show how num
    for (int i = history_queen.head; i != history_queen.end; i = ((i + 1) % MAX_QUEEN))
    {
        printf("%d:%s\n", j++, history_queen.data[i]);
    }
    return 1;
}
int shell_exit()
{
    printf("bye~\n");
    exit(0);
}

int shell_func(char *arg, struct Command_QUEEN *queen)
{
    int flag = 0;
/*
    else if (strcmp(arg, "!!") == 0) // 历史记录
    {
        flag = history(queen);
    }
    else if (strlen(arg) == 2 && arg[0] == '!') // 使用历史第n条指令
    {
        int index = arg[1] - '0';
        if (index < 1 || index > 9)
        {
            printf("数字错误！\n");
            return 1;
        }
        char *command = get_command_index(queen, index);
        if (command == NULL)
        {
            printf("输入错误！\n");
            return 1;
        }
        return 1;
    }
    */
    return flag;
}
