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
    bool completed;
    bool in_queue;
};


int main(){
    int n; 

    printf("Enter number of porcess : ");
    scanf("%d", &n);

    struct Process p[n];


    for(int i = 0; i<n; i++){
        p[i].pid = i + 1;

        printf("Enter arrival time and burst time : ");
        scanf("%d %d", &p[i].arrival_time, &p[i].burst_time);

        p[i].remaining_time = p[i].burst_time;
        p[i].started = false;
        p[i].completed = false;
        p[i].in_queue = false;

    }

    int time_quantum;

    printf("Enter time quantum : ");
    scanf("%d", &time_quantum);

    int queue[1000];
    int front = 0, rear = 0;

    int current_time = 0;

	float total_turnaround_time = 0;
	float total_waiting_time = 0;
	float total_response_time = 0;

	int complete_cnt = 0;

    while(complete_cnt < n){
        for(int i = 0; i<n; i++){
            if(p[i].arrival_time <= current_time && !p[i].completed && !p[i].in_queue && p[i].remaining_time > 0){
                queue[rear++] = i;
                p[i].in_queue = true;
            }
        }

        if(front == rear){
            current_time++;
            continue;
        }

        int selected = queue[front++];
        p[selected].in_queue = false;

        if(p[selected].started == false){
            p[selected].response_time = current_time - p[selected].arrival_time;

            p[selected].started = true;
        }

        if(p[selected].remaining_time > time_quantum){
            current_time += time_quantum;
            p[selected].remaining_time -= time_quantum;
        }else{
            current_time += p[selected].remaining_time;
            p[selected].remaining_time = 0;

            p[selected].completion_time = current_time;
            p[selected].turnaround_time = p[selected].completion_time - p[selected].arrival_time;
            p[selected].waiting_time = p[selected].turnaround_time - p[selected].burst_time;

            p[selected].completed = true;
            complete_cnt++;

            total_turnaround_time += p[selected].turnaround_time;
            total_waiting_time += p[selected].waiting_time;
            total_response_time += p[selected].response_time;

        }


        for(int i = 0; i<n; i++){
            if(p[i].arrival_time <= current_time && !p[i].completed && !p[i].in_queue && p[i].remaining_time > 0 && i != selected){
                queue[rear++] = i;
                p[i].in_queue = true;
            }
        }

        if(p[selected].remaining_time > 0){
            queue[rear++] = selected;
            p[selected].in_queue = true;
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