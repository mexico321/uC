#include<xc.h>

#pragma config WDT = OFF
#pragma config OSC = HS
#pragma config LVP = OFF


#define B7 LATBbits.LATB7
#define B3 PORTBbits.RB3
#define led LATCbits.LATC2



void delay(long int x)
{
    x = x *350;
    while(x--);
}



void main(void)
{
    TRISBbits.TRISB7 = 0;
    TRISBbits.TRISB3 = 1;
    
    INTCON2bits.RBPU = 0;
    TRISCbits.TRISC2 = 0;
    

    B7 = 1;
    led=0;
   
    while(1)
    {
        B7 = 0;
        if( B3 == 0 )   //key is pressed
        {
            delay(1); 
            if( B3 == 0)
            {
                led^=1;
                //led_data('1');
                while(B3==0);    // wait till key is released
            }

        }

        
}
