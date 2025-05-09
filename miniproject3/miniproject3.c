#include"timer0.h"
#include "adc.h"
#include "lm35.h"
#include "lcd.h"
#include "motor.h"


int main(void)
{
	uint8 temp;
	ADC_ConfigType ADC_attributes={ADC_INTERNAL_2560mv,ADC_F_CPUOVER_8};
	PWM_Timer0_init();
	ADC_init(&ADC_attributes);
	DcMotor_Init();
	LCD_init();

	while(1)
	{
		temp=LM35_getTemp();

		if(temp<30)
		{

			LCD_displayStringRowColumn(1, 5, "FAN is OFF");
			LCD_displayStringRowColumn(2, 3, "Temp = ");
			LCD_intgerToString(temp);
			LCD_displayString(" c ");
			DcMotor_Rotate(DCMOTOR_STOP, 0);
		}


		else if(temp<60)
		{
			LCD_displayStringRowColumn(1, 5, "FAN is ON ");
			LCD_displayStringRowColumn(2, 3, "Temp = ");
			LCD_intgerToString(temp);
			LCD_displayString(" c ");
			DcMotor_Rotate(DCMOTOR_CW, 25);
		}
		else if (temp<90)
		{
			LCD_displayStringRowColumn(1, 5, "FAN is ON ");
			LCD_displayStringRowColumn(2, 3, "Temp = ");
			LCD_intgerToString(temp);
			LCD_displayString(" c ");
			DcMotor_Rotate(DCMOTOR_CW, 50);

		}
		else if(temp<120)
		{
			LCD_displayStringRowColumn(1, 5, "FAN is ON ");
			LCD_displayStringRowColumn(2, 3, "Temp = ");
			LCD_intgerToString(temp);
			LCD_displayString(" c ");
			DcMotor_Rotate(DCMOTOR_CW, 75);
		}
		else
		{
			LCD_displayStringRowColumn(1, 5, "FAN is ON ");
			LCD_displayStringRowColumn(2, 3, "Temp = ");
			LCD_intgerToString(temp);
			LCD_displayString(" c ");
			DcMotor_Rotate(DCMOTOR_CW, 100);
		}


	}



}

