#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100

struct Employee {
    int id;
    char name[50];
    int age;
    float salary;
};

void write_employee_data(FILE *fp) {
    struct Employee emp;
    printf("Enter employee id: ");
    scanf("%d", &emp.id);
    printf("Enter employee name: ");
    scanf("%s", emp.name);
    printf("Enter employee age: ");
    scanf("%d", &emp.age);
    printf("Enter employee salary: ");
    scanf("%f", &emp.salary);
    fseek(fp, (emp.id - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, fp);
}

void read_employee_data(FILE *fp) {
    struct Employee emp;
    int id;
    printf("Enter employee id to read: ");
    scanf("%d", &id);
    fseek(fp, (id - 1) * sizeof(struct Employee), SEEK_SET);
    fread(&emp, sizeof(struct Employee), 1, fp);
    printf("Employee id: %d\n", emp.id);
    printf("Employee name: %s\n", emp.name);
    printf("Employee age: %d\n", emp.age);
    printf("Employee salary: %.2f\n", emp.salary);
}

int main() {
    FILE *fp;
    int choice;

    fp = fopen("employee.dat", "w+b");
    if (!fp) {
        printf("Error opening file\n");
        exit(1);
    }

    while (1) {
        printf("1. Write employee data\n");
        printf("2. Read employee data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                write_employee_data(fp);
                break;
            case 2:
                read_employee_data(fp);
                break;
            case 3:
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}

