#include "defs.h"
#include "error_code.h"
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>

void mode_to_letters(int mode, char *str)
{
    strcpy(str, "----------");
    /*
    ‘d’：目录文件；
    ‘-’：普通文件；
    ‘p’：管理文件；
    ‘l’：链接文件；
    ‘b’：块设备文件；
    ’c‘：字符设备文件；
    ‘s’：套接字文件
    S_ISLNK(st_mode)：是否是一个连接.
    S_ISREG(st_mode)：是否是一个常规文件.
    S_ISDIR(st_mode)：是否是一个目录
    S_ISCHR(st_mode)：是否是一个字符设备.
    S_ISBLK(st_mode)：是否是一个块设备
    S_ISFIFO(st_mode)：是否 是一个FIFO文件.
    S_ISSOCK(st_mode)：是否是一个SOCKET文件
    */
    if (S_ISDIR(mode))
        str[0] = 'd';
    if (S_ISCHR(mode))
        str[0] = 'c';
    if (S_ISBLK(mode))
        str[0] = 'b';
    if (S_ISFIFO(mode))
        str[0] = 'f';
    if (S_ISLNK(mode))
        str[0] = 'l';
    if (S_ISSOCK(mode))
        str[0] = 's';
    if (S_ISREG(mode))
        str[0] = '-';

    if (mode & S_IRUSR)
        str[1] = 'r';
    if (mode & S_IWUSR)
        str[2] = 'w';
    if (mode & S_IXUSR)
        str[3] = 'x';

    if (mode & S_IRGRP)
        str[4] = 'r';
    if (mode & S_IWGRP)
        str[5] = 'w';
    if (mode & S_IXGRP)
        str[6] = 'x';

    if (mode & S_IROTH)
        str[7] = 'r';
    if (mode & S_IWOTH)
        str[8] = 'w';
    if (mode & S_IXOTH)
        str[9] = 'X';
}
char *userNameFromID(uid_t uid)
{
    struct passwd *pwd;
    pwd = getpwuid(uid);
    return (pwd == NULL) ? NULL : pwd->pw_name;
}
char *groupNameFromID(gid_t gid)
{
    struct group *grp;
    grp = getgrgid(gid);
    return (grp == NULL) ? NULL : grp->gr_name;
}

char *displayStatInfo(const struct stat *sb, char *name, struct Arg_List *arg)
{
    char *t = ctime(&sb->st_mtime);
    if (t[strlen(t) - 1] == '\n')
        t[strlen(t) - 1] = '\0'; // 删除换行符
    char mode_str[10];
    mode_to_letters(sb->st_mode, mode_str);

    char *buf = (char *)malloc(sizeof(char) * MAX_RESULT_BUF);
    sprintf(buf, "%s\t%ld\t%s\t%s\t%lld\t%s\t%s\n", mode_str, (long)sb->st_nlink, userNameFromID(sb->st_uid), groupNameFromID(sb->st_gid), (long long)sb->st_size, t, name);
    return buf;

    /*printf("%s\t", mode_str);
    printf("%ld\t", (long)sb->st_nlink);
    printf("%s\t", userNameFromID(sb->st_uid));
    printf("%s\t", groupNameFromID(sb->st_gid));
    printf("%lld\t", (long long)sb->st_size);
    printf("%s\t", t);
    printf("%s\n", name);*/
    /*
        printf("File type:");
        printf("Device containing i-node: major=%ld minor-%ld\n", (long)(sb->st_dev),(long)(sb->st_dev));

        printf("I-node number:%ld  \n",(long)sb->st_ino);

        printf("Mode:%lo ()\n",(unsigned long)sb->st_mode);

        if (sb->st_mode & (S_ISUID | S_ISGID | S_ISVTX))
            printf("special bits set:%s%s%s\n",
                   (sb->st_mode & S_ISUID) ? "set - UID" : "",
                   (sb->st_mode & S_ISGID) ? "set - GID7" : "",
                   (sb->st_mode & S_ISVTX) ? "sticky" : "");

        printf(" Number of(hard) links : % ld\n ", (long)sb->st_nlink);
        printf(" Ownership: UID - %sGID - %s\n", );

        if (S_ISCHR(sb->st_mode)||S_ISBLK(sb->st_mode))
            printf("Device number (st rdev): major-%ld; minor-%ld\n", (long)(sb->st_rdev),(long)(sb->st_rdev));
        printf("File size:%lld bytes\n", (long long)sb->st_size);
        printf("Optimal I/0 block size:%ld bytes\n", (long)sb->st_blksize);
        printf("512B blocks allocated:%lld\n", (long long)sb->st_blocks);

        printf("Last file access:%s", ctime(&sb->st_atime));
        printf("Last file modification:%s", ctime(&sb->st_mtime));
        printf("Last status change:%s", ctime(&sb->st_ctime));
    */
}

int ls(int index)
{
    if (arg[index].opts > 1)
    {
        error_printf(ARG_NUM_ERROR, index);
        return -1;
    }

    DIR *dir = NULL;
    struct dirent *dp = NULL;
    if (arg[index].opts == 0)
    {
        if ((dir = opendir(path)) != NULL)
        {

            for (;;)
            {
                dp = readdir(dir);
                if (dp == NULL) // 读空
                    break;
                if (strcmp(".", dp->d_name) == 0 || strcmp("..", dp->d_name) == 0) // 跳过. ..
                    continue;
                build_result(dp->d_name, strlen(dp->d_name));
                build_result("\t", strlen("\t"));
            }
            build_result("\n", strlen("\n"));
            output(index);
        }
        else
        {
            error_printf(ERROR_BY_SYS, index);
        }
    }
    else if (strcmp(arg[index].opt[0], "-l") == 0)
    {

        if ((dir = opendir(path)) != NULL)
        {
            struct stat st;
            for (;;)
            {
                dp = readdir(dir);
                if (dp == NULL) // 读空
                    break;
                if (strcmp(".", dp->d_name) == 0 || strcmp("..", dp->d_name) == 0) // 跳过. ..
                    continue;
                char *new_path = concat(path, dp->d_name);
                if (stat(new_path, &st) == -1)
                {
                    error_printf(ERROR_BY_SYS, index);
                    return -1;
                }
                free(new_path);
                char *line = displayStatInfo(&st, dp->d_name, &arg[index]);
                build_result(line, strlen(line));
                free(line);
            }
            output(index);
        }
        else
        {
            error_printf(ARG_CONENT_ERROR, index);
            return -1;
        }
    }
}
