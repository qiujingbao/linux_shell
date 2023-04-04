/*
 * @Author: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @Date: 2023-03-30 13:43:32
 * @LastEditors: “qiujingbao” “qiujingbao@dlmu.edu.cn”
 * @LastEditTime: 2023-04-04 14:46:59
 * @FilePath: /linux_shell/src/pwd.c
 * @Description: 输出当前路径
 * 
 * Copyright (c) 2023 by qiujingbao, All Rights Reserved. 
 */
#include "defs.h"
int pwd(int index)
{
    path=getcwd(NULL,0);
    delete_result();
    build_result(path,strlen(path));
    build_result("\n",strlen("\n"));
    
    

    output(index);
}