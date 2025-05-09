#include "motor.h"
#include "gpio.h"
#include "timer0.h"



void DcMotor_Init(void)
{
GPIO_setupPinDirection(DCMOTOR_PORTID	,DCMOTOR_PIN1ID, PIN_OUTPUT);
GPIO_setupPinDirection(DCMOTOR_PORTID	,DCMOTOR_PIN2ID, PIN_OUTPUT);

}
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	switch (state)
	{
	case DCMOTOR_STOP :
		GPIO_writePin(DCMOTOR_PORTID,DCMOTOR_PIN1ID, LOGIC_LOW);
		GPIO_writePin(DCMOTOR_PORTID,DCMOTOR_PIN2ID, LOGIC_LOW);
		break;
	case DCMOTOR_ACW :
			GPIO_writePin(DCMOTOR_PORTID,DCMOTOR_PIN1ID, LOGIC_LOW);
			GPIO_writePin(DCMOTOR_PORTID,DCMOTOR_PIN2ID, LOGIC_HIGH);
			break;
	case DCMOTOR_CW :
				GPIO_writePin(DCMOTOR_PORTID,DCMOTOR_PIN1ID, LOGIC_HIGH);
				GPIO_writePin(DCMOTOR_PORTID,DCMOTOR_PIN2ID, LOGIC_LOW);
				break;
	default:
		;
	}
				PWM_Timer0_Start(speed);

}


