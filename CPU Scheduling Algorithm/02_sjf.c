#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

struct Process{
    int pid;

    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;

    int start_time;
    int response_time;

    bool completed; 

};

int main(){
    int n; 

    printf("Enter number of process: ");
    scanf("%d", &n);

    struct Process p[n];


    for(int i = 0; i<n; i++){
        p[i].pid = i + 1;
        p[i].completed = false;

        printf("Enter arrival_time and burst_time fro pid %d : ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);

    }

    int current_time = 0;
    int complete_cnt = 0;

    float total_turnaround_time = 0, total_waiting_time = 0, total_response_time = 0;

    while(complete_cnt < n){

        int selected = -1;
        int mn_burst = INT_MAX;

        for(int i = 0; i<n; i ++){
            if(p[i].arrival_time <= current_time && !p[i].completed){
                if(p[i].burst_time < mn_burst){
                     mn_burst = p[i].burst_time;
                     selected = i;
                }
            }
        }

        if(selected == -1){
            current_time++;
        }else{
            p[selected].start_time = current_time;
            p[selected].completion_time = current_time + p[selected].burst_time;
            p[selected].turnaround_time = p[selected].completion_time - p[selected].arrival_time;
            p[selected].waiting_time = p[selected].turnaround_time - p[selected].burst_time;
            p[selected].response_time = p[selected].start_time - p[selected].arrival_time;

            p[selected].completed = true;
            complete_cnt++;

            current_time = p[selected].completion_time;

            total_turnaround_time += p[selected].turnaround_time;
            total_waiting_time += p[selected].waiting_time;
            total_response_time += p[selected].response_time;
            
        }


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