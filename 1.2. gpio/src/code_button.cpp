#include "mbed.h"
 
DigitalIn mybutton(USER_BUTTON);
DigitalOut myled(LED1);

int main()
{
    mybutton.mode(PullUp);

    while(1) {
        printf("Button state is: %d\n\r", mybutton.read());

        if (mybutton == 0) { // Button is pressed

            myled = !myled; // Toggle the LED state
            wait_ms(200); // 200 ms
        }
    }
}
```