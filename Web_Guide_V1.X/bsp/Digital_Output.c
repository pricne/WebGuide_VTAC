/*******************************************************************************
Copyright 2016 Microchip Technology Inc. (www.microchip.com)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*******************************************************************************/

#include <xc.h>

#include <stdbool.h>

#include "Digital_Output.h"
/*Port A*/
//#define _LAT      LATAbits.LATA0 //Pin17
//#define _LAT      LATAbits.LATA1 //Pin38
//#define _LAT      LATAbits.LATA2 //Pin58
//#define _LAT      LATAbits.LATA3 //Pin59
//#define _LAT      LATAbits.LATA4 //Pin60
//#define _LAT      LATAbits.LATA5 //Pin61
//#define _LAT      LATAbits.LATA6 //Pin91
//#define _LAT     LATAbits.LATA7 //Pin92      //Overlaps with S5
//#define _LAT     LATAbits.LATA9 //Pin28
//#define _LAT     LATAbits.LATA10 //Pin29
//#define _LAT     LATAbits.LATA14 //Pin66
//#define LED_8_LAT     LATAbits.LATA15 //Pin67
//
//#define _TRIS     TRISAbits.TRISA0
//#define LED_D4_TRIS     TRISAbits.TRISA1
//#define LED_D5_TRIS     TRISAbits.TRISA2
//#define LED_D6_TRIS     TRISAbits.TRISA3
//#define LED_D7_TRIS     TRISAbits.TRISA4
//#define LED_D8_TRIS     TRISAbits.TRISA5
//#define LED_D9_TRIS     TRISAbits.TRISA6
//#define LED_D10_TRIS    TRISAbits.TRISA7
//#define LED_D10_TRIS    TRISAbits.TRISA9
//#define LED_D10_TRIS    TRISAbits.TRISA10
//#define LED_D10_TRIS    TRISAbits.TRISA14
//#define LED_8_TRIS    TRISAbits.TRISA15
/*Port B*/
//#define LED_D3_LAT      LATBbits.LATB0 //Pin25
//#define LED_D4_LAT      LATBbits.LATB1 //Pin24
//#define LED_D5_LAT      LATBbits.LATB2 //Pin23
//#define LED_D6_LAT      LATBbits.LATB3 //Pin22
//#define LED_D7_LAT      LATBbits.LATB4 //Pin21
//#define LED_D8_LAT      LATBbits.LATB5 //Pin20
//#define LED_D9_LAT      LATBbits.LATB6 //Pin26
//#define LED_D10_LAT     LATBbits.LATB7 //Pin27
//#define LED_D10_LAT     LATBbits.LATB8 //Pin32
//#define LED_D10_LAT     LATBbits.LATB9 //Pin33
//#define LED_D10_LAT     LATBbits.LATB10 //Pin34
//#define LED_D10_LAT     LATBbits.LATB11 //Pin35
//#define LED_D10_LAT     LATBbits.LATB12 //Pin41
//#define LED_D10_LAT     LATBbits.LATB13 //Pin42
//#define LED_D10_LAT     LATBbits.LATB14 //Pin43
//#define LED_D10_LAT     LATBbits.LATB15 //Pin44
//
//#define LED_D3_TRIS     TRISBbits.TRISB0
//#define LED_D4_TRIS     TRISBbits.TRISB1
//#define LED_D5_TRIS     TRISBbits.TRISB2
//#define LED_D6_TRIS     TRISBbits.TRISB3
//#define LED_D7_TRIS     TRISBbits.TRISB4
//#define LED_D8_TRIS     TRISBbits.TRISB5
//#define LED_D9_TRIS     TRISBbits.TRISB6
//#define LED_D10_TRIS    TRISBbits.TRISB7
//#define LED_D10_TRIS    TRISBbits.TRISB8
//#define LED_D10_TRIS    TRISBbits.TRISB9
//#define LED_D10_TRIS    TRISBbits.TRISB10
//#define LED_D10_TRIS    TRISBbits.TRISB11
//#define LED_D10_TRIS    TRISBbits.TRISB12
//#define LED_D10_TRIS    TRISBbits.TRISB13
//#define LED_D10_TRIS    TRISBbits.TRISB14
//#define LED_D10_TRIS    TRISBbits.TRISB15
/*Port C*/
//#define LED_D4_LAT      LATCbits.LATC1 //pin6
//#define LED_D5_LAT      LATCbits.LATC2 //pin7
//#define LED_D6_LAT      LATCbits.LATC3 //pin8
//#define LED_D7_LAT      LATCbits.LATC4 //pin9
//#define LED_D8_LAT      LATCbits.LATC12 //pin63
//#define LED_D9_LAT      LATCbits.LATC13 //pin73
//#define LED_D10_LAT     LATCbits.LATC14 //pin74
//#define LED_D10_LAT     LATCbits.LATC15 //pin64
//
//#define LED_D3_TRIS     TRISCbits.TRISC1
//#define LED_D3_TRIS     TRISCbits.TRISC2
//#define LED_D3_TRIS     TRISCbits.TRISC3
//#define LED_D3_TRIS     TRISCbits.TRISC4
//#define LED_D3_TRIS     TRISCbits.TRISC12
//#define LED_D3_TRIS     TRISCbits.TRISC13
//#define LED_D3_TRIS     TRISCbits.TRISC14
//#define LED_D3_TRIS     TRISCbits.TRISC15

/*Port D*/
//#define LED_D3_LAT      LATDbits.LATD0 //Pin72
//#define LED_7_LAT      LATDbits.LATD1 //Pin76
//#define LED_6_LAT      LATDbits.LATD2 //Pin77
//#define LED_5_LAT      LATDbits.LATD3 //Pin78
//#define LED_4_LAT      LATDbits.LATD4 //Pin81
//#define LED_3_LAT      LATDbits.LATD5 //Pin82
//#define LED_2_LAT      LATDbits.LATD6 //Pin83
//#define LED_1_LAT      LATDbits.LATD7 //Pin84
//#define LED_D3_LAT      LATDbits.LATD8 //Pin68
//#define LED_D3_LAT      LATDbits.LATD9 //Pin69
//#define LED_D3_LAT      LATDbits.LATD10//Pin70
//#define LED_D3_LAT      LATDbits.LATD11//Pin71
//#define LED_D3_LAT      LATDbits.LATD12//Pin79
//#define LED_D3_LAT      LATDbits.LATD13//Pin80
//#define LED_D3_LAT      LATDbits.LATD14//Pin47
//#define LED_D3_LAT      LATDbits.LATD15//Pin48
//
//#define LED_D3_TRIS     TRISDbits.TRISD0
//#define LED_7_TRIS     TRISDbits.TRISD1
//#define LED_6_TRIS     TRISDbits.TRISD2
//#define LED_5_TRIS     TRISDbits.TRISD3
//#define LED_4_TRIS     TRISDbits.TRISD4
//#define LED_3_TRIS     TRISDbits.TRISD5
//#define LED_2_TRIS     TRISDbits.TRISD6
//#define LED_1_TRIS     TRISDbits.TRISD7
//#define LED_D3_TRIS     TRISDbits.TRISD8
//#define LED_D3_TRIS     TRISDbits.TRISD9
//#define LED_D3_TRIS     TRISDbits.TRISD10
//#define LED_D3_TRIS     TRISDbits.TRISD11
//#define LED_D3_TRIS     TRISDbits.TRISD12
//#define LED_D3_TRIS     TRISDbits.TRISD13
//#define LED_D3_TRIS     TRISDbits.TRISD14
//#define LED_D3_TRIS     TRISDbits.TRISD15

/*Port E*/
#define OUTPUT_1_LAT      LATEbits.LATE0 //pin93
#define OUTPUT_2_LAT      LATEbits.LATE1 //pin94
#define OUTPUT_3_LAT      LATEbits.LATE2 //pin98
#define OUTPUT_4_LAT      LATEbits.LATE3 //pin99
#define OUTPUT_5_LAT      LATEbits.LATE4 //pin100
#define OUTPUT_6_LAT      LATEbits.LATE5 //pin3
#define OUTPUT_7_LAT      LATEbits.LATE6 //pin4
#define OUTPUT_8_LAT      LATEbits.LATE7 //pin5
//#define LED_D3_LAT      LATEbits.LATE8 //pin18
//#define LED_D3_LAT      LATEbits.LATE9 //pin19
//
#define OUTPUT_1_TRIS     TRISEbits.TRISE0
#define OUTPUT_2_TRIS     TRISEbits.TRISE1
#define OUTPUT_3_TRIS     TRISEbits.TRISE2
#define OUTPUT_4_TRIS     TRISEbits.TRISE3
#define OUTPUT_5_TRIS     TRISEbits.TRISE4
#define OUTPUT_6_TRIS     TRISEbits.TRISE5
#define OUTPUT_7_TRIS     TRISEbits.TRISE6
#define OUTPUT_8_TRIS     TRISEbits.TRISE7
//#define LED_D3_TRIS     TRISEbits.TRISE8
//#define LED_D3_TRIS     TRISEbits.TRISE9

/*Port F*/
//#define LED_D3_LAT      LATFbits.LATF0 //pin87
//#define LED_D3_LAT      LATFbits.LATF1 //pin88
//#define LED_D3_LAT      LATFbits.LATF2 //pin52
//#define LED_D3_LAT      LATFbits.LATF3 //pin51
//#define LED_D3_LAT      LATFbits.LATF4 //pin49
//#define LED_D3_LAT      LATFbits.LATF5 //pin50
//#define LED_D3_LAT      LATFbits.LATF7 //pin54
//#define LED_D3_LAT      LATFbits.LATF8 //pin53
//#define LED_D3_LAT      LATFbits.LATF12 //pin40
//#define LED_D3_LAT      LATFbits.LATF13 //pin39
//
//#define LED_D3_TRIS     TRISFbits.TRISF0
//#define LED_D3_TRIS     TRISFbits.TRISF1
//#define LED_D3_TRIS     TRISFbits.TRISF2
//#define LED_D3_TRIS     TRISFbits.TRISF3
//#define LED_D3_TRIS     TRISFbits.TRISF4
//#define LED_D3_TRIS     TRISFbits.TRISF5
//#define LED_D3_TRIS     TRISFbits.TRISF7
//#define LED_D3_TRIS     TRISFbits.TRISF8
//#define LED_D3_TRIS     TRISFbits.TRISF12
//#define LED_D3_TRIS     TRISFbits.TRISF13

/*Port G*/
//#define LED_D3_LAT      LATGbits.LATG0 //pin90
//#define LED_D3_LAT      LATGbits.LATG1 //pin89
//#define LED_D3_LAT      LATGbits.LATG2 //pin57
//#define LED_D3_LAT      LATGbits.LATG3 //pin56
//#define LED_D3_LAT      LATGbits.LATG6 //pin10
//#define LED_D3_LAT      LATGbits.LATG7 //pin11
//#define LED_D3_LAT      LATGbits.LATG8 //pin12
//#define LED_D3_LAT      LATGbits.LATG9 //pin14
//#define LED_D3_LAT      LATGbits.LATG12//pin96
//#define LED_D3_LAT      LATGbits.LATG13//pin97
//#define LED_D3_LAT      LATGbits.LATG14//pin95
//#define LED_D3_LAT      LATGbits.LATG15//pin1
//
//#define LED_D3_TRIS     TRISGbits.TRISG0
//#define LED_D3_TRIS     TRISGbits.TRISG1
//#define LED_D3_TRIS     TRISGbits.TRISG2
//#define LED_D3_TRIS     TRISGbits.TRISG3
//#define LED_D3_TRIS     TRISGbits.TRISG6
//#define LED_D3_TRIS     TRISGbits.TRISG7
//#define LED_D3_TRIS     TRISGbits.TRISG8
//#define LED_D3_TRIS     TRISGbits.TRISG9
//#define LED_D3_TRIS     TRISGbits.TRISG12
//#define LED_D3_TRIS     TRISGbits.TRISG13
//#define LED_D3_TRIS     TRISGbits.TRISG14
//#define LED_D3_TRIS     TRISGbits.TRISG15

#define OUTPUT_ON  1
#define OUTPUT_OFF 0

#define PIN_INPUT   1
#define PIN_OUTPUT  0

/*********************************************************************
* Function: void LED_On(LED led);
*
* Overview: Turns requested LED on
*
* PreCondition: LED configured via LED_Configure()
*
* Input: LED led - enumeration of the LEDs available in this
*        demo.  They should be meaningful names and not the names of
*        the LEDs on the silkscreen on the board (as the demo code may
*        be ported to other boards).
*         i.e. - LED_On(LED_CONNECTION_DETECTED);
*
* Output: none
*
********************************************************************/
void Output_On(OUTPUT output)
{
    switch(output)
    {
        case OUTPUT_1:
            OUTPUT_1_LAT = OUTPUT_ON;
            break;

        case OUTPUT_2:
            OUTPUT_2_LAT = OUTPUT_ON;
            break;

        case OUTPUT_3:
            OUTPUT_3_LAT = OUTPUT_ON;
            break;

        case OUTPUT_4:
            OUTPUT_4_LAT = OUTPUT_ON;
            break;

        case OUTPUT_5:
            OUTPUT_5_LAT = OUTPUT_ON;
            break;

        case OUTPUT_6:
            OUTPUT_6_LAT = OUTPUT_ON;
            break;

        case OUTPUT_7:
            OUTPUT_7_LAT = OUTPUT_ON;
            break;

        case OUTPUT_8:
            OUTPUT_8_LAT = OUTPUT_ON;
            break;

        default:
            break;
    }
}

/*********************************************************************
* Function: void LED_Off(LED led);
*
* Overview: Turns requested LED off
*
* PreCondition: LED configured via LEDConfigure()
*
* Input: LED led - enumeration of the LEDs available in this
*        demo.  They should be meaningful names and not the names of
*        the LEDs on the silkscreen on the board (as the demo code may
*        be ported to other boards).
*         i.e. - LED_Off(LED_CONNECTION_DETECTED);
*
* Output: none
*
********************************************************************/
void Output_Off(OUTPUT output)
{
    switch(output)
    {
        case OUTPUT_1:
            OUTPUT_1_LAT = OUTPUT_OFF;
            break ;

        case OUTPUT_2:
            OUTPUT_2_LAT = OUTPUT_OFF;
            break ;

        case OUTPUT_3:
            OUTPUT_3_LAT = OUTPUT_OFF;
            break;

        case OUTPUT_4:
            OUTPUT_4_LAT = OUTPUT_OFF;
            break;

        case OUTPUT_5:
            OUTPUT_5_LAT = OUTPUT_OFF;
            break;

        case OUTPUT_6:
            OUTPUT_6_LAT = OUTPUT_OFF;
            break;

        case OUTPUT_7:
            OUTPUT_7_LAT = OUTPUT_OFF;
            break ;

        case OUTPUT_8:
            OUTPUT_8_LAT = OUTPUT_OFF;
            break ;

        default:
            break;
    }
}

/*********************************************************************
* Function: void LED_Toggle(LED led);
*
* Overview: Toggles the state of the requested LED
*
* PreCondition: LED configured via LEDConfigure()
*
* Input: LED led - enumeration of the LEDs available in this
*        demo.  They should be meaningful names and not the names of
*        the LEDs on the silkscreen on the board (as the demo code may
*        be ported to other boards).
*         i.e. - LED_Toggle(LED_CONNECTION_DETECTED);
*
* Output: none
*
********************************************************************/
void Output_Toggle(OUTPUT output)
{
    switch(output)
    {
        case OUTPUT_1:
            OUTPUT_1_LAT ^= 1;
            break;

        case OUTPUT_2:
            OUTPUT_2_LAT ^= 1;
            break;

        case OUTPUT_3:
            OUTPUT_3_LAT ^= 1;
            break;

        case OUTPUT_4:
            OUTPUT_4_LAT ^= 1;
            break;

        case OUTPUT_5:
            OUTPUT_5_LAT ^= 1;
            break;

        case OUTPUT_6:
            OUTPUT_6_LAT ^= 1;
            break;

        case OUTPUT_7:
            OUTPUT_7_LAT ^= 1;
            break;

        case OUTPUT_8:
            OUTPUT_8_LAT ^= 1;
            break;

        default:
            break;
    }
}

/*********************************************************************
* Function: bool LED_Get(LED led);
*
* Overview: Returns the current state of the requested LED
*
* PreCondition: LED configured via LEDConfigure()
*
* Input: LED led - enumeration of the LEDs available in this
*        demo.  They should be meaningful names and not the names of
*        the LEDs on the silkscreen on the board (as the demo code may
*        be ported to other boards).
*         i.e. - LED_Get(LED_CONNECTION_DETECTED);
*
* Output: true if on, false if off
*
********************************************************************/
bool Output_Get(OUTPUT output)
{
    switch(output)
    {
        case OUTPUT_1:
            return ( (OUTPUT_1_LAT == OUTPUT_ON) ? true : false );

        case OUTPUT_2:
            return ( (OUTPUT_2_LAT == OUTPUT_ON) ? true : false );

        case OUTPUT_3:
            return ( (OUTPUT_3_LAT == OUTPUT_ON) ? true : false );

        case OUTPUT_4:
            return ( (OUTPUT_4_LAT == OUTPUT_ON) ? true : false );

        case OUTPUT_5:
            return ( (OUTPUT_5_LAT == OUTPUT_ON) ? true : false );

        case OUTPUT_6:
            return ( (OUTPUT_6_LAT == OUTPUT_ON) ? true : false );

        case OUTPUT_7:
            return ( (OUTPUT_7_LAT == OUTPUT_ON) ? true : false );

        case OUTPUT_8:
            return ( (OUTPUT_8_LAT == OUTPUT_ON) ? true : false );

        default:
            break;
    }
    return false;
}

/*********************************************************************
* Function: void LED_Enable(LED led);
*
* Overview: Configures the LED for use by the other LED API
*
* PreCondition: none
*
* Input: LED led - enumeration of the LEDs available in this
*        demo.  They should be meaningful names and not the names of
*        the LEDs on the silkscreen on the board (as the demo code may
*        be ported to other boards).
*
* Output: none
*
********************************************************************/
void Output_Enable(OUTPUT output)
{
    switch(output)
    {
        case OUTPUT_1:
            OUTPUT_1_TRIS = PIN_OUTPUT;
            break;

        case OUTPUT_2:
            OUTPUT_2_TRIS = PIN_OUTPUT;
            break;

        case OUTPUT_3:
            OUTPUT_3_TRIS = PIN_OUTPUT;
            break;

        case OUTPUT_4:
            OUTPUT_4_TRIS = PIN_OUTPUT;
            break;

        case OUTPUT_5:
            OUTPUT_5_TRIS = PIN_OUTPUT;
            break;

        case OUTPUT_6:
            OUTPUT_6_TRIS = PIN_OUTPUT;
            break;

        case OUTPUT_7:
            OUTPUT_7_TRIS = PIN_OUTPUT;
            break;

        case OUTPUT_8:
            OUTPUT_8_TRIS = PIN_OUTPUT;
            break ;

        default:
            break;
    }
}

