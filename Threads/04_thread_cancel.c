#include<stdio.h>
#include<pthread.h>  
#include<unistd.h>  

void* work(void* arg){
    while(1){
        printf("Thread is running\n");
        sleep(1);
    }
    
    return NULL;
}

int main(){
    pthread_t t;
    
    pthread_create(&t, NULL, work, NULL);
    sleep(5); //let thread run 5 time
    
    pthread_cancel(t);
    pthread_join(t, NULL);
    
    printf("Thread has been cancel\n");

    return 0;
}

