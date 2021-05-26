#include "mbed.h"

//AnalogIn - класс для считывания внешнего напряжения, приложенного к аналоговому входному выводу. 
//PA_1 - порт, к которому подключен световой сенсор
AnalogIn light_sensor(PA_1);

int main()
{
	float res;
	while (true) {
	
		//считывание светового сигнала
		res = light_sensor.read()*100; 
		printf("%2.2f\n",res);
		
		//сон за указанный период времени в мс
		thread_sleep_for(1000);
	}
}