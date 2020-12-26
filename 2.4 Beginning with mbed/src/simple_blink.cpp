
#include "mbed.h"
DigitalOut myled(LED1);
int main()
{
    while(true){
        myled = 1;
        wait(0.5);
        myled = 0;
        wait(0.5);
        }
}
