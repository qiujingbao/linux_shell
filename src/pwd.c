#include "defs.h"
int pwd(int index)
{
    path=getcwd(NULL,0);
    delete_result();
    build_result(path,strlen(path));
    output(index);
}