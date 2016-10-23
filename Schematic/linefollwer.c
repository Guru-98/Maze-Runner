#include "htc.h"
#define _XTAL_FREQ 20000000
#define EN1 RB7
#define C_M_R RB6
#define CC_M_R RB5
#define CC_M_L RB4
#define C_M_L RB3
#define EN2 RB2
#define S_L RB1
#define S_R RB0
__CONFIG(XT & WDTDIS & PWRTEN & BOREN & LVPDIS & DUNPROT & WRTEN & UNPROTECT);
void main(void)
{  
   TRISB=0x03;
   PORTB=0;
   CC_M_L=0;
   CC_M_R=0;
   while(1){
      if(S_L==1&&S_R==1){
	 EN1=1;
	 C_M_R=1;
	 
	 EN2=1;
	 C_M_L=1;
      }
      if(S_L==0&&S_R==1){
	 EN1=1;
	 C_M_R=1;
	 
	 EN2=0;
	 C_M_L=0;
      }
      if(S_L==1&&S_R==0){
	 EN1=0;
	 C_M_R=0;
	 
	 EN2=1;
	 C_M_L=1;
      }
      if(S_L==0&&S_R==0){
	 EN1=0;
	 C_M_R=0;
	 
	 EN2=0;
	 C_M_L=0;
      }
   }
}