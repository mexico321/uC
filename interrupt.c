#include <xc.h>
#pragma config WDT = OFF
#pragma config OSC = HS

void __interrupt() ISR(void) {
    if (TMR0IF == 1) {
        TMR0IF = 0;
        TMR0 = 60536;
        LATCbits.LATC2 ^= 1;
    }
    if (INT0IF == 1) {
    }
}

void main(void) {
    TRISCbits.TRISC2 = 0;
    LATCbits.LATC2 = 1;
    T0CON = 0x85;
    TMR0 = 60536;
    TMR0IE = 1;
    PEIE = 1;
    GIE = 1;
    return;
}
