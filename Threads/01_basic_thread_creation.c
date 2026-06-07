#include<stdio.h>
#include<pthread.h> //need for posix thread functions

void* newMssg(void* arg){
    printf("Thread is Running\n");
    printf("Thread id %lu\n", pthread_self()); //pthread_self() return self id

    return NULL;
}

int main(){
    pthread_t t1, t2; //decleare thread
    
    //thread creation
    pthread_create(&t1, NULL, newMssg, NULL);
    pthread_create(&t2, NULL, newMssg, NULL);
    
    pthread_join(t1, NULL);  //main thread wait for t1 to finish  
    pthread_join(t2, NULL);
    
    printf("Both thread have completed execution\n");
    
    return 0;
}