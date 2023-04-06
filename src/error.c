/*
 * @Author: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-04-04 18:58:35
 * @LastEditors: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-06 17:13:49
 * @FilePath: /linux_shell/src/error.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-03-30 15:19:06
 * @LastEditors: qiujingbao “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-06 15:18:06
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
        sprintf(buf, RED "参数数量错误\n" WHITE);
        break;
    case ARG_CONENT_ERROR:
        sprintf(buf, RED "参数内容错误\n" WHITE);
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