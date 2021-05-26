#include "mbed.h"

	DigitalOut led1(LED1);

	InterruptIn button1(USER_BUTTON); //Создаётся объект класса прерывания
	volatile bool button1_pressed = false; // Используется в главном цикле
	volatile bool button1_enabled = true; // Используется для устранения дребезга
	Timeout button1_timeout; // Used for debouncing

	// Включение кнопки, когда дребезг кончится
	void button1_enabled_cb(void)
	{
		button1_enabled = true;
	}

	// Событие при нажатии кнопки
	void button1_onpressed_cb(void)
	{
		if (button1_enabled) { // Выключение кнопки, когда на неё нажали
			button1_enabled = false;
			button1_pressed = true; // Готова к использованию в главном цилке
			button1_timeout.attach(callback(button1_enabled_cb), 0.3); // Включение через 300 миллисекунд
		}
	}

	int main()
	{
		
		button1.fall(callback(button1_onpressed_cb)); // Если кнопка нажата, вызов события

		int idx = 0; //Только нужен для вывода

		while(1) {
			if (button1_pressed) { // Если кнопка нажата
				button1_pressed = false;
				printf("Button pressed %d\n", idx++);
				led1 = !led1;
			}
		}
	}