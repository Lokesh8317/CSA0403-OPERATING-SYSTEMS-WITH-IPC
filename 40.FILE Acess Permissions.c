#include <stdio.h>
#include <sys/stat.h>

int main() {
    char file_name[] = "example.txt";
    int permissions = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH;
    if (chmod(file_name, permissions) == 0) {
        printf("Permissions changed successfully\n");
    } else {
        printf("Failed to change permissions\n");
    }
    return 0;
}
#include <stdio.h>
#include <unistd.h>

int main() {
    char file_name[] = "example.txt";
    uid_t user_id = 1000;
    gid_t group_id = 100;
    if (chown(file_name, user_id, group_id) == 0) {
        printf("Ownership changed successfully\n");
    } else {
        printf("Failed to change ownership\n");
    }
    return 0;
}
