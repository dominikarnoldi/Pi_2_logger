//
// Created by dominik.arnoldi on 18.06.2016.
//

#include "logger.h"
#include <wiringPi.h>

int main(viod)
{
    wiringPiSetup();
    pinMode (0, OUTPUT) ;
    for (;;)
    {
        digitalWrite (0, HIGH) ; delay (500) ;
        digitalWrite (0,  LOW) ; delay (500) ;
    }
    return 0 ;
}