#ifndef _QUEEN_H
#define _QUEEN_H
#define MAX_QUEEN 11
// 使用队列保存历史命令 但不包含shell内置命令
struct Command_QUEEN
{
    char *data[MAX_QUEEN];
    int head, end;
};
#endif