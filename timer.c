#include <xc.h>
#pragma config WDT = OFF
#pragma config OSC = HS

void main(void)
{
TRISCbits.TRISC2 = 0;
LATCbits.LATC2 = 1;
T0CON = 0x85;
TMR0 = 60536;
while(1)
{
while( TMR0IF == 0);
TMR0 = 60536;
TMR0IF = 0;
LATCbits.LATC2 ^= 1;
}
return;
}
