#include<stdio.h>
#include<unistd.h>  //for fork()

int main(){
    
    fork(); 
    
    // fork() creates a new child process
    // After this line, there are 2 processes:
    // 1. Parent process
    // 2. Child process

    // Both processes continue execution from this point
    
    printf("The Process is created using fork() system call\n");
    
    // This line will be executed twice:
    // once by the parent process and once by the child process
    
    return 0;
}