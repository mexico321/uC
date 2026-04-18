
#include <xc.h>
#pragma config WDT = OFF
#pragma config OSC = HS
#pragma config LVP = OFF

#define D2 LATDbits.LATD2
#define D3 LATDbits.LATD3
#define B_Port LATB



char arr[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int count = 0;

void delay(unsigned long int i) {
    i *= 360;
    while (i--);
}

void main(void) {
    //    set as output
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    TRISB = 0;

    D2 = 1;
    D3 = 1;
    int num = 99;
    while (1) {
        int LSB = num % 10;
        int MSB = num / 10;
        B_Port = arr[LSB];
        D3 = 0;
        delay(5);
        D3 = 1;
        B_Port = arr[MSB];
        D2 = 0;
        delay(5);
        D2 = 1;
        count++;
        if (count == 100) {
            count = 0;
            if(num > 0){
                num--;
            }
            else{
                num = 99;
            }
        } 
    }

    return;
}
