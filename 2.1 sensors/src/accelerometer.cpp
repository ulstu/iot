#include "mbed.h"
#include "ADXL345_I2C.h"

ADXL345_I2C accelerometer(I2C_SDA,I2C_SCL); //I2C sda and scl

int main()
{
	int readings[3] = {0,0,0};
	printf("Starting ADXL345 text...\n");
	
	//Перейдите в режим ожидания, чтобы настроить устройство.
	accelerometer.setPowerControl(0x00);
	
	// Полное разрешение, +/- 16 г, 4 мг / младший бит.
	accelerometer.setDataFormatControl(0x0B);
	
	// Скорость передачи данных 3.2 кГц.
	accelerometer.setDataRate(ADXL345_3200HZ);
	
	// Режим измерения.
	accelerometer.setPowerControl(0x08);

	while(1){
		thread_sleep_for(1000);
		accelerometer.getOutput(readings);
		
		// 13-битные, знаковые расширенные значения.
		printf("%i, %i, %i\n",(int16_t)readings[0],(int16_t)readings[1],(int16_t)readings[2]);
	}
}