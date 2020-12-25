#include "mbed.h"
#include "RangeFinder.h"

//Указываем pio(PA_1), scale(10), pulsetime(5000), timeout(100000)
RangeFinder rf(PA_1,10,5000,100000);

int main()
{
	float d;
	while(1){
		d = rf.read_m();
		if(d == -1.0){ // если есть ошибки подключения
			printf("Timeout Error.\n");
		}else if(d > 5.0){ // если расстояние до объекта слишком большое
			printf("No objects within detection range.\n");
		}else{
			printf("Distance = %f m.\n",d);
		}
		thread_sleep_for(500);
	}
}