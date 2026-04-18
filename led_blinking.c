#include <xc.h>
#pragma config WDT = OFF
#pragma config OSC = HS

void delay(long int x)
{
x = x *350;
while(x--);
}

void main(void){
TRISCbits.TRISC2 = 0;
while(1)
{
delay(1);
LATCbits.LATC2 = 0;
delay(10000);
LATCbits.LATC2 = 1;
}
return;
}
