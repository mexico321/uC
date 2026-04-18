#include <xc.h>
#pragma config WDT = OFF
#pragma config OSC = HS
#pragma config LVP=OFF

#define C1 PORTBbits.RB3
#define C2 PORTBbits.RB2
#define C3 PORTBbits.RB1
#define C4 PORTBbits.RB0
#define R1 LATBbits.LATB7
#define R2 LATBbits.LATB6
#define R3 LATBbits.LATB5
#define R4 LATBbits.LATB4
#define Led LATCbits.LATC2

#define RS LATDbits.LATD0
#define EN LATDbits.LATD1
#define D4 LATDbits.LATD4
#define D5 LATDbits.LATD5
#define D6 LATDbits.LATD6
#define D7 LATDbits.LATD7

void delay(unsigned long int i) {
    i *= 360;
    while (i--);
}

void lcdcmd(unsigned char cmd) { 
    RS = 0;
    D4 = (cmd >> 4)&1;
    D5 = (cmd >> 5)&1;
    D6 = (cmd >> 6)&1;
    D7 = (cmd >> 7)&1;
    EN = 1;
    delay(2);
    EN = 0;
    D4 = (cmd >> 0)&1;
    D5 = (cmd >> 1)&1;
    D6 = (cmd >> 2)&1;
    D7 = (cmd >> 3)&1;
    EN = 1;
    delay(2);
    EN = 0;
}

void lcd_init() {
    lcdcmd(0x28);
    delay(1);
    lcdcmd(0x28);
    delay(1);
    lcdcmd(0x28);
    delay(1);
    lcdcmd(0x0F);
    delay(1);
    lcdcmd(0x01);
    delay(1);
    //setting the address
}

void lcd_data(unsigned char data) { //For sending data
    RS = 1;
    D4 = (data >> 4)&1;
    D5 = (data >> 5)&1;
    D6 = (data >> 6)&1;
    D7 = (data >> 7)&1;
    EN = 1;
    delay(1);
    EN = 0;
    D4 = (data >> 0)&1;
    D5 = (data >> 1)&1;
    D6 = (data >> 2)&1;
    D7 = (data >> 3)&1;
    EN = 1;
    delay(1);
    EN = 0;
}

void main(void) {
    INTCON2bits.RBPU = 0;
    TRISBbits.TRISB2 = 1; //set as B2 pin input
    TRISBbits.TRISB3 = 1; // B3 input
    TRISBbits.TRISB1 = 1; // B1 input
    TRISBbits.TRISB0 = 1; // B0 input
    TRISCbits.TRISC2 = 0; // set as led pin output
    TRISBbits.TRISB7 = 0; // set as B7 pin output
    TRISBbits.TRISB6 = 0; // set as B6 pin output
    TRISBbits.TRISB5 = 0; // set as B5 pin output
    TRISBbits.TRISB4 = 0; // set as B4 pin output

    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD4 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    EN = 0;
    //initialize the LCD
    lcd_init();
    lcdcmd(0x80);
    delay(1);

    Led = 0;

    while (1) {
        R1 = 0;
        R2 = 1;
        R3 = 1;
        R4 = 1;

        if (C1 == 0) {
            delay(1);
            if (C1 == 0) {
                Led ^= 1;
                lcd_data('1');
                while (C1 == 0);
            }
        }
        if (C2 == 0) {
            delay(1);
            if (C2 == 0) {
                Led ^= 1;
                lcd_data('2');
                while (C2 == 0);
            }
        }
        if (C3 == 0) {
            delay(1);
            if (C3 == 0) {
                Led ^= 1;
                lcd_data('3');
                while (C3 == 0);
            }
        }
        if (C4 == 0) {
            delay(1);
            if (C4 == 0) {
                Led ^= 1;
                lcd_data('4');
                while (C4 == 0);
            }
        }
        R1 = 1;
        R2 = 0;
        R3 = 1;
        R4 = 1;
        if (C1 == 0) {
            delay(1);
            if (C1 == 0) {
                Led ^= 1;
                lcd_data('5');
                while (C1 == 0);
            }
        }
        if (C2 == 0) {
            delay(1);
            if (C2 == 0) {
                Led ^= 1;
                lcd_data('6');
                while (C2 == 0);
            }
        }
        if (C3 == 0) {
            delay(1);
            if (C3 == 0) {
                Led ^= 1;
                lcd_data('7');
                while (C3 == 0);
            }
        }
        if (C4 == 0) {
            delay(1);
            if (C4 == 0) {
                Led ^= 1;
                lcd_data('8');
                while (C4 == 0);
            }
        }
        R1 = 1;
        R2 = 1;
        R3 = 0;
        R4 = 1;
        if (C1 == 0) {
            delay(1);
            if (C1 == 0) {
                Led ^= 1;
                lcd_data('9');
                while (C1 == 0);
            }
        }
        if (C2 == 0) {
            delay(1);
            if (C2 == 0) {
                Led ^= 1;
                lcd_data('A');
                while (C2 == 0);
            }
        }
        if (C3 == 0) {
            delay(1);
            if (C3 == 0) {
                Led ^= 1;
                lcd_data('B');
                while (C3 == 0);
            }
        }
        if (C4 == 0) {
            delay(1);
            if (C4 == 0) {
                Led ^= 1;
                lcd_data('C');
                while (C4 == 0);
            }
        }
        R1 = 1;
        R2 = 1;
        R3 = 1;
        R4 = 0;
        if (C1 == 0) {
            delay(1);
            if (C1 == 0) {
                Led ^= 1;
                lcd_data('D');
                while (C1 == 0);
            }
        }
        if (C2 == 0) {
            delay(1);
            if (C2 == 0) {
                Led ^= 1;
                lcd_data('E');
                while (C2 == 0);
            }
        }
        if (C3 == 0) {
            delay(1);
            if (C3 == 0) {
                Led ^= 1;
                lcd_data('F');
                while (C3 == 0);
            }
        }
        if (C4 == 0) {
            delay(1);
            if (C4 == 0) {
                Led ^= 1;
                lcd_data('0');
                while (C4 == 0);
            }
        }
    }
    return;
}
