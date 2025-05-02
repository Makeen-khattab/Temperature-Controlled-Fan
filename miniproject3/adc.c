#include"adc.h"
#include"gpio.h"
#include <avr/io.h>
#include "Common_Macros.h"


void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX = (ADMUX&0x3F) | (((Config_Ptr->ref_volt)<<6) & 0xC0);
	CLEAR_BIT(ADMUX,ADLAR);
	SET_BIT(ADCSRA,ADEN);
	CLEAR_BIT(ADCSRA,ADIE);
	ADCSRA=  (ADCSRA&(0xF8)) | ((Config_Ptr->prescaler)&(0x07));


}
uint16 ADC_readChannel(uint8 a_ch_num)
{
	ADMUX= ((ADMUX & 0xE0) | a_ch_num);
	SET_BIT(ADCSRA,ADSC);
	while(!(BIT_IS_SET(ADCSRA,ADIF)));

		SET_BIT(ADCSRA,ADIF);
		return (uint16)(ADC);

}

