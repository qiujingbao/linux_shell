#include "defs.h"
#include <time.h>
#include "error_code.h"
int date(int index)
{
    time_t t;
    struct tm *p_time = NULL;

    time(&t);
    p_time = gmtime(&t);
    if (NULL != p_time)
    {
        delete_result();
        char buf[1024];
        sprintf(buf,"%04d年%02d月%02d日:%02d时%02d分%02d秒\n",(1900 + p_time->tm_year), p_time->tm_mon, p_time->tm_mday, (8 + p_time->tm_hour), p_time->tm_min, p_time->tm_sec);
        build_result(buf,strlen(buf));
        output(index);
    }
        
    else
        error_printf(ERROR_BY_SYS,index);
        
    return 0;
}