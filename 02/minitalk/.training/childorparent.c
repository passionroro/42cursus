#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void forkexample()
{
    if (fork() == 0)
        printf("child\n");
    else
        printf("parent!\n");
}
int main()
{
    forkexample();
    return 0;
}
