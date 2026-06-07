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
    int response_time;

    int remaining_time;

    bool started; 

};

int main(){
    int n; 

    printf("Enter number of process: ");
    scanf("%d", &n);

    struct Process p[n];


    for(int i = 0; i<n; i++){
        p[i].pid = i + 1;
        p[i].started = false;

        printf("Enter arrival_time and burst_time fro pid %d : ", i + 1);
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);
        

        p[i].remaining_time = p[i].burst_time;

    }

    int current_time = 0;
    int complete_cnt = 0;

    float total_turnaround_time = 0, total_waiting_time = 0, total_response_time = 0;

    while(complete_cnt < n){

        int selected = -1;
        int mn_remaining = INT_MAX;

        for(int i = 0; i<n; i ++){
            if(p[i].arrival_time <= current_time && p[i].remaining_time > 0){
                if(p[i].remaining_time < mn_remaining){
                     mn_remaining = p[i].remaining_time;
                     selected = i;
                }
            }
        }

        if(selected == -1){
            current_time++;
        }else{

            if(!p[selected].started){
                p[selected].response_time = current_time - p[selected].arrival_time;
                p[selected].started = true;
            }

            p[selected].remaining_time--;
            current_time++;

            if(p[selected].remaining_time == 0){
                p[selected].completion_time = current_time;
                p[selected].turnaround_time = p[selected].completion_time - p[selected].arrival_time;
                p[selected].waiting_time = p[selected].turnaround_time - p[selected].burst_time;

                complete_cnt++;

                total_turnaround_time += p[selected].turnaround_time;
                total_waiting_time += p[selected].waiting_time;
                total_response_time += p[selected].response_time;

            }
            
        }

    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWt\tRT\n");

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