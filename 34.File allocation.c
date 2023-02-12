#include <stdio.h>

#define MAX_RECORDS 100 

int main() {
    int records[MAX_RECORDS]; 
    int num_records = 0; 
    int record_size = sizeof(int);
    int next_free_record = 0; 

    while (1) {
        int value;
        printf("Enter a value to add to the file (-1 to stop): ");
        scanf("%d", &value);

        if (value == -1) {
            break; 
        }

        if (next_free_record >= MAX_RECORDS) {
            printf("Error: file is full\n");
            break; 
        }

        records[next_free_record] = value;

        next_free_record += record_size;

        num_records++;
    }
    for (int i = 0; i < num_records; i++) {
        int value = records[i];
        printf("%d\n", value);
    }

    return 0;
}

