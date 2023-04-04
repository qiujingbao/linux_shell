/*
 * @Author: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-03-30 13:43:19
 * @LastEditors: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-04 14:45:27
 * @FilePath: /linux_shell/src/cd.c
 * @Description: cd命令 原理为改变path这个全局变量
 *      cd 支持全路径 支持 .. 
 * Copyright (c) 2023 by qiujingbao, All Rights Reserved. 
 */

#include "defs.h"
#include "error_code.h"
int cd(int index)
{
    if(arg[index].opts!=1)
    {
        error_printf(ARG_NUM_ERROR,index);
    }
    if (chdir(arg[index].opt[0]) == 0)
    {
        path=getcwd(NULL,0);
        return 0;
    }
    error_printf(PATH_ERROR,index);
    return -1;
}