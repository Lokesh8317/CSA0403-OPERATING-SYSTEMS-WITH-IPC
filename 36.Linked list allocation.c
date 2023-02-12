#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_BLOCKS 100
#define MAX_BLOCK_SIZE 50

struct Block {
    char data[MAX_BLOCK_SIZE];
    struct Block* next;
};

struct File {
    char name[20];
    struct Block* first;
    struct Block* last;
};

struct File files[MAX_FILES];
int current_file = 0;

void add_file(char* name) {
    strcpy(files[current_file].name, name);
    files[current_file].first = NULL;
    files[current_file].last = NULL;
    current_file++;
}

void add_block(struct File* file, char* data) {
    struct Block* block = (struct Block*) malloc(sizeof(struct Block));
    strcpy(block->data, data);
    block->next = NULL;

    if (file->first == NULL) {
        file->first = block;
        file->last = block;
    } else {
        file->last->next = block;
        file->last = block;
    }
}

void read_file(struct File* file) {
    struct Block* current = file->first;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    add_file("File 1");
    add_block(&files[0], "Block 1");
    add_block(&files[0], "Block 2");
    add_block(&files[0], "Block 3");
    add_block(&files[0], "Block 4");

    read_file(&files[0]);

    return 0;
}
