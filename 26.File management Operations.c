#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Error creating file\n");
        return 1;
    }

    fprintf(fp, "Hello, this is a text written to the file\n");

    fclose(fp);

    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading\n");
        return 1;
    }

    char buffer[100];
    fgets(buffer, sizeof(buffer), fp);
    printf("Read from file: %s\n", buffer);

    fclose(fp);

    if (remove("example.txt") != 0) {
        printf("Error deleting file\n");
        return 1;
    }

    return 0;
}
