#include "mbed.h"
#include "RangeFinder.h"

RangeFinder rf(PA_1,10,5000,100000);

int main()
{
	float d;
	while(1){
		d =rf.read_m();
		if(d ==-1.0){
			printf("Timeout Error.\n");
		}else if(d >5.0){
			printf("No objects within detection range.\n");
		}else{
			printf("Distance = %f m.\n",d);
		}
		thread_sleep_for(500);
	}
}