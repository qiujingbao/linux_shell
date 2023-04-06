/*
 * @Author: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-04-04 18:58:35
 * @LastEditors: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-06 17:02:33
 * @FilePath: /linux_shell/test/shell_pipe.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv)
{
    printf("shell pipe test sart !!!\n");
    char buf[1024*4];
    while (scanf("%s",buf)!=EOF)
    {
        printf("%s\n",buf);
    }
    printf("shell pipe end !!!\n");
}