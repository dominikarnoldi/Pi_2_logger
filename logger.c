//
// Created by dominik.arnoldi on 18.06.2016.
//

#include "logger.h"
#include <wiringPi.h>
#include <pthread.h>
#include <stdio.h>
#define EXIT_FAILURE 1;

int  count = 0;

static void *logging_falling(void* val)
{
    wiringPiISR(0,INT_EDGE_FALLING, *count_edge);
    return NULL;
}

static void count_edge(void* val)
{
    count++;
}
static void *impulse_output(void* val)
{
    return NULL;
}

int main(void)
{
    wiringPiSetup();
    pinMode (0, OUTPUT) ;

    pthread_t thread1, thread2;
    int rc;

    //creating two threads for setting signal and counting signal
     rc = pthread_create(&thread1, NULL, &impulse_output, NULL );
    if (rc != 0) {
        printf("Konnte Thread 1 nicht erzeugen !");
        return EXIT_FAILURE;
    }
     rc = pthread_create(&thread2, NULL, &logging_falling, NULL);
    if(rc != 0)
    {
        printf("Konnte Thread 2 nicht erzeugen !");
        return EXIT_FAILURE;
    }

    for (;;)
    {
        digitalWrite (0, HIGH) ; delay (500) ;
        digitalWrite (0,  LOW) ; delay (500) ;
    }
    return 0 ;
}
