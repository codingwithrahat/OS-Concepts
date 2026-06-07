#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>  //for wait

int main(){
    
    pid_t pid = fork(); 
    
    if(pid == 0){
        printf("Hello from child process\n");
    }else{
        
        // This executes before wait() is called
        printf("Before Wait\n");
            
        // Parent process waits for the child to finish
        wait(NULL);
        printf("Hello from parent process\n");
    }
    
    
    return 0;
}