#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;

    fd = open("out", O_CREAT | O_RDWR | O_TRUNC, 0644);
    dup2(fd, STDOUT_FILENO);
    printf("hello");
    return (0);
}