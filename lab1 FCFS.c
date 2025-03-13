#include<stdio.h>
int n,i,j,pos, temp, choice, Burst_time[20], waiting_time[20], Turn_around_time[20], process[20], total=0;
float avg_turn_around_time=0;
avg_waiting_time=0;
void FCFS()
{
    waiting_time[0]=0;
    for(i=1;i<n;i++){
        waiting_time[i]=0;
        for(j=0;j<i;j++){
            waiting_time[i]+=Burst_time[j];
        }
    }
        printf("\n Process\t\Burst Time\t\t waiting time\t\t turnaround time");
        for(i=0;i<n;i++){
            Turn_around_time[i]=Burst_time[i]+waiting_time[i];
            avg_waiting_time+=waiting_time[i];
            avg_turn_around_time+=Turn_around_time[i];
            printf("\n P[%d]\t\t%d\t\t\t%d\t\t\t\t%d",i+1,Burst_time[i],waiting_time[i],Turn_around_time[i]);
        }
            avg_waiting_time=(float)avg_waiting_time/(float)i;
            avg_turn_around_time=(float)avg_turn_around_time/(float)i;
            printf("\nAverage waiting time:%.2f",avg_waiting_time);
            printf("\n Average turn around time:%.2f\n",avg_turn_around_time);
        }
    int main(){
        printf("enter the total number of processes:");
        scanf("%d",&n);
        printf("\nEnter burst time:\n");
        for(i=0;i<n;i++){
            printf("\nP[%d]:",i+1);
            scanf("%d",&Burst_time[i]);  
            process[i]=i+1;
        }
        while(1){
            printf("\nMAIN MENU\n");
            printf("\n 1.FCFS scheduling\n");
            printf("\n Enter your choice:");
            scanf("%d",&choice);
            switch(choice){
            case 1:FCFS();
            break;
            default:
                printf("Invalid input");
            }
        }
        return 0;
        }



###output###
Enter the total number of processes: 4

Enter burst time:
P[1]: 0
P[2]: 2
P[3]: 3
P[4]: 4  

MAIN MENU
1. FCFS Scheduling
Enter your choice: 1

 Process      Burst Time    Waiting Time    Turnaround Time
 P[1]        0            0               5
 P[2]        2            0               2
 P[3]        3            2               19
 P[4]        4            5               9

Average Waiting Time: 0.00
Average Turnaround Time: 4.00
