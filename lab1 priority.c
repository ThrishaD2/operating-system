non preemtive:
#include <stdio.h>

struct process {
    int id;
    int bt;
    int priority;
    int wt;
    int tat;
};

void findWaitingTime(struct process proc[], int n) {
    proc[0].wt = 0;
    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i - 1].bt + proc[i - 1].wt;
    }
}

void findTurnAroundTime(struct process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
}

void findAverageTime(struct process proc[], int n) {
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
}

void priorityScheduling(struct process proc[], int n) {
    struct process temp;


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {

                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    findWaitingTime(proc, n);
    findTurnAroundTime(proc, n);
    findAverageTime(proc, n);

    printf("\n\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", proc[i].id, proc[i].bt, proc[i].priority, proc[i].wt, proc[i].tat);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("\nEnter burst time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].bt);
        printf("Enter priority for process %d: ", proc[i].id);
        scanf("%d", &proc[i].priority);
    }

    priorityScheduling(proc, n);
    return 0;
}
######output######
Enter the number of processes: 4

Enter burst time for process 1: 2
Enter priority for process 1: 0

Enter burst time for process 2: 4
Enter priority for process 2: 2

Enter burst time for process 3: 5
Enter priority for process 3: 1

Enter burst time for process 4: 6
Enter priority for process 4: 3

Average Waiting Time: 5.00
Average Turnaround Time: 9.25

Process ID      Burst Time      Priority        Waiting Time    Turnaround Time
1               2               0               0               2
3               5               1               2               7
2               4               2               7               11
4               6               3               11              17

  preemtive:
#include <stdio.h>

struct process {
    int id;
    int bt;
    int priority;
    int wt;
    int tat;
};

void findWaitingTime(struct process proc[], int n) {
    proc[0].wt = 0;
    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i - 1].bt + proc[i - 1].wt;
    }
}

void findTurnAroundTime(struct process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
}

void findAverageTime(struct process proc[], int n) {
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
}

void priorityScheduling(struct process proc[], int n) {
    int time = 0;
    int remaining_burst[n];
    int completed = 0;
   
   
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = proc[i].bt;
    }

    while (completed < n) {
        int min_priority = 1000000;  
        int min_priority_index = -1;
       
       
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0 && proc[i].priority < min_priority) {
                min_priority = proc[i].priority;
                min_priority_index = i;
            }
        }

       
        remaining_burst[min_priority_index]--;
        time++;
 
        if (remaining_burst[min_priority_index] == 0) {
            completed++;
            proc[min_priority_index].wt = time - proc[min_priority_index].bt;
            proc[min_priority_index].tat = proc[min_priority_index].wt + proc[min_priority_index].bt;
        }
    }

    findAverageTime(proc, n);

    printf("\n\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", proc[i].id, proc[i].bt, proc[i].priority, proc[i].wt, proc[i].tat);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("\nEnter burst time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].bt);
        printf("Enter priority for process %d: ", proc[i].id);
        scanf("%d", &proc[i].priority);
    }

    priorityScheduling(proc, n);
    return 0;
}
#####output#####
Enter the number of processes: 4

Enter burst time for process 1: 2
Enter priority for process 1: 0

Enter burst time for process 2: 3
Enter priority for process 2: 1

Enter burst time for process 3: 4
Enter priority for process 3: 2

Enter burst time for process 4: 5
Enter priority for process 4: 3

Average Waiting Time: 4.00
Average Turnaround Time: 7.50

Process ID      Burst Time      Priority        Waiting Time    Turnaround Time
1               2               0               0               2
2               3               1               2               5
3               4               2               5               9
4               5               3               9               14
