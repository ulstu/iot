#include "mbed.h"
DigitalOut relay(D6);
int on = 1,off = 0;
int main()
{
 
    while(1) {
        relay = on;
        wait(1);
        relay = off;
        wait(1);
    }
}