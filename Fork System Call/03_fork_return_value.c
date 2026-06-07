#include<stdio.h>
#include<unistd.h>

int main(){
    
    pid_t pid = fork(); //fork return a value(neg, 0, pos)
    
    // pid < 0  → fork failed
    // pid == 0 → child process
    // pid > 0  → parent process (returns child's PID)
    
    if(pid == 0){
        printf("Hello from child process\n");
    }else{
        printf("Hello from parent process\n");
    }
    
    
    return 0;
}