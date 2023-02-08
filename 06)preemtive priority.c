#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct Process {
  int id;
  int burstTime;
  int priority;
};

void sortByPriority(struct Process *processes, int n) {
  int i, j;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (processes[j].priority > processes[j+1].priority) {
        struct Process temp = processes[j];
        processes[j] = processes[j+1];
        processes[j+1] = temp;
      }
    }
  }
}

int main() {
  int n, i;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  if (n > MAX_PROCESSES) {
    printf("Error: Maximum number of processes exceeded.");
    return 1;
  }

  struct Process processes[MAX_PROCESSES];
  for (i = 0; i < n; i++) {
    processes[i].id = i+1;
    printf("Enter burst time and priority of process %d: ", i+1);
    scanf("%d%d", &processes[i].burstTime, &processes[i].priority);
  }

  sortByPriority(processes, n);

  printf("\nProcess ID\tBurst Time\tPriority\n");
  for (i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, processes[i].priority);
  }

  return 0;
}
