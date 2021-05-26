#include "mbed.h"
	
	Ticker toggle_led_ticker; //Создаётся объект класса Ticker 
	DigitalOut led1(LED1);
	void toggle_led() //Переключение лампочки
	{
		led1 = !led1;
	}

	int main()
	{
		//Срабатывание переключения лампочки каждые 100 миллисекунд
		toggle_led_ticker.attach(&toggle_led, 0.1);
		while (true) {
			//Какие либо другие действия
		}
	}