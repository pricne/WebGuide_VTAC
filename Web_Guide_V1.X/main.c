/*****************************************************************
 *  Date:16/04/2021
 *  By: Prince
 *  Project Name: Web Guide
 *  Discription: 8 Digital Input,
 *               8 Digital Output, 
 *               8 Status LED Output, 
 *               1 Indicator LED Output, 
 *               1 Power failure Detection Input,
 *               3*2 Keypad, 
 *               128*64 Graphic LCD 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

//#include "bsp/adc.h"
//#include "bsp/lcd.h"
#include "bsp/timer_1ms.h"
#include "bsp/buttons.h"
#include "bsp/leds.h"
//#include "bsp/rtcc.h"
#include "bsp/Digital_Output.h"
 
#include "io_mapping.h"
#include "delay.h"
#include "generic.h"

//
// *****************************************************************************
// *****************************************************************************
// Section: File Scope Variables and Functions
// *****************************************************************************
// *****************************************************************************
extern void SYS_Initialize ( void ) ;
static void BlinkAliveEventHandler( void );
static void ScreenUpdateEventHandler( void );

//static RTCC_DATETIME time;
//static RTCC_DATETIME lastTime = {0};
//static volatile bool toggleBlinkAlive = false;
//static volatile bool allowScreenUpdate = true;

#define MEMCMP_VALUES_IDENTICAL 0

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
int main ( void )
{
//    uint16_t adcResult;
//    uint16_t lastAdcResult = 0xFFFF;
    
    /* Call the System Initialize routine*/
    SYS_Initialize ( );
    
    /* To determine how the LED and Buttons are mapped to the actual board
     * features, please see io_mapping.h. */
//    LED_Enable ( LED_BLINK_ALIVE );
//    LED_Enable ( LED_BUTTON_PRESSED );
    LED_Enable ( FRD ); //working
    LED_Enable ( REV ); //working
    LED_Enable ( Limit1 ); //working
    LED_Enable ( Limit2 ); //working
    LED_Enable ( Manual ); //working
    LED_Enable ( Auto ); //working
    LED_Enable ( Start ); //working
    LED_Enable ( Center ); //working
    
    Output_Enable(Motor_FRD);//working
    Output_Enable(Motor_REV);//working
    Output_Enable(Buzzer);//working
    Output_Enable(OP4);//working
    Output_Enable(OP5);//working
    Output_Enable(OP6);//working
    Output_Enable(OP7);//working
    Output_Enable(OP8);//working
    

    INPUT_Enable ( Sensor_1 );//working
    INPUT_Enable ( Sensor_2 );//working
    INPUT_Enable ( Travel_Limit_1 );//working
    INPUT_Enable ( Travel_Limit_2 );//working
    INPUT_Enable ( IP5 );//working
    INPUT_Enable ( IP6 );//working
    INPUT_Enable ( IP7 );//working
    INPUT_Enable ( IP8 );//working
    
    
    /* Get a timer event once every 100ms for the blink alive. */
//    TIMER_SetConfiguration ( TIMER_CONFIGURATION_1MS );
//    TIMER_RequestTick( &BlinkAliveEventHandler, 500 );
//    TIMER_RequestTick( &ScreenUpdateEventHandler, 170 );
    
    /* The TIMER_1MS configuration should come before the RTCC initialization as
     * there are some processor modules that require the TIMER_1MS module to be
     * configured before the RTCC module, as the RTCC module is emulated using
     * the TIMER_1MS module. */
//    time.bcdFormat = false;
//    lastTime.bcdFormat = false;
//    RTCC_BuildTimeGet( &time );
//    RTCC_Initialize( &time );
//    memset(&lastTime,0,sizeof(lastTime)); 

//    ADC_SetConfiguration ( ADC_CONFIGURATION_DEFAULT );
//    ADC_ChannelEnable ( ADC_CHANNEL_POTENTIOMETER );
    
    /* Clear the screen */
//    printf( "\f" );   
    
    while ( 1 )
    {
        LED_On( FRD );
//        LED_On( REV );
//        LED_On( Limit1 );
//        LED_On( Limit2 );
//        LED_On( Manual );
//        LED_On( Auto );
//        LED_On( Start );
//        LED_On( Center );
        
//        Output_On(Motor_FRD);
//        Output_On(Motor_REV);
//        Output_On(Buzzer);
//        Output_On(OP4);
//        Output_On(OP5);
//        Output_On(OP6);
//        Output_On(OP7);
//        Output_On(OP8);
//        /* To determine how the LED and Buttons are mapped to the actual board
//         * features, please see io_mapping.h. */
//        if(INPUT_Isdetected( Sensor_1 ) == true)
//        {
//            LED_On( FRD );
//        }
//        else
//        {
//            LED_Off( FRD );
//        }
//        
//        if(INPUT_Isdetected( Sensor_2 ) == true)
//        {
//            LED_On( FRD );
//        }
//        else
//        {
//            LED_Off( FRD );
//        }
        
//        if(INPUT_Isdetected( Travel_Limit_1 ) == true)
//        {
//            LED_On( FRD );
//        }
//        else
//        {
//            LED_Off( FRD );
//        }
//        
//        if(INPUT_Isdetected( Travel_Limit_2 ) == true)
//        {
//            LED_On( FRD );
//        }
//        else
//        {
//            LED_Off( FRD );
//        }
//        
//        if(INPUT_Isdetected( IP5 ) == true)
//        {
//            LED_On( FRD );
//        }
//        else
//        {
//            LED_Off( FRD );
//        }
//        
//        if(INPUT_Isdetected( IP6 ) == true)
//        {
//            LED_On( FRD );
//        }
//        else
//        {
//            LED_Off( FRD );
//        }
//        
//        if(INPUT_Isdetected( IP7 ) == true)
//        {
//            LED_On( FRD );
//        }
//        else
//        {
//            LED_Off( FRD );
//        }
//        
//        if(INPUT_Isdetected( IP8 ) == true)
//        {
//            LED_On( FRD );
//        }
//        else
//        {
//            LED_Off( FRD );
//        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Previous Code        
//        adcResult = ADC_Read10bit( ADC_CHANNEL_POTENTIOMETER );

//        RTCC_TimeGet( &time );
        
        //Only print if the ADC value or time has changed since the last time 
        // around the loop and we haven't updated recently too recently.
//        if(allowScreenUpdate == true)
//        {
//            if( (adcResult != lastAdcResult) ||
//                (memcmp(&time, &lastTime, sizeof(time)) != MEMCMP_VALUES_IDENTICAL) )
//            {                  
//                //Either ADC or time has changed, and the screen update refresh
//                // limit has expired, update the screen.
//                allowScreenUpdate = false;
//                
//                printf( "Time %02d:%02d:%02d   Pot = %4d\r\n", 
//                        time.hour, 
//                        time.minute, 
//                        time.second, 
//                        adcResult
//                      );
//
//                lastAdcResult = adcResult;
//                memcpy(&lastTime, &time, sizeof(time));
//            }
//        }

//        if(toggleBlinkAlive == true)
//        {
//            LED_Toggle( FRD );
//            LED_Toggle( REV );
//            LED_Toggle( Limit1 );
//            LED_Toggle( Limit2 );
//            LED_Toggle( Manual );
//            LED_Toggle( Auto );
//            LED_Toggle( Start );
//            LED_Toggle( Center );
//            toggleBlinkAlive = false;
//        }
//        
    }
}

static void BlinkAliveEventHandler(void)
{    
//    toggleBlinkAlive = true;
}

static void ScreenUpdateEventHandler(void)
{
//    allowScreenUpdate = true;
}

