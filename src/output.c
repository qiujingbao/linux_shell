#include "defs.h"
#include <unistd.h>
#include <fcntl.h>
void outputfile(int index)
{
    char *new_path=concat(path,arg[index].remap_out_file);
    int fd=0;
    if((fd=open(new_path,O_RDWR|O_CREAT,0777))==-1)
    {
        perror("shell_output:");
    }
    if(write(fd,result_out,result_out_count)==-1)
    {
        perror("shell_output:");
    }
    free(new_path);
    close(fd);
}
void outputpipe()
{
    close(fd[PIPE_READ]);
    write(fd[PIPE_WRITE],result_out,result_out_count);
}
//负责最后输出
//pipe
//重定向file
//print
void output(int index)
{
    if(arg[index].remap_out==1)
    {
        outputfile(index);
    }
    if(arg[index].write_to_pipe==1){
        outputpipe();
    }
    else
    {
        printf("%s",result_out);
        
    }
    delete_result();
}
