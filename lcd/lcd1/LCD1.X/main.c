/* 
 * File:   main.c
 * Author: EL Houssine ADILE
 *
 * Created on 30 mars 2014, 21:40
 */

/*
 * Includes
 */
#include <plib/delays.h>
#include <xc.h>
#include <pic18f4550.h>
#include "lcd.h"

/*
 * Configs
 */


/*
 * Defines
 */
#define _XTAL_FREQ 16000000


/*
 * Variables
 */



/*
 * Prototypes
 */
void DelayFor18TCY(void);
void DelayPORXLCD(void);
void DelayXLCD(void);
void init(void);

/*
 * 
 */
void main() {
    // Configurer les pins
    init();   
    
    // Demarrer le LCD
    OpenXLCD( FOUR_BIT & LINES_5X7 );
    while(BusyXLCD());

    // Configurer le LCD
    WriteCmdXLCD( CURSOR_OFF );
    WriteCmdXLCD( BLINK_OFF );
    WriteCmdXLCD( SHIFT_DISP_LEFT );
    
    // Ecrire sur la ligne 1
    char mybuff [20];
    putrsXLCD( "Asalamo" );
    putsXLCD( mybuff );

    // Ecrire sur la ligne 1
    while(BusyXLCD());
    SetDDRamAddr( 0x40 );
    char mybuff [20];
    putrsXLCD( "3alaykom");
    putsXLCD( mybuff );
}


void init(void) {
    LATB=0;
    TRISB=0;   
}


void DelayFor18TCY(void) {
    __delay_ms(18);
}
void DelayPORXLCD(void){
    __delay_ms(15);
}
void DelayXLCD(void){
    __delay_ms(5);
}