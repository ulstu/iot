#include "mbed.h"
#include "ADXL345_I2C.h"

ADXL345_I2C accelerometr(I2C_SDA,I2C_SCL);

int main()
{
	int readings[3] = {0,0,0};
	printf("Starting ADXL345 text...\n");
	accelerometr.setPowerControl(0x00);
	accelerometr.setDataFormatControl(0x0B);
	accelerometr.setDataRate(ADXL345_3200HZ);
	accelerometr.setPowerControl(0x08);

	while(1){
		thread_sleep_for(1000);
		accelerometr.getOutput(readings);
		printf("%i, %i, %i\n",(int16_t)readings[0],(int16_t)readings[1],(int16_t)readings[2]);
	}
}