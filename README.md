### 子功能

#### ls命令

支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$ls
backend DartConfiguration.tcl   CPackConfig.cmake       Testing 
...
ubuntu@/home/ubuntu/linux_shell/build$ls -l
-rwxrwxr-X      1       ubuntu  ubuntu  16744   Tue Apr  4 18:58:35 2023        backend
....
ubuntu@/home/ubuntu/linux_shell/build$
```

​	获取当前环境路径，然后使用`opendir`获取当前文件夹，然后通过`readdir`获取文件名，如果不带参数直接输出，注意忽略`.`，`..`路径。如果带参数，则通过`stat`函数获取文件信息。最后调用`output()`打印。

#### cd命令

支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$cd /home
ubuntu@/home$cd ..
ubuntu@/$cd /home/ubuntu
ubuntu@/home/ubuntu$cd linux_shell
ubuntu@/home/ubuntu/linux_shell$
```

​	仅支持全路径，不支持`~`。使用`chdir()`函数修改当前环境，并更新全局变量`path`。

#### cat命令

支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$cat a.out
/home/ubuntu/linux_shell/build-rwxrwxr-X        1       ubuntu  ubuntu  16744   Tue Apr  4 18:58:35 2023        backend
...
ubuntu@/home/ubuntu/linux_shell/build$
```

​	通过`open()`获取文件描述符，然后通过`read()`读取文件循环构造输出，当`read()`返回为0时终止循环。

#### chmod命令

​	支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$ls -l
-rwx------      1       ubuntu  ubuntu  1285    Tue Apr  4 21:05:22 2023        a.out
ubuntu@/home/ubuntu/linux_shell/build$chmod 777 a.out
ubuntu@/home/ubuntu/linux_shell/build$ls -l
-rwxrwxrwX      1       ubuntu  ubuntu  1285    Tue Apr  4 21:05:22 2023        a.out
ubuntu@/home/ubuntu/linux_shell/build$
```

​	读取文件信息通过`stat()`函数，然后构造掩码通过7=1+2+4，三位数字共9位二进制。然后通过`chmod()`更改权限。

#### date命令

​	支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$date
2023年03月06日:16时28分25秒
```

​	通过`gmtime()`获取当前时间并输出。

#### echo命令

​	支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$echo aaa
aaa ubuntu@/home/ubuntu/linux_shell/build$eho lll
ubuntu@/home/ubuntu/linux_shell/build$
```

​	获取参数并输出。

#### pwd命令

​	支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$pwd
/home/ubuntu/linux_shell/build
```

​	获取`path`全局变量并输出。

#### rm命令

​	支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$ls
backend DartConfiguration.tcl   CPackConfig.cmake       Testing CPackSourceConfig.cmake exec_test       Makefile        cmake_install.cmake     CMakeCache.txt    a.out   linux_shell     pipe.txt        CTestTestfile.cmake     .cmake  compile_commands.json   CMakeFiles      shell_pipe
ubuntu@/home/ubuntu/linux_shell/build$rm a.out
ubuntu@/home/ubuntu/linux_shell/build$ls
backend DartConfiguration.tcl   CPackConfig.cmake       Testing CPackSourceConfig.cmake exec_test       Makefile        cmake_install.cmake     CMakeCache.txt    linux_shell     pipe.txt        CTestTestfile.cmake     .cmake  compile_commands.json   CMakeFiles      shell_pipe
ubuntu@/home/ubuntu/linux_shell/build$
```

#### mkdir命令

​	支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$ls
backend DartConfiguration.tcl   CPackConfig.cmake       Testing CPackSourceConfig.cmake exec_test       Makefile        cmake_install.cmake     CMakeCache.txt    linux_shell     pipe.txt        CTestTestfile.cmake     .cmake  compile_commands.json   CMakeFiles      shell_pipe
ubuntu@/home/ubuntu/linux_shell/build$mkdir new_dir
ubuntu@/home/ubuntu/linux_shell/build$ls
new_dir backend DartConfiguration.tcl   CPackConfig.cmake       Testing CPackSourceConfig.cmake exec_test       Makefile        cmake_install.cmake       CMakeCache.txt  linux_shell     pipe.txt        CTestTestfile.cmake     .cmake  compile_commands.json   CMakeFiles      shell_pipe
ubuntu@/home/ubuntu/linux_shell/build$
```

#### rmdir命令

​	支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$ls
new_dir backend DartConfiguration.tcl   CPackConfig.cmake       Testing CPackSourceConfig.cmake exec_test       Makefile        cmake_install.cmake       CMakeCache.txt  linux_shell     pipe.txt        CTestTestfile.cmake     .cmake  compile_commands.json   CMakeFiles      shell_pipe
ubuntu@/home/ubuntu/linux_shell/build$rmdir new_dir
ubuntu@/home/ubuntu/linux_shell/build$ls
backend DartConfiguration.tcl   CPackConfig.cmake       Testing CPackSourceConfig.cmake exec_test       Makefile        cmake_install.cmake     CMakeCache.txt    linux_shell     pipe.txt        CTestTestfile.cmake     .cmake  compile_commands.json   CMakeFiles      shell_pipe
ubuntu@/home/ubuntu/linux_shell/build$
```

#### who命令

​	支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$who
reboot          ~               1679408500      5.4.0-126-generic
runlevel        ~               1679408509      5.4.0-126-generic
LOGIN           ttyS0           1679408510
LOGIN           tty1            1679408510
                pts/5           1679720792
ubuntu@/home/ubuntu/linux_shell/build$
```

#### whoami命令

​	支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$whoami
ubuntu
ubuntu@/home/ubuntu/linux_shell/build$
```

#### wc命令

​	支持如下形式

```shell
ubuntu@/home/ubuntu/linux_shell/build$wc -lwc a.out
lines: 16       words: 176      bytes: 1142
ubuntu@/home/ubuntu/linux_shell/build$
```

参数为 l：行数 w：词数 c：大小 L：最大单词长度的组合。

### 高级功能使用

### 重定向输入输出

```shell
ubuntu@/home/ubuntu/linux_shell/build$rm a.out
ubuntu@/home/ubuntu/linux_shell/build$ls -l > a.out
ubuntu@/home/ubuntu/linux_shell/build$cat a.out
-rwxrwxr-X      1       ubuntu  ubuntu  16744   Tue Apr  4 18:58:35 2023        backend
...
ubuntu@/home/ubuntu/linux_shell/build$
```

#### 多管道命令

两个内部命令

```shell
ubuntu@VM-8-10-ubuntu:~/linux_shell/build$ ls | cat
a.out
backend
CMakeCache.txt
CMakeFiles
cmake_install.cmake
compile_commands.json
CPackConfig.cmake
CPackSourceConfig.cmake
CTestTestfile.cmake
DartConfiguration.tcl
exec_test
linux_shell
Makefile
pipe.txt
shell_pipe
Testing
ubuntu@VM-8-10-ubuntu:~/linux_shell/build$ 
ubuntu@/home/ubuntu/linux_shell/build$ls | cat
backend DartConfiguration.tcl   CPackConfig.cmake       Testing CPackSourceConfig.cmake exec_test   Makefile        cmake_install.cmake     CMakeCache.txt  a.out   linux_shell     pipe.txt    CTestTestfile.cmake     .cmake  compile_commands.json   CMakeFiles      shell_pipe
ubuntu@/home/ubuntu/linux_shell/build$
```

三个内部命令

```
ubuntu@VM-8-10-ubuntu:~/linux_shell/build$ ls | date | cat
Thu 06 Apr 2023 04:55:04 PM CST
ubuntu@VM-8-10-ubuntu:~/linux_shell/build$ 
ubuntu@/home/ubuntu/linux_shell/build$ls | date | cat
2023年03月06日:16时54分46秒
ubuntu@/home/ubuntu/linux_shell/build$
```

单用户程序

```c
shell_pipe.c
int main(int argc,char** argv)
{
    printf("shell pipe test sart !!!\n");
    char buf[1024*4];
    while (scanf("%s",buf)!=EOF)
    {
        printf("%s\n",buf);
    }
    printf("shell pipe end !!!\n");
}
exec_test.C
int main(int argc,char** argv)
{
    printf("exec test sart !!!\n");
    for (size_t i = 0; i < argc; i++)
    {
        printf("%s\n",argv[i]);
    }
    printf("exec test end !!!\n");
}
```

```shell
ubuntu@/home/ubuntu/linux_shell/build$ls -l | exec shell_pipe
shell pipe test sart !!!
-rwxrwxr-X
1
ubuntu
...
shell pipe end !!!
ubuntu@/home/ubuntu/linux_shell/build$

ubuntu@VM-8-10-ubuntu:~/linux_shell/build$ ls -l | ./shell_pipe 
shell pipe test sart !!!
total
264
-rwxrwxr-x
1
ubuntu
...
shell pipe end !!!
ubuntu@VM-8-10-ubuntu:~/linux_shell/build$ 
```

多用户程序

```shell
ubuntu@/home/ubuntu/linux_shell/build$exec exec_test | exec shell_pipe
shell pipe test sart !!!
exec
test
sart
!!!
exec
test
end
!!!

shell pipe end !!!
ubuntu@/home/ubuntu/linux_shell/build$
ubuntu@VM-8-10-ubuntu:~/linux_shell/build$ ./exec_test | ./shell_pipe 
shell pipe test sart !!!
exec
test
sart
!!!
./exec_test
exec
test
end
!!!
shell pipe end !!!
ubuntu@VM-8-10-ubuntu:~/linux_shell/build$ 
```

#### 后台运行命令

```shell
ubuntu@/home/ubuntu/linux_shell/build$exec backend | ls
backend DartConfiguration.tcl   CPackConfig.cmake       Testing CPackSourceConfig.cmake exec_test   Makefile        cmake_install.cmake     CMakeCache.txt  a.out   linux_shell     pipe.txt    CTestTestfile.cmake     .cmake  compile_commands.json   CMakeFiles      shell_pipe
ubuntu@/home/ubuntu/linux_shell/build$exec backedn | ls &
ubuntu@/home/ubuntu/linux_shell/build$backend   DartConfiguration.tcl   CPackConfig.cmake  Testing  CPackSourceConfig.cmake exec_test       Makefile        cmake_install.cmake     CMakeCache.txt      a.out   linux_shell     pipe.txt        CTestTestfile.cmake     .cmake  compile_commands.json       CMakeFiles      shell_pipe
ubuntu@/home/ubuntu/linux_shell/build$
ubuntu@VM-8-10-ubuntu:~/linux_shell/build$ ./backend | ls &
[2] 1632916
a.out           cmake_install.cmake      CTestTestfile.cmake    Makefile
backend         compile_commands.json    DartConfiguration.tcl  pipe.txt
CMakeCache.txt  CPackConfig.cmake        exec_test              shell_pipe
CMakeFiles      CPackSourceConfig.cmake  linux_shell            Testing
ubuntu@VM-8-10-ubuntu:~/linux_shell/build$ ./
[2]-  Done                    ./backend | ls --color=auto
bash: ./: Is a directory
```