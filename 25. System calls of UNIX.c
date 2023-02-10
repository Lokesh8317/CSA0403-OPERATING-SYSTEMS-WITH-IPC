#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>

int main()
{
    int fd;
    struct stat file_stat;
    DIR *dir;
    struct dirent *entry;

    fd = open("file.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Open failed");
        return 1;
    }

    if (fstat(fd, &file_stat) == -1)
    {
        perror("fstat failed");
        return 1;
    }

    printf("File size: %ld\n", file_stat.st_size);

    if (lseek(fd, 10, SEEK_SET) == -1)
    {
        perror("lseek failed");
        return 1;
    }

    dir = opendir(".");
    if (!dir)
    {
        perror("opendir failed");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    close(fd);
    return 0;
}

