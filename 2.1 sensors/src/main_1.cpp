#include "mbed.h"

AnalogIn light_sensor(PA_1);

int main()
{
	float res;
	while (true) {
		res = light_sensor.read()*100;
		printf("%2.2f\n",res);
		thread_sleep_for(1000);
	}
}