preemtive:
#include <stdio.h>

#define MAX 100

typedef struct {
    int at, bt, rt, ct, tat, wt;
} Process;

int main() {
    int n, completed = 0, time = 0, min_rt, shortest;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("AT & BT of P%d: ", i + 1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
    }

    while (completed < n) {
        shortest = -1, min_rt = 1e9;

        for (int i = 0; i < n; i++)
            if (p[i].at <= time && p[i].rt > 0 && p[i].rt < min_rt)
                min_rt = p[i].rt, shortest = i;

        if (shortest == -1) { time++; continue; }

        p[shortest].rt--;

        if (p[shortest].rt == 0) {
            p[shortest].ct = time + 1;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
            completed++;
        }
        time++;
    }

    printf("\nAT\tBT\tCT\tTAT\tWT\n");
    float totalTAT = 0, totalWT = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }

    printf("\nAvg TAT: %.2f, Avg WT: %.2f\n", totalTAT / n, totalWT / n);
    return 0;
}
######output#######
Enter number of processes: 4
AT & BT of P1: 2 3
AT & BT of P2: 4 5
AT & BT of P3: 6 3
AT & BT of P4: 2 6

AT      BT      CT      TAT     WT
2       3       5       3       0
4       5       13      9       4
6       3       9       3       0
2       6       19      17      11

Avg TAT: 8.00, Avg WT: 3.75



non preemtive:
#include<stdio.h>

    int n, i, j, pos, temp, choice, Burst_time[20], Waiting_time[20], Turn_around_time[20], process[20], total=0;

    float avg_Turn_around_time=0, avg_Waiting_time=0;
    int SJF()

{

    //sorting

    for(i=0;i<n;i++)

    {

        pos=i;

        for(j=i+1;j<n;j++)

        {

            if(Burst_time[j]<Burst_time[pos])

                pos=j;

        }



        temp=Burst_time[i];

        Burst_time[i]=Burst_time[pos];

        Burst_time[pos]=temp;



        temp=process[i];

        process[i]=process[pos];

        process[pos]=temp;

    }

        Waiting_time[0]=0;





    for(i=1;i<n;i++)

    {

        Waiting_time[i]=0;



        for(j=0;j<i;j++)

            Waiting_time[i]+=Burst_time[j];



        total+=Waiting_time[i];

    }



    avg_Waiting_time=(float)total/n;

    total=0;



    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");



    for(i=0;i<n;i++)

    {

        Turn_around_time[i]=Burst_time[i]+Waiting_time[i];

        total+=Turn_around_time[i];

        printf("\nP[%d]\t\t%d\t\t\t%d\t\t\t\t%d",process[i],Burst_time[i],Waiting_time[i],Turn_around_time[i]);

    }



    avg_Turn_around_time=(float)total/n;

    printf("\n\nAverage Waiting Time=%f",avg_Waiting_time);

    printf("\nAverage Turnaround Time=%f\n",avg_Turn_around_time);

}



int main()

{

    printf("Enter the total number of processes:");

    scanf("%d",&n);



    printf("\nEnter Burst Time:\n");

    for(i=0;i<n;i++)

    {

        printf("P[%d]:",i+1);

        scanf("%d",&Burst_time[i]);

        process[i]=i+1;

    }



    while(1)

    {   printf("\n-----MAIN MENU-----\n");

        printf("1.SJF Scheduling\n");

        printf("\nEnter your choice:");

        scanf("%d", &choice);

        switch(choice)

        {

            case 1: SJF();

            break;





            default: printf("Invalid Input!!!");

        }

    }

    return 0;

}
########OUTPUT####

Enter the total number of processes:4

Enter Burst Time:
P[1]:2
P[2]:3
P[3]:4
P[4]:5

-----MAIN MENU-----
1.SJF Scheduling

Enter your choice:1

Process         Burst Time              Waiting Time            Turnaround Time
P[1]            2                       0                               2
P[2]            3                       2                               5
P[3]            4                       5                               9
P[4]            5                       9                               14

Average Waiting Time=4.000000
Average Turnaround Time=7.500000
