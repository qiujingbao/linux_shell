#include "defs.h"
#include <unistd.h>
#include <fcntl.h>
#include "error_code.h"
int cat(int index)
{
    if (arg[index].opts!=1)
        return 0;
    int fd;
    delete_result();
    if ((fd = open(arg[index].opt[0] ,O_RDONLY)) != -1) //read only
    {
        int num=0;
        char buf[1024];
        while ((num=read(fd,buf,sizeof(char)*1024))!=0)
        {
            build_result(buf,num);
            memset(buf,'\0',sizeof(char)*1024);
        }
        build_result("\n",strlen("\n"));
        output(index);
    }
    else
    {
        error_printf(ERROR_BY_SYS,0);
        return -1;
    }
    return 0;
}