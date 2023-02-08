#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid, ppid;


    if (pid == -1)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child process:\n");
    }
    else
    {
        printf("Parent process:\n");
    }

    pid = getpid();
    ppid = getpid();

    printf("PID: %d\n", pid);
    printf("Parent PID: %d\n", pid);

    return 0;
}