#include "defs.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include "error_code.h"
struct TextStatistics
{
    int lines;           // 行数
    int words;           // 单词数
    int max_line_length; // 最长的一个单词的长度
    int size;            // 大小
    int chars;           // 字符数
};
struct TextStatistics info;
int file2sattictics(char *path, int index)
{
    struct stat st;
    if (stat(path, &st) == -1)
    {
        error_printf(PATH_ERROR, index);
        return -1;
    }
    int length = 0;

    if (S_ISDIR(st.st_mode)) // 如果是目录，输出错误
    {
        error_printf(PATH_ERROR, index);
        return -1;
    }
    else
    {

        info.size = st.st_size; // 文件字节大小 wc -c
        int fd;
        if ((fd = open(path, O_RDONLY)) == -1)
        {
            error_printf(PATH_ERROR, index);
            return -1;
        }
        char buf;

        int flag = 0;

        while (read(fd, &buf, 1) != 0)
        {
            info.chars++; // 字符数加1 wc -m
            if (buf != '\n')
            {
                length++; // 记录当前行的长度 wc -L
            }
            if (buf == '\n')
            {
                info.lines++; // 行数加1 wc -l
                if (length > info.max_line_length)
                    info.max_line_length = length; // 更新最大长度
                length = 0;
            }
            if (buf == '\t' || buf == ' ' || buf == '\n')
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
            if (info.words == 1 && length > info.max_line_length)
                info.max_line_length = length;
        }
        close(fd);
    }
}
int stream2sattictics(char *stream, int index)
{
    char buf;
    int flag = 0;
    int stream_point = 0;
    int length = 0;
    while (stream[stream_point] != '\0')
    {
        buf = stream[stream_point++];
        info.chars++; // 字符数加1 wc -m
        if (buf != '\n')
        {
            length++; // 记录当前行的长度 wc -L
        }
        if (buf == '\n')
        {
            info.lines++; // 行数加1 wc -l
            if (length > info.max_line_length)
                info.max_line_length = length; // 更新最大长度
            length = 0;
        }
        if (buf == '\t' || buf == ' ' || buf == '\n')
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
        if (info.words == 1 && length > info.max_line_length)
            info.max_line_length = length;
    }
}

void show(char *in_arg, int index)
{
    if (in_arg[0] != '-')
    {
        return;
    }
    char buf;
    int i = 1;
    delete_result();
    while (in_arg[i] != '\0')
    {
        buf = in_arg[i];
        char res[100] = {'\0'};
        switch (buf)
        {
        case 'w':
            sprintf(res, "words: %d", info.words);
            break;
        case 'c':
            sprintf(res, "bytes: %d", info.size);
            break;
        case 'l':
            sprintf(res, "lines: %d", info.lines);
            /* code */
            break;
        case 'm':
            sprintf(res, "chars: %d", info.chars);
            /* code */
            break;
        case 'L':
            sprintf(res, "max word size: %d", info.max_line_length);
            break;
        default:
            delete_result();
            return;
        }
        build_result(res, strlen(res));
        build_result("\t", strlen("\t"));

        i++;
    }
    build_result("\n", strlen("\n"));

    output(index);
}
int wc(int index)
{

    if (arg[index].opts == 2) // 参数和文件名
    {
        file2sattictics(arg[index].opt[1], index);
        show(arg[index].opt[0], index);
    }
    else if (arg[index].opts == 1 && arg[index].read_from_pipe == 1) // 参数 pipe
    {
        close(TX_FD[PIPE_WRITE]);
        char buf[1024 * 4] = {'\0'};
        read(TX_FD[PIPE_READ], buf, 1024 * 4);
        info.size=strlen(buf);
        stream2sattictics(buf, index);
        show(arg[index].opt[0], index);
    }

    /*

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

    return 0;*/
}