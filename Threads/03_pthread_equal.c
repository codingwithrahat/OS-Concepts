#include<stdio.h>
#include<pthread.h>  
#include<unistd.h>  

int main(){
    pthread_t t1, t2;
    
    t1 = pthread_self();
    t2 = pthread_self();

    if(pthread_equal(t1, t2)){
        printf("Id same\n");
    }else{
        printf("Id not same\n");
    }

    return 0;
}