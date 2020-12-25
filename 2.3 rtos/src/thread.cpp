#include "mbed.h"
	void print_char(char c = '*') //Функция вывода символа
	{
		printf("%c", c);
		fflush(stdout);
	}

	Thread thread; //Создаётся объект класса Thread

	DigitalOut led1(LED1);

	void print_thread() //Функция отдельного потока, в которой выводится символ
	{
		while (true) {
			wait(1);
			print_char();
		}
	}

	int main()
	{
		printf("\n\n*** RTOS basic example ***\n");
		thread.start(print_thread); //Включение отдельного потока с выводом символа
		while (true) { //Отдельный поток с переключением лампочки
			led1 = !led1;
			wait(0.5);
		}
	}