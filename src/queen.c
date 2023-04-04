#include "defs.h"

void init_queen(struct Command_QUEEN *queen)
{
    queen->end = 0;
    queen->head = 0;
}
// 判断队列是否满
int isFull(struct Command_QUEEN *queen)
{
    return (queen->end + 1) % MAX_QUEEN == queen->head;
}

// 判断队列是否为空
int isEmpty(struct Command_QUEEN *queen)
{
    return queen->end == queen->head;
}

// 添加数据到队列

void addQueue(struct Command_QUEEN *queen,char *p)
{
    // 判断队列是否满
    if (isFull(queen))
    {
        return;
    }
    queen->data[queen->end] = p;
    // 将rear后移，必须考虑取模
    queen->end = (queen->end + 1) % MAX_QUEEN;
}

// 出队列
int getQueue(struct Command_QUEEN *queen)
{
    // 判断队列是否空
    if (isEmpty(queen))
    {
        return -1;
    }
    // 因为修改了保存方式使用了malloc 那么需要在移除队列的时候free

    free(queen->data[queen->head]);

    queen->head = (queen->head + 1) % MAX_QUEEN;
    return 0;
}

int add_command(struct Command_QUEEN *queen,char *p)
{
    if (isFull(queen))
    {
        getQueue(queen);
    }
    char *tem = (char *)malloc(sizeof(char) * strlen(p));
    strcpy(tem, p);
    addQueue(queen,tem);
    return 1;
}
char *get_command(struct Command_QUEEN *queen,int index)
{
    return queen->data[(queen->head + index) % MAX_QUEEN];
}