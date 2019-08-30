#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//Execute a program launch 2 thread write 2 different things
//Both will wait each other before quit program
void *draw(void *my_char) {
    char* cvar = (char*) my_char;

    for(int i = 0; i < 30; i++) {
        write(2, cvar, 1* sizeof(char));
    }
    return 0;
}

int main(int argc, char** argv) {
    char c1 = '*', c2 = '$';

    pthread_t star_thread, dollar_thread;

    //int pthread_create(pthread_t * threadid , pthread_attr_t * attr,void *(* start_routine )(void *), void* arg );
    if(pthread_create(&star_thread, NULL, draw, (void*)&c1)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    if(pthread_create(&dollar_thread, NULL, draw, (void*)&c2)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    //int pthread_join(pthread_t th , void ** thread_return );
    if(pthread_join(star_thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    if(pthread_join(dollar_thread, NULL)) {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    pthread_exit(NULL);
}