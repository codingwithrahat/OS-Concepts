#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* fun(void* arg){
    char* task_name = (char*)arg;  //string
    
    printf("%s started\n", task_name);
    sleep(2);
    printf("%s finished\n", task_name);
    
    return NULL;
}

int main(){
    pthread_t t1, t2;
    
    pthread_create(&t1, NULL, fun, "grilling steak");
    pthread_create(&t2, NULL, fun, "boiling pasta");
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    return 0;
}
