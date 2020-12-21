#include "mbed.h"

PwmOut PWM1(LED1);

int main()
{
    PWM1.period(0.010); // set PWM period to 10 ms
    PWM1=0.5; // set duty cycle to 50%
}
