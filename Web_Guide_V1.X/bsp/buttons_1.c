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

#include "buttons.h"

/*** Button Definitions *********************************************/
//      S1  is MCLR button
#define INPUT_1_PORT  PORTDbits.RD13
#define INPUT_2_PORT  PORTDbits.RD12
#define INPUT_3_PORT  PORTDbits.RD11       //Overlaps with D10
#define INPUT_4_PORT  PORTDbits.RD10
#define INPUT_5_PORT  PORTDbits.RD9
#define INPUT_6_PORT  PORTDbits.RD8
#define INPUT_7_PORT  PORTDbits.RD15
#define INPUT_8_PORT  PORTDbits.RD14

#define INPUT_1_TRIS  TRISDbits.TRISD13
#define INPUT_2_TRIS  TRISDbits.TRISD12
#define INPUT_3_TRIS  TRISDbits.TRISD11
#define INPUT_4_TRIS  TRISDbits.TRISD10
#define INPUT_5_TRIS  TRISDbits.TRISD9
#define INPUT_6_TRIS  TRISDbits.TRISD8
#define INPUT_7_TRIS  TRISDbits.TRISD15
#define INPUT_8_TRIS  TRISDbits.TRISD14

//#define INPUT_1_ANSEL ANSDbits.ANSD13
//#define INPUT_2_ANSEL ANSDbits.ANSD12
//#define INPUT_3_ANSEL ANSDbits.ANSD11
//#define INPUT_4_ANSEL ANSDbits.ANSD10
//#define INPUT_5_ANSEL ANSDbits.ANSD9
//#define INPUT_6_ANSEL ANSDbits.ANSD8
//#define INPUT_7_ANSEL ANSDbits.ANSD15
//#define INPUT_8_ANSEL ANSDbits.ANSD14

//      S4_ANSEL D13 doesn't have an ANSEL

//#define BUTTON_PRESSED      0
//#define BUTTON_NOT_PRESSED  1
//
//#define PIN_INPUT           1
//#define PIN_OUTPUT          0
//
//#define ANALOG      1
//#define DIGITAL     0
///*********************************************************************
// * Function: bool BUTTON_IsPressed(BUTTON button);
// *
// * Overview: Returns the current state of the requested button
// *
// * PreCondition: button configured via BUTTON_SetConfiguration()
// *
// * Input: BUTTON button - enumeration of the buttons available in
// *        this demo.  They should be meaningful names and not the names
// *        of the buttons on the silk-screen on the board (as the demo
// *        code may be ported to other boards).
// *         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
// *
// * Output: true if pressed; false if not pressed.
// *
// ********************************************************************/
//bool BUTTON_IsPressed ( BUTTON button )
//{
//    switch(button)
//    {
//        case BUTTON_S3:
//            return ( (S3_PORT == BUTTON_PRESSED) ? true : false);
//
//        case BUTTON_S6:
//            return ( (S6_PORT == BUTTON_PRESSED) ? true : false);
//
//        case BUTTON_S5:
//            return ( ( S5_PORT == BUTTON_PRESSED ) ? true : false ) ;
//
//        case BUTTON_S4:
//            return ( ( S4_PORT == BUTTON_PRESSED ) ? true : false ) ;
//
//        default:
//            return false;
//    }
//    
//    return false;
//}
//
///*********************************************************************
//* Function: void BUTTON_Enable(BUTTON button);
//*
//* Overview: Returns the current state of the requested button
//*
//* PreCondition: button configured via BUTTON_SetConfiguration()
//*
//* Input: BUTTON button - enumeration of the buttons available in
//*        this demo.  They should be meaningful names and not the names
//*        of the buttons on the silk-screen on the board (as the demo
//*        code may be ported to other boards).
//*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
//*
//* Output: None
//*
//********************************************************************/
//void BUTTON_Enable(BUTTON button)
//{
//    switch(button)
//    {
//        case BUTTON_S3:
//            S3_TRIS = PIN_INPUT ;
//            S3_ANSEL = DIGITAL ;
//            break ;
//
//        case BUTTON_S6:
//            S6_TRIS = PIN_INPUT;
//            S6_ANSEL = DIGITAL ;
//            break;
//
//        case BUTTON_S5:
//            S5_TRIS = PIN_INPUT ;
//            S5_ANSEL = DIGITAL ;
//            break ;
//
//        case BUTTON_S4:
//            S4_TRIS = PIN_INPUT ;
//            //No ANSEL required for D13
//            break ;
//
//        default:
//            break ;
//    }
//}

#define INPUT_DETECTED      1
#define INPUT_NOT_DETECTED  0

#define PIN_INPUT           1
#define PIN_OUTPUT          0

#define ANALOG      1
#define DIGITAL     0
/*********************************************************************
 * Function: bool BUTTON_IsPressed(BUTTON button);
 *
 * Overview: Returns the current state of the requested button
 *
 * PreCondition: button configured via BUTTON_SetConfiguration()
 *
 * Input: BUTTON button - enumeration of the buttons available in
 *        this demo.  They should be meaningful names and not the names
 *        of the buttons on the silk-screen on the board (as the demo
 *        code may be ported to other boards).
 *         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
 *
 * Output: true if pressed; false if not pressed.
 *
 ********************************************************************/
bool INPUT_Isdetected ( INPUT input )
{
    switch(input)
    {
        case INPUT_1:
            return ( (INPUT_1_PORT == INPUT_DETECTED) ? true : false);
            
        case INPUT_2:
            return ( (INPUT_2_PORT == INPUT_DETECTED) ? true : false);
            
        case INPUT_3:
            return ( (INPUT_3_PORT == INPUT_DETECTED) ? true : false);
            
        case INPUT_4:
            return ( (INPUT_4_PORT == INPUT_DETECTED) ? true : false);
            
        case INPUT_5:
            return ( (INPUT_5_PORT == INPUT_DETECTED) ? true : false);
            
        case INPUT_6:
            return ( (INPUT_6_PORT == INPUT_DETECTED) ? true : false);
            
        case INPUT_7:
            return ( (INPUT_7_PORT == INPUT_DETECTED) ? true : false);
            
        case INPUT_8:
            return ( (INPUT_8_PORT == INPUT_DETECTED) ? true : false);

        default:
            return false;
    }
    
    return false;
}

/*********************************************************************
* Function: void BUTTON_Enable(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
* PreCondition: button configured via BUTTON_SetConfiguration()
*
* Input: BUTTON button - enumeration of the buttons available in
*        this demo.  They should be meaningful names and not the names
*        of the buttons on the silk-screen on the board (as the demo
*        code may be ported to other boards).
*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
*
* Output: None
*
********************************************************************/
void INPUT_Enable(INPUT input)

{
    switch(input)
    {
        case INPUT_1:
            INPUT_1_TRIS = PIN_INPUT ;
//            INPUT_1_ANSEL = DIGITAL ;
            break ;
            
        case INPUT_2:
            INPUT_2_TRIS = PIN_INPUT ;
//            INPUT_2_ANSEL = DIGITAL ;
            break ;
            
        case INPUT_3:
            INPUT_3_TRIS = PIN_INPUT ;
//            INPUT_3_ANSEL = DIGITAL ;
            break ;
            
        case INPUT_4:
            INPUT_4_TRIS = PIN_INPUT ;
//            INPUT_4_ANSEL = DIGITAL ;
            break ;
            
        case INPUT_5:
            INPUT_5_TRIS = PIN_INPUT ;
//            INPUT_5_ANSEL = DIGITAL ;
            break ;
            
        case INPUT_6:
            INPUT_6_TRIS = PIN_INPUT ;
//            INPUT_6_ANSEL = DIGITAL ;
            break ;
            
        case INPUT_7:
            INPUT_7_TRIS = PIN_INPUT ;
//            INPUT_7_ANSEL = DIGITAL ;
            break ;
            
        case INPUT_8:
            INPUT_8_TRIS = PIN_INPUT ;
//            INPUT_8_ANSEL = DIGITAL ;
            break ;

        default:
            break ;
    }
}
