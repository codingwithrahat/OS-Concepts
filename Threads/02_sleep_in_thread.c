#include<stdio.h>
#include<pthread.h>  
#include<unistd.h>  //need for sleep()

void* newMssg(void* arg){
    
    int id = *(int*)arg;
    
    printf("Thread %d Started\n", id);
    sleep(2);
    printf("Thread %d finished after sleeping\n", id);

    return NULL;
}

int main(){
    pthread_t t1, t2;
    
    int a = 3, b = 4;
    
    pthread_create(&t1, NULL, newMssg, &a);  //pass a as a argument
    pthread_create(&t2, NULL, newMssg, &b);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("Both thread have completed execution\n");
    
    return 0;
}