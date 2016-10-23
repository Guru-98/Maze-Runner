#include "htc.h"
#define _XTAL_FREQ 20000000
#include "pwm.h"
#define EN1    RD0
#define C_M_R  RC1
#define CC_M_R RD1
#define CC_M_L RD2
#define C_M_L  RC2
#define EN2    RD3
#define S_L    RB7
#define S_R    RB6
__CONFIG(HS & WDTDIS & PWRTEN & BOREN & LVPEN & DUNPROT & WRTEN & UNPROTECT);
void main(void)
{  
   TRISB=0xFF;
   PORTB=0;
   TRISC=0x00;
   PORTC=0;
   TRISD=0x00;
   PORTD=0;
   PWM1_Init(100);
   PWM2_Init(100);
   PWM1_Start();
   PWM2_Start();
   CC_M_L=0;
   CC_M_R=0;
   while(1){
      if(S_L==1&&S_R==1){
	 EN1=1;
	 //C_M_R=1;
	 PWM1_Duty(50);
	 
	 EN2=1;
	 //C_M_L=1;
	 PWM2_Duty(50);
      }
      if(S_L==0&&S_R==1){
	 EN1=1;
	 //C_M_R=1;
	 PWM1_Duty(50);
	 
	 EN2=0;
	 //C_M_L=0;
	 PWM2_Duty(0);
      }
      if(S_L==1&&S_R==0){
	 EN1=0;
	 //C_M_R=0;
	 PWM1_Duty(0);
	 
	 EN2=1;
	 //C_M_L=1;
	 PWM2_Duty(50);
      }
      if(S_L==0&&S_R==0){
	 EN1=0;
	 //C_M_R=0;
	 PWM1_Duty(0);
	 
	 EN2=0;
	 //C_M_L=0;
	 PWM2_Duty(0);
      }
   }
}