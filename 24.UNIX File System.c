#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    int fd = creat("example.txt", 0644);
    if (fd == -1) {
        printf("Error creating file\n");
        return 1;
    }
    char* text = "Hello, this is a text written to the file\n";
    write(fd, text, sizeof(text));
    close(fd);
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        printf("Error opening file for reading\n");
        return 1;
    }
    char buffer[100];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        printf("Error reading from file\n");
        return 1;
    }
    printf("Read from file: %s\n", buffer);
    close(fd);
    if (remove("example.txt") != 0) {
        printf("Error deleting file\n");
        return 1;
    }
    return 0;
}
