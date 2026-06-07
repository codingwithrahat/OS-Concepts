#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h> 

int main(){
    
    pid_t pid = fork(); 

    if(pid < 0){
        //forok failed
        printf("fork failed\n");

    }else if(pid == 0){

        printf("child running 'ls -l'\n");

        // execlp replaces current process with new program
        execlp("ls", "ls", "-l", NULL);
        

        printf("Child : exec failed\n"); //runs only if exec failed

    }else{
        
        printf("waiting for child\n");
        
        wait(NULL);
        printf("Hello from parent process\n");
    }
    
    
    return 0;
}