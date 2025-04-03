#include<stdio.h>
# define max 10

typedef struct{
    int pid,arrival,burst;
}proc;

void sort_by_arrival(proc q[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(q[j].arrival>q[j+1].arrival){
                proc temp=q[j];
                q[j]=q[j+1];
                q[j+1]=temp;
            }
        }
    }
}
void fcfs(proc q[],int n){
int time=0;
printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
for(int i=0;i<n;i++){
    if(time<q[i].arrival){
        time=q[i].arrival;
    }
        int CT=time+q[i].burst;
        int TAT=CT-q[i].arrival;
        int WT=TAT-q[i].burst;
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",q[i].pid,q[i].arrival,q[i].burst,CT,TAT,WT);
        time=CT;
    }
}

void main()
{
    int n,sys_count=0,user_count=0;
    proc sys_queue[max],user_queue[max];
    printf("Enter no. of process:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        proc P;
        int type;
        printf("Enter PID,AT,BT,type(0=sys,1=user);");
        scanf("%d%d%d%d",&P.pid,&P.arrival,&P.burst,&type);
        if(type==0){
            sys_queue[sys_count++]=P;
        }
        else{
            user_queue[user_count++]=P;
        }
    }
        sort_by_arrival(sys_queue,sys_count);
        sort_by_arrival(user_queue,user_count);

        if(sys_count>0){
        printf("\n Sys process(Higher Priority)\n");
        fcfs(sys_queue,sys_count);
        }
        if(user_count>0){
            printf("\n Sys process(Lower Priority)\n");
            fcfs(user_queue,user_count);
        }
}

##########output#########
Enter PID,AT,BT,type(0=sys,1=user);1
2
5
0
Enter PID,AT,BT,type(0=sys,1=user);2
3
6
1
Enter PID,AT,BT,type(0=sys,1=user);3
2
7
0
Enter PID,AT,BT,type(0=sys,1=user);4
5
3
1

 Sys process(Higher Priority)
PID     AT      BT      CT      TAT     WT
1       2       5       7       5       0
3       2       7       14      12      5

 Sys process(Lower Priority)
PID     AT      BT      CT      TAT     WT
2       3       6       9       6       0
4       5       3       12      7       4

Process returned 2 (0x2)   execution time : 30.435 s
Press any key to continue.

