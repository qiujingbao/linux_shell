#include "defs.h"
#include <stdio.h>
#include <utmp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
// 显示信息
char *show_info(struct utmp *utbufp)
{
    char *buf = (char *)malloc(sizeof(char) * 1024);
    sprintf(buf, "%-8.8s\t%-8.8s\t%10d\t%s\t\n", utbufp->ut_name, utbufp->ut_line, utbufp->ut_time, utbufp->ut_host);
    return buf;
}
int who(int index)
{
    struct utmp current_record;
    int utmpfd;
    int reclen = sizeof(current_record);

    if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1)
    {
        perror(UTMP_FILE);
        exit(1);
    }
    delete_result();
    while (read(utmpfd, &current_record, reclen) == reclen)
    {
        char *line = show_info(&current_record);
        build_result(line, strlen(line));
        free(line);
    }
    output(0);
    close(utmpfd);

    return 0;
}