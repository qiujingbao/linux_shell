#include "defs.h"
int echo(int index)
{
    delete_result();
    for (size_t i = 0; i < arg[index].opts; i++)
    {
        build_result(arg[index].opt[i], strlen(arg[index].opt[i]));
        build_result(" ", strlen(" "));
    }
    output(index);
}