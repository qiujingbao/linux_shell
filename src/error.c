/*
 * @Author: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-03-30 15:19:06
 * @LastEditors: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-04 14:37:13
 * @FilePath: /linux_shell/src/error.c
 * @Description: 
 * 
 * Copyright (c) 2023 by qiujingbao, All Rights Reserved. 
 */
#include "error_code.h"
#include "defs.h"
#include <error.h>
#include <errno.h>
void error_printf(int error_code, int index)
{
    // 清空其他输出
    delete_result();
    char *sys_error = NULL;
    char buf[1024]={'\0'};
    switch (error_code)
    {
    case PATH_ERROR:
        sprintf(buf, RED "路径错误\n" WHITE);
        break;
    case ARG_NUM_ERROR:
        /* code */
        break;
    case ARG_CONENT_ERROR:
        /* code */
        break;
    case ERROR_BY_SYS:
        sys_error = strerror(errno);
        break;
    default:
        break;
    }
    if (sys_error != NULL)
    {
        build_result(sys_error, strlen(sys_error));
        build_result("\n",strlen("\n"));
    }
    else
    {
        build_result(buf,strlen(buf));
    }
    output(index);
}