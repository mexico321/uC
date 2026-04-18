#include <xc.h>
#pragma config WDT = OFF
#pragma config OSC = HS
#pragma config LVP = OFF

#define RS LATDbits.LATD0
#define EN LATDbits.LATD1
#define D4 LATDbits.LATD4
#define D5 LATDbits.LATD5
#define D6 LATDbits.LATD6
#define D7 LATDbits.LATD7

void delay(unsigned long int i){
    i*=360;
    while(i--);
}

void lcd_cmd(unsigned char cmd){
    RS = 0;
    D4 = (cmd >> 4)&1;
    D5 = (cmd >> 5)&1;
    D6 = (cmd >> 6)&1;
    D7 = (cmd >> 7)&1;
    EN = 1;
    delay(10);
    EN = 0;
    D4 = (cmd >> 0)&1;
    D5 = (cmd >> 1)&1;
    D6 = (cmd >> 2)&1;
    D7 = (cmd >> 3)&1;
    EN = 1;
    delay(10);
    EN = 0;
}

void lcd_init(){
    lcd_cmd(0x28);
    delay(1);
    lcd_cmd(0x28);
    delay(1);
    lcd_cmd(0x28);
    delay(1);
    lcd_cmd(0x0F);
    delay(1);
    lcd_cmd(0x01);
    delay(1);
}

void lcd_data(unsigned char data){
    RS = 1;
    D4 = (data >> 4)&1;
    D5 = (data >> 5)&1;
    D6 = (data >> 6)&1;
    D7 = (data >> 7)&1;
    EN = 1;
    delay(10);
    EN = 0;
    D4 = (data >> 0)&1;
    D5 = (data >> 1)&1;
    D6 = (data >> 2)&1;
    D7 = (data >> 3)&1;
    EN = 1;
    delay(10);
    EN = 0;
}

void main(void) {
    
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD4 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD7 = 0;
    
    EN = 0;
    lcd_init();
    lcd_cmd(0x80);
    delay(1);
    
    lcd_data('H');
    delay(40);
    lcd_data('I');
    delay(40);
    
    while(1);
    return;
}
