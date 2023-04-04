#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv)
{
    printf("exec test sart !!!\n");
    for (size_t i = 0; i < argc; i++)
    {
        printf("%s\n",argv[i]);
    }
    printf("exec test end !!!\n");
    
}