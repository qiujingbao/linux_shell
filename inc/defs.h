#ifndef _DEFS_H
#define _DEFS_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "queen.h"
//条件宏
#define MAX_LINE 80
#define MAX_CHAR 10
#define MAXPROCESSNUM 4
#define MAXOPTS 3
#define MAX_RESULT_BUF 1024 * 100
#define MAX_PATH 1024
#define PIPE_READ 0
#define PIPE_WRITE 1
#define USER "USER"
#define LIB_FUN_NUM 17
//颜色宏
#define COL(x) "\033[;" #x "m"
#define RED COL(31)
#define GREEN COL(32)
#define YELLOW COL(33)
#define BLUE COL(34)
#define MAGENTA COL(35)
#define CYAN COL(36)
#define WHITE COL(0)

/// @brief 用以保存每个命令的结构体
struct Arg_List
{
    char *name; // 命令名称

    char *file; //

    int read_from_pipe;

    int write_to_pipe;

    int remap_in;

    char *remap_in_file;

    int remap_out;

    char *remap_out_file;

    int opts;

    char *opt[MAXOPTS];
};

/// @brief 全局变量
char *result_out;
int result_out_count;
int com_num;
int is_multi; // 是否并发执行
char *args[MAX_LINE / 2 + 1];
char *path;
int *arg_count;
char *uname;
struct Command_QUEEN history_queen;
struct Arg_List arg[MAXPROCESSNUM];
int TX_FD[2];
int RX_FD[2];

// queen.c
void init_queen(struct Command_QUEEN *queen);
int isFull(struct Command_QUEEN *queen);
int isEmpty(struct Command_QUEEN *queen);
void addQueue(struct Command_QUEEN *queen, char *p);
int getQueue(struct Command_QUEEN *queen);
int add_command(struct Command_QUEEN *queen, char *p);
char *get_command(struct Command_QUEEN *queen, int index);

// shell_function.c
char *get_command_index(int index);
int history();
int shell_exit();
int shell_func(char *arg, struct Command_QUEEN *queen);

// exec.c
void exec_command(int is_multi, void *func, char *args);

// error print
void error_printf(int error_code, int index);

// functions define
int ls(int index);
int echo(int index);
int cat(int index);
int shell_mkdir(int index);
int shell_rmdir(int index);
int rm(int index);
int cd(int index);
int shell_chmod(int index);
int pwd(int index);
int wc(int index);
int date(int index);
int shell_kill(int index);
int who(int index);
int wc(int index);
int whoami(int index);
int shell_exec(int index);

void exec_function(int i, int j);
int init_pipe_process();
void output(int index);
//
char *concat(char *spath, char *filename);
int append(char *src, char *des, int src_len, int des_len);
void build_result(char *res, int len);
void delete_result();
int split_command(char *in_buf);

#endif