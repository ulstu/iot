#include "mbed.h"
	void print_char(char c = '*')
	{
		printf("%c", c);
		fflush(stdout);
	}

	Thread thread;

	DigitalOut led1(LED1);

	void print_thread()
	{
		while (true) {
			wait(1);
			print_char();
		}
	}

	int main()
	{
		printf("\n\n*** RTOS basic example ***\n");
		thread.start(print_thread);
		while (true) {
			led1 = !led1;
			wait(0.5);
		}
	}