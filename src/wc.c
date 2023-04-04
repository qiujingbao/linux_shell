#include "defs.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "error_code.h"
struct message {

int lines;

int words;

int max_line_length;

int size;

int chars;
}info;

void init(char filename[],int index)
{

    struct stat get_message = {};

    FILE *fp;

    int ret_stat = stat(filename, &get_message); /*用stat函数读取filenmae文件的信息，并将结果写到get_message结构体中*/

    if (ret_stat == -1)
    { 
        error_printf(ARG_CONENT_ERROR,index);
        return;
    }

    mode_t mode = get_message.st_mode; // 接收文件信息，用于下面判断是不是目录

    int length = 0;

    if (S_ISDIR(mode)) // 如果是目录，输出错误

        error_printf(ARG_CONENT_ERROR,index);

    else
    {

        info.size = get_message.st_size; // 文件字节大小 wc -c

        fp = fopen(filename, "r"); // 以只读方式打开指定文件

        char ch;

        int flag = 0;

        while ((ch = fgetc(fp)) != EOF)
        { // 一直读到文件尾

            info.chars++; // 字符数加1 wc -m

            if (ch != '\n')
            {

                length++; // 记录当前行的长度 wc -L
            }

            if (ch == '\n')
            {

                info.lines++; // 行数加1 wc -l

                if (length > info.max_line_length)

                    info.max_line_length = length; // 更新最大长度

                length = 0;
            }

            if (ch == '\t' || ch == ' ' || ch == '\n')
            {

                flag = 0; // 计算单词数 wc -w

                continue;
            }

            else
            {

                if (flag == 0)
                {

                    info.words++; // 计算单词数 wc -w

                    flag = 1;
                }
            }
        }

        fclose(fp);
    }
}
void EmptyFile()
{

    char ch;

    int flag = 0;

    int length = 0;

    while ((ch = getchar()) != EOF)
    {

        info.chars++;

        info.size += sizeof(ch); // 字节累加

        if (ch != '\n')
        {

            length++;
        }

        if (ch == '\n')
        {

            info.lines++;

            if (length > info.max_line_length)

                info.max_line_length = length;

            length = 0;
        }

        if (ch == '\t' || ch == ' ' || ch == '\n')
        {

            flag = 0;

            continue;
        }

        else
        {

            if (flag == 0)
            {

                info.words++;

                flag = 1;
            }
        }
    }
}

int wc(int index)
{

    if (arg[index].opts == 2)
    {

        if (arg[index].opt[0] != '-')
        {

            init(arg[index].opt[0]);

            printf("%d %d %d %s\n", info.lines, info.words, info.size, args[1]);

            return 0;
        }

        else
        { // 未指定打开文件，类似 wc -lmwcL

            EmptyFile();
        }
    }

    else if (*arg_count == 1)
    { // 未指定打开文件和要输出的参数，(默认输出 -lwc)

        EmptyFile();

        printf("%d\t%d\t%d\n", info.lines, info.words, info.size);

        return 0;
    }

    else if (*arg_count == 3)
    {

        init(args[2]);
    }

    int num;

    while ((num = getopt(*arg_count, args, "lwmcL")) != -1)
    {

        switch (num)
        {

        case 'l':

            printf("%d\t", info.lines);

            break;

        case 'w':

            printf("%d\t", info.words);

            break;

        case 'm':

            printf("%d\t", info.chars);

            break;

        case 'c':

            printf("%d\t", info.size);

            break;

        case 'L':

            printf("%d\t", info.max_line_length);

            break;
        }
    }

    if (*arg_count != 2 && args[1][0] != '-') // 一定要判断，否则会越界

        printf("%s\n", args[2]);

    return 0;
}