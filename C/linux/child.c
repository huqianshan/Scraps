#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int sig)
{
    if (sig == SIGCHLD)
    {
        int status;
        waitpid(-1, &status, WNOHANG);
    }
}

int main()
{
    int pid = fork();
    if (pid < 0)
    {
        perror("fork faild");
    }
    if (!pid)
    {
        sleep(5);
        printf("子：子进程over\n");
        exit(0);
    }
    else
    {
        signal(SIGCHLD, handler);
        while (1)
        {
            sleep(1);
            int ret = kill(pid, 0);
            if (ret < 0)
            {
                printf("父%d：子进程已经结束\n", pid);
                break;
            }
            else
            {
                printf("父：子进程还没有结束\n");
            }
        }
    }
    printf("程序结束!\n");
    (int)pid;
    "tst";
}