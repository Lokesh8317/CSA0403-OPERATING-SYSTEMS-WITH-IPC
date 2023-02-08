#include<stdio.h>
#include<stdlib.h>

struct Process {
  int pid;      
  int burst;    
  int arrival;  
};

int compare(const void *a, const void *b) {

  struct Process *p1 = (struct Process *)a;
  struct Process *p2 = (struct Process *)b;
  return p1->burst - p2->burst;
}

void printGanttChart(int *gantt, int n, int len) {

  int i, j;
  for (i = 0; i < n; i++) {
    printf("P%d |", i + 1);
    for (j = 0; j < gantt[i]; j++) {
      printf("--");
    }
    printf(" ");
  }
}

int main() {
  int n, i, j, k;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  struct Process proc[n];

  printf("Enter burst time and arrival time of each process:\n");
  for (i = 0; i < n; i++) {
    proc[i].pid = i + 1;
    scanf("%d%d", &proc[i].burst, &proc[i].arrival);
  }
  
  qsort(proc, n, sizeof(struct Process), compare);

  int gantt[n];  
  int len = 0;   

  for (i = 0; i < n; i++) {
    len += proc[i].burst;
    gantt[proc[i].pid - 1] = proc[i].burst;
  }

  printf("\nGantt Chart:\n");
  printGanttChart(gantt, n, len);
  printf("\n\n");

  return 0;
}
