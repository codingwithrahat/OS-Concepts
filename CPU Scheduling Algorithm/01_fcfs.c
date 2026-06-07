#include<stdio.h>

struct Process{
    int pid;

    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;

    int start_time;
    int response_time;

};


int main(){
    int n; 

    printf("Enter number of process: ");
    scanf("%d", &n);

    struct Process p[n];


    for(int i = 0; i<n; i++){
        p[i].pid = i + 1;

        printf("Enter arrival_time and burst_time fro pid %d : ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);

    }

    for(int i = 0; i<n - 1; i++){
        for(int j = 0; j<n - i - 1; j++){
            if(p[j].arrival_time > p[j + 1].arrival_time){
                struct Process temp;
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }


    int current_time = 0;

    float total_turnaround_time = 0, total_waiting_time = 0, total_response_time = 0;

    for(int i = 0; i<n; i++){

        if(current_time < p[i].arrival_time){
            current_time = p[i].arrival_time;
        }

        p[i].start_time = current_time;

        p[i].completion_time = current_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        p[i].response_time = p[i].start_time - p[i].arrival_time;

        current_time = p[i].completion_time;

        total_turnaround_time += p[i].turnaround_time;
        total_waiting_time += p[i].waiting_time;
        total_response_time += p[i].response_time;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i = 0; i<n; i++){
        printf("p%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,
            p[i].arrival_time,
            p[i].burst_time,
            p[i].completion_time,
            p[i].turnaround_time,
            p[i].waiting_time,
            p[i].response_time);

    }

    printf("Average turnaround_time : %0.2f\n", total_turnaround_time / n);
    printf("Average waiting_time : %0.2f\n", total_waiting_time / n);
    printf("Average response_time : %0.2f\n", total_response_time / n);

}