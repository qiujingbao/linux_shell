#include "error_code.h"
#include "defs.h"
#include <error.h>
#include <errno.h>
void error_printf(int error_code, int index)
{
    // 清空其他输出
    delete_result();
    char *error_buf = (char *)malloc(sizeof(char) * MAX_RESULT_BUF);
    char *sys_error = NULL;
    switch (error_code)
    {
    case PATH_ERROR:
        sprintf(error_buf, RED "路径错误\n" WHITE);
        break;
    case ARG_NUM_ERROR:
        /* code */
        break;
    case ARG_CONENT_ERROR:
        /* code */
        break;
    case ERROR_BY_SYS:
        sys_error = strerror(errno);
        break;
    default:
        break;
    }
    if (sys_error != NULL)
    {
        free(error_buf);
        build_result(sys_error, strlen(sys_error));
        build_result("\n",strlen("\n"));
    }

    output(index);
}