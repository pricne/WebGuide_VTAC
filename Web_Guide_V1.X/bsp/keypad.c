///*******************************************************************************
//Copyright 2016 Microchip Technology Inc. (www.microchip.com)
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.
//*******************************************************************************/
//
//#include <xc.h>
//
//#include <stdbool.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <stddef.h>
//#include <string.h>
//
//#include "keypad.h"
//#include "../generic.h"
//#include "../delay.h"
//
//#define C0 _RB9
//#define C1 _RB8
//#define C2 _RB7
//#define C3 _RB6
//
//#define R0 _LATB5
//#define R1 _LATB4
//#define R2 _LATB3
//
//#define CONFIG_R0_DIG_OUTPUT() CONFIG_RB5_AS_DIG_OUTPUT()
//#define CONFIG_R1_DIG_OUTPUT() CONFIG_RB4_AS_DIG_OUTPUT()
//#define CONFIG_R2_DIG_OUTPUT() CONFIG_RB3_AS_DIG_OUTPUT()
//
//static inline void CONFIG_COLUMN() 
//{
////    CONFIG_RB9_AS_DIG_INPUT();
////    ENABLE_RB9_PULLUP();
////    CONFIG_RB8_AS_DIG_INPUT();
////    ENABLE_RB8_PULLUP();
////    CONFIG_RB7_AS_DIG_INPUT();
////    ENABLE_RB7_PULLUP();
////    CONFIG_RB6_AS_DIG_INPUT();
////    ENABLE_RB6_PULLUP();
//}
//
//void CONFIG_ROW() 
//{
////   CONFIG_R0_DIG_OUTPUT();
////   CONFIG_R1_DIG_OUTPUT();
////   CONFIG_R2_DIG_OUTPUT();
//}
//
//static inline void DRIVE_ROW_LOW() {
//  R0 = 0;
//  R1 = 0;
//  R2 = 0;
//}
// 
//static inline void DRIVE_ROW_HIGH() {
//  R0 = 1;
//  R1 = 1;
//  R2 = 1;
//}
//
//void configKeypad(void) {
//  CONFIG_ROW();
//  DRIVE_ROW_LOW();
//  CONFIG_COLUMN();
//  DELAY_US(1);     //wait for pullups to stabilize inputs
//}
//
////drive one row low
//void setOneRowLow(uint8 u8_x) {
//  switch (u8_x) {
//    case 0:
//      R0 = 0;
//      R1 = 1;
//      R2 = 1;
//      break;
//    case 1:
//      R0 = 1;
//      R1 = 0;
//      R2 = 1;
//      break;
//    default:
//      R0 = 1;
//      R1 = 1;
//      R2 = 0;
//      break;
//  }
//}
//
//#define NUM_ROWS 3
//#define NUM_COLS 4
//const uint8 au8_keyTable[NUM_ROWS][NUM_COLS] = 
//{ 
//  {'1', '4', '7', '*'},
//  {'2', '5', '8', '0'},
//  {'3', '6', '9', '#'}
//};
//
//#define KEY_PRESSED() (!C0 || !C1 || !C2 || !C3)   //any low
//#define KEY_RELEASED() (C0 && C1 && C2 && C3)  //all high
// 
//uint8 doKeyScan(void) {
//  uint8 u8_row, u8_col;
//  //determine column
//  if (!C0) u8_col = 0;
//  else if (!C1) u8_col = 1;
//  else if (!C2) u8_col = 2;
//  else if (!C3) u8_col = 3;
//  else return('E'); //error
//  //determine row
//  for (u8_row = 0; u8_row < NUM_ROWS; u8_row++) {
//    setOneRowLow(u8_row); //enable one row low
//    if (KEY_PRESSED()) {
//      DRIVE_ROW_LOW(); //return rows to driving low
//      return(au8_keyTable[u8_row][u8_col]);
//    }
//  }
//  DRIVE_ROW_LOW(); //return rows to driving low
//  return('E'); //error
//}
//typedef enum  {
//  STATE_WAIT_FOR_PRESS = 0,
//  STATE_WAIT_FOR_PRESS2,
//  STATE_WAIT_FOR_RELEASE,
//} ISRSTATE;
//
//ISRSTATE e_isrState = STATE_WAIT_FOR_PRESS;
//volatile uint8 u8_newKey = 0;
// 
////Interrupt Service Routine for Timer3
////void _ISR _T3Interrupt (void) {
////  switch (e_isrState) {
////    case STATE_WAIT_FOR_PRESS:
////      if (KEY_PRESSED() && (u8_newKey == 0)) {
////        //ensure that key is sampled low for two consecutive interrupt periods
////        e_isrState = STATE_WAIT_FOR_PRESS2;
////      }
////      break;
////    case STATE_WAIT_FOR_PRESS2:
////      if (KEY_PRESSED()) {
////        // a key is ready
////        u8_newKey = doKeyScan();
////        e_isrState = STATE_WAIT_FOR_RELEASE;
////      } else e_isrState = STATE_WAIT_FOR_PRESS;
////      break;
//// 
////    case STATE_WAIT_FOR_RELEASE:
////      //keypad released
////      if (KEY_RELEASED()) {
////        e_isrState = STATE_WAIT_FOR_PRESS;
////      }
////      break;
////    default:
////     e_isrState = STATE_WAIT_FOR_PRESS;
////      break;
////  }
////  _T3IF = 0;                 //clear the timer interrupt bit
////}
// 
//#define ISR_PERIOD     15      // in ms
//
//void  configTimer3(void) {
////  //ensure that Timer2,3 configured as separate timers.
////  T2CONbits.T32 = 0;     // 32-bit mode off
////  //T3CON set like this for documentation purposes.
////  //could be replaced by T3CON = 0x0020
////  T3CON = T3_OFF | T3_IDLE_CON | T3_GATE_OFF | T3_SOURCE_INT | T3_PS_1_64 ; //results in T3CON= 0x0020
////          
////           
////  PR3 = msToU16Ticks (ISR_PERIOD, getTimerPrescale(T3CONbits)) - 1;
////  TMR3  = 0;                       //clear timer3 value
////  _T3IF = 0;                       //clear interrupt flag
////  _T3IP = 1;                       //choose a priority
////  _T3IE = 1;                       //enable the interrupt
////  T3CONbits.TON = 1;               //turn on the timer
//}
// 
////int main (void) {
//////  configBasic(HELLO_MSG);
////  configKeypad();
////  configTimer3();
////  while (1) {
////    if (u8_newKey) {
//////      outChar(u8_newKey);
////      u8_newKey = 0;
////    }
//////    doHeartbeat();     //ensure that we are alive
////  } // end while (1)
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////
////
/////*** Button Definitions *********************************************/
//////      S1  is MCLR button
////#define INPUT_1_PORT  PORTDbits.RD13
////#define INPUT_2_PORT  PORTDbits.RD12
////#define INPUT_3_PORT  PORTDbits.RD11       //Overlaps with D10
////#define INPUT_4_PORT  PORTDbits.RD10
////#define INPUT_5_PORT  PORTDbits.RD9
////#define INPUT_6_PORT  PORTDbits.RD8
////#define INPUT_7_PORT  PORTDbits.RD15
////#define INPUT_8_PORT  PORTDbits.RD14
////
////#define INPUT_1_TRIS  TRISDbits.TRISD13
////#define INPUT_2_TRIS  TRISDbits.TRISD12
////#define INPUT_3_TRIS  TRISDbits.TRISD11
////#define INPUT_4_TRIS  TRISDbits.TRISD10
////#define INPUT_5_TRIS  TRISDbits.TRISD9
////#define INPUT_6_TRIS  TRISDbits.TRISD8
////#define INPUT_7_TRIS  TRISDbits.TRISD15
////#define INPUT_8_TRIS  TRISDbits.TRISD14
////
//////#define INPUT_1_ANSEL ANSDbits.ANSD13
//////#define INPUT_2_ANSEL ANSDbits.ANSD12
//////#define INPUT_3_ANSEL ANSDbits.ANSD11
//////#define INPUT_4_ANSEL ANSDbits.ANSD10
//////#define INPUT_5_ANSEL ANSDbits.ANSD9
//////#define INPUT_6_ANSEL ANSDbits.ANSD8
//////#define INPUT_7_ANSEL ANSDbits.ANSD15
//////#define INPUT_8_ANSEL ANSDbits.ANSD14
////
//////      S4_ANSEL D13 doesn't have an ANSEL
////
//////#define BUTTON_PRESSED      0
//////#define BUTTON_NOT_PRESSED  1
//////
//////#define PIN_INPUT           1
//////#define PIN_OUTPUT          0
//////
//////#define ANALOG      1
//////#define DIGITAL     0
///////*********************************************************************
////// * Function: bool BUTTON_IsPressed(BUTTON button);
////// *
////// * Overview: Returns the current state of the requested button
////// *
////// * PreCondition: button configured via BUTTON_SetConfiguration()
////// *
////// * Input: BUTTON button - enumeration of the buttons available in
////// *        this demo.  They should be meaningful names and not the names
////// *        of the buttons on the silk-screen on the board (as the demo
////// *        code may be ported to other boards).
////// *         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
////// *
////// * Output: true if pressed; false if not pressed.
////// *
////// ********************************************************************/
//////bool BUTTON_IsPressed ( BUTTON button )
//////{
//////    switch(button)
//////    {
//////        case BUTTON_S3:
//////            return ( (S3_PORT == BUTTON_PRESSED) ? true : false);
//////
//////        case BUTTON_S6:
//////            return ( (S6_PORT == BUTTON_PRESSED) ? true : false);
//////
//////        case BUTTON_S5:
//////            return ( ( S5_PORT == BUTTON_PRESSED ) ? true : false ) ;
//////
//////        case BUTTON_S4:
//////            return ( ( S4_PORT == BUTTON_PRESSED ) ? true : false ) ;
//////
//////        default:
//////            return false;
//////    }
//////    
//////    return false;
//////}
//////
///////*********************************************************************
//////* Function: void BUTTON_Enable(BUTTON button);
//////*
//////* Overview: Returns the current state of the requested button
//////*
//////* PreCondition: button configured via BUTTON_SetConfiguration()
//////*
//////* Input: BUTTON button - enumeration of the buttons available in
//////*        this demo.  They should be meaningful names and not the names
//////*        of the buttons on the silk-screen on the board (as the demo
//////*        code may be ported to other boards).
//////*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
//////*
//////* Output: None
//////*
//////********************************************************************/
//////void BUTTON_Enable(BUTTON button)
//////{
//////    switch(button)
//////    {
//////        case BUTTON_S3:
//////            S3_TRIS = PIN_INPUT ;
//////            S3_ANSEL = DIGITAL ;
//////            break ;
//////
//////        case BUTTON_S6:
//////            S6_TRIS = PIN_INPUT;
//////            S6_ANSEL = DIGITAL ;
//////            break;
//////
//////        case BUTTON_S5:
//////            S5_TRIS = PIN_INPUT ;
//////            S5_ANSEL = DIGITAL ;
//////            break ;
//////
//////        case BUTTON_S4:
//////            S4_TRIS = PIN_INPUT ;
//////            //No ANSEL required for D13
//////            break ;
//////
//////        default:
//////            break ;
//////    }
//////}
////
////#define INPUT_DETECTED      1
////#define INPUT_NOT_DETECTED  0
////
////#define PIN_INPUT           1
////#define PIN_OUTPUT          0
////
////#define ANALOG      1
////#define DIGITAL     0
/////*********************************************************************
//// * Function: bool BUTTON_IsPressed(BUTTON button);
//// *
//// * Overview: Returns the current state of the requested button
//// *
//// * PreCondition: button configured via BUTTON_SetConfiguration()
//// *
//// * Input: BUTTON button - enumeration of the buttons available in
//// *        this demo.  They should be meaningful names and not the names
//// *        of the buttons on the silk-screen on the board (as the demo
//// *        code may be ported to other boards).
//// *         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
//// *
//// * Output: true if pressed; false if not pressed.
//// *
//// ********************************************************************/
////bool INPUT_Isdetected ( INPUT input )
////{
////    switch(input)
////    {
////        case INPUT_1:
////            return ( (INPUT_1_PORT == INPUT_DETECTED) ? true : false);
////            
////        case INPUT_2:
////            return ( (INPUT_2_PORT == INPUT_DETECTED) ? true : false);
////            
////        case INPUT_3:
////            return ( (INPUT_3_PORT == INPUT_DETECTED) ? true : false);
////            
////        case INPUT_4:
////            return ( (INPUT_4_PORT == INPUT_DETECTED) ? true : false);
////            
////        case INPUT_5:
////            return ( (INPUT_5_PORT == INPUT_DETECTED) ? true : false);
////            
////        case INPUT_6:
////            return ( (INPUT_6_PORT == INPUT_DETECTED) ? true : false);
////            
////        case INPUT_7:
////            return ( (INPUT_7_PORT == INPUT_DETECTED) ? true : false);
////            
////        case INPUT_8:
////            return ( (INPUT_8_PORT == INPUT_DETECTED) ? true : false);
////
////        default:
////            return false;
////    }
////    
////    return false;
////}
////
/////*********************************************************************
////* Function: void BUTTON_Enable(BUTTON button);
////*
////* Overview: Returns the current state of the requested button
////*
////* PreCondition: button configured via BUTTON_SetConfiguration()
////*
////* Input: BUTTON button - enumeration of the buttons available in
////*        this demo.  They should be meaningful names and not the names
////*        of the buttons on the silk-screen on the board (as the demo
////*        code may be ported to other boards).
////*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
////*
////* Output: None
////*
////********************************************************************/
////void INPUT_Enable(INPUT input)
////{
////    switch(input)
////    {
////        case INPUT_1:
////            INPUT_1_TRIS = PIN_INPUT ;
//////            INPUT_1_ANSEL = DIGITAL ;
////            break ;
////            
////        case INPUT_2:
////            INPUT_2_TRIS = PIN_INPUT ;
//////            INPUT_2_ANSEL = DIGITAL ;
////            break ;
////            
////        case INPUT_3:
////            INPUT_3_TRIS = PIN_INPUT ;
//////            INPUT_3_ANSEL = DIGITAL ;
////            break ;
////            
////        case INPUT_4:
////            INPUT_4_TRIS = PIN_INPUT ;
//////            INPUT_4_ANSEL = DIGITAL ;
////            break ;
////            
////        case INPUT_5:
////            INPUT_5_TRIS = PIN_INPUT ;
//////            INPUT_5_ANSEL = DIGITAL ;
////            break ;
////            
////        case INPUT_6:
////            INPUT_6_TRIS = PIN_INPUT ;
//////            INPUT_6_ANSEL = DIGITAL ;
////            break ;
////            
////        case INPUT_7:
////            INPUT_7_TRIS = PIN_INPUT ;
//////            INPUT_7_ANSEL = DIGITAL ;
////            break ;
////            
////        case INPUT_8:
////            INPUT_8_TRIS = PIN_INPUT ;
//////            INPUT_8_ANSEL = DIGITAL ;
////            break ;
////
////        default:
////            break ;
////    }
////}
