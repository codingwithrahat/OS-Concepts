#include<stdio.h>
#include<pthread.h>  
#include<unistd.h>  

int cnt = 0;   // shared global variable (both threads use it)

void* inc(void* arg){
    for(int i = 0; i<100000; i++){
        cnt++;
    }
    
    return NULL;
}

int main(){
    pthread_t t1, t2;
    
    pthread_create(&t1, NULL, inc, NULL);
    pthread_create(&t2, NULL, inc, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("Final Value of cnt %d\n", cnt);
    // Expected: 200000
    // Actual: random (like 150000, 173421, etc.)

    return 0;
}


// t0: producer execute        | register1 = counter        | {register1 = 5}
// t1: producer execute        | register1 = register1 + 1  | {register1 = 6}
// t2: consumer execute        | register2 = counter        | {register2 = 5}
// t3: consumer execute        | register2 = register2 - 1  | {register2 = 4}
// t4: producer execute        | counter = register1         | {counter = 6}
// t5: consumer execute        | counter = register2         | {counter = 4} 
