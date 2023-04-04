#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char** argv)
{
    printf("backend test sart !!!\n");
    sleep(10);
    for (size_t i = 0; i < argc; i++)
    {
        printf("%s\n",argv[i]);
    }
    printf("backend test end !!!\n");
    
}