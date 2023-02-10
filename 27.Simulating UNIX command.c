#include <stdio.h>
#include <dirent.h>

int main() {
    DIR* dir = opendir("."); 

    if (dir == NULL) {
        printf("Error opening directory\n");
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name); 
    }

    closedir(dir); 
    return 0;
}
