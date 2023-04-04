#include "defs.h"

int init_pipe_process()
{
    arg[0].write_to_pipe=1;
    for (size_t i = 1; i < com_num; i++)
    {
        arg[i].read_from_pipe=1;
        arg[i].write_to_pipe=1;
    }
    arg[com_num-1].write_to_pipe=0;
}