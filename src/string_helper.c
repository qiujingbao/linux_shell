/*
 * @Author: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-04-01 12:11:15
 * @LastEditors: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-04 13:21:03
 * @FilePath: /linux_shell/src/string_helper.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "defs.h"
char *concat(char *spath, char *filename)
{
    char *new_path = (char *)malloc(MAX_PATH);
    strcpy(new_path, spath);
    strcat(new_path, "/");
    strcat(new_path, filename);
    return new_path;
}
// 将dstcopy到source后边
//-1 on failue num on success
//  追加字符串, 但在使用时要注意src与des的关系
int append(char *src, char *des, int src_len, int des_len)
{
    int count = des_len;
    char *ps = src;
    char *pd = des;
    while (count > 0)
    {

        count--;
        *((ps++) + src_len) = *pd++;
    }
    return src_len + des_len;
}
void delete_result()
{
    free(result_out);
    result_out=NULL;
    result_out_count=0;
}
void build_result(char *res, int len)
{
    if (result_out != NULL)
    {
        result_out_count = append(result_out, res, result_out_count, len);
        return;
    }
    else
    {
        result_out=(char *)malloc(sizeof(char)*MAX_RESULT_BUF);
        memset(result_out,'\0',sizeof(char)*MAX_RESULT_BUF);
        result_out_count=0;
        build_result(res,len);
        return;
    }
}

// 分割字符串 放入全局变量
int split_command(char *in_buf)
{
    // 根据 | 分割不同命令
    char *tem_args[MAXPROCESSNUM];
    for (tem_args[com_num] = strtok(in_buf, "|"); tem_args[com_num] != NULL; tem_args[com_num] = strtok(NULL, "|"))
        com_num++;

    // 处理每一条命令
    for (size_t i = 0; i < com_num; i++)
    {
        int opt_count = 0;
        char *tem;
        // 获取每个参数

        // 获取命令名称
        // 不用重新赋值 inbuf没有free
        tem = strtok(tem_args[i], " ");
        arg[i].name = tem;
        tem = strtok(NULL, " ");
        for (; tem != NULL; tem = strtok(NULL, " "))
        {
            if (strcmp(">", tem) == 0)
            {
                arg[i].remap_out = 1;
                tem = strtok(NULL, " ");
                arg[i].remap_out_file = tem;
                continue;
            }
            if (strcmp("<", tem) == 0)
            {
                arg[i].remap_in = 1;
                tem = strtok(NULL, " ");
                arg[i].remap_in_file = tem;
                continue;
            }
            arg[i].opt[arg[i].opts++] = tem;
        }
    }
    
    if(com_num==0)return 0;
    init_pipe_process();
    return 1;

}