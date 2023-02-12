#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_RECORD_LENGTH 50

struct Record {
    char data[MAX_RECORD_LENGTH];
} records[MAX_RECORDS];

int current_record = 0;

void add_record(char* data) {
    strcpy(records[current_record].data, data);
    current_record++;
}

void read_record(int record_number) {
    for (int i = 0; i < record_number; i++) {
        printf("%s\n", records[i].data);
    }
}

int main() {
    add_record("Record 1");
    add_record("Record 2");
    add_record("Record 3");
    add_record("Record 4");

    read_record(2);

    return 0;
}
