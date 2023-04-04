#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv)
{
    printf("shell pipe test sart !!!\n");
    sleep(10);
    char buf[1024*4];
    while (scanf("%s",buf)!=EOF)
    {
        printf("%s\n",buf);
    }
    
    
    printf("shell pipe end !!!\n");
    
}