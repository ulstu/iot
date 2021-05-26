#include "mbed.h"

	InterruptIn button(USER_BUTTON); //Создание объекта класса прерывания
	DigitalOut led(LED1);

	double delay = 0.5; // 500 ms
	void pressed() //Функция, если нажата кнопка
	{
		delay = 0.1; // 100 ms
	}

	void released() //Если отжата кнопка
	{
		delay = 0.5; // 500 ms
	}

	int main()
	{
	// Assign functions to button
		button.fall(&pressed); //Кнопка нажата
		button.rise(&released); // Кнопка отжата
		while (1) {
			led = !led;
			wait(delay); //Ожидание в зависимости от того, нажата кнопка или нет
		}
	}