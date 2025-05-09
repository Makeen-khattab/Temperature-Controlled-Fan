#include "adc.h"
#include "lm35.h"



uint8 LM35_getTemp(void)
{
	uint8 LM35_temp=0;
uint16 ADC_readBits=0;
ADC_readBits=ADC_readChannel(ADC2);

LM35_temp= ((uint32)(ADC_readBits) * MAXTEMP* VREF) /(LM35MAXVOLTAGE * ADC_MAXCOUNT);

return (uint8)LM35_temp;
}

