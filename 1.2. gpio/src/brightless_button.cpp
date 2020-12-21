#include "mbed.h"
Serial pc(USBTX, USBRX); // tx, rx
PwmOut led(LED1);
float brightness=0.0;

int main()
{
    pc.printf("Control of LED dimmer by host terminal\n\r");
    pc.printf("Press 'u' = brighter, 'd' = dimmer\n\r");

    while(1) {
        char c = pc.getc();
        wait(0.001);
        if((c == 'u') && (brightness < 0.1)) {
            brightness += 0.001;
            led = brightness;
        }

        if((c == 'd') && (brightness > 0.0)) {
            brightness -= 0.001;
            led = brightness;
        }
        pc.printf("%c %1.3f \n \r",c,brightness);
    }
}