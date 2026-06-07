#include<stdio.h>
#include<unistd.h>

int main(){
    
    fork(); 
    
    // First fork() → creates 1 new process
    // Now total processes = 2
    
    fork();
    
    // Second fork() → each existing process creates a new child
    // Now total processes = 4
    
    fork();
        
    // Final number of processes = 2^3 = 8    
    
    printf("The Process is created using fork() system call\n");
    
    
    return 0;
}