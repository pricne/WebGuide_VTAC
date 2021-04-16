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

#include "bsp/Digital_Input.h"
#include "bsp/leds.h"

//#define LED_BLINK_ALIVE LED_D3
//#define LED_BUTTON_PRESSED LED_D4

/*Explorer 16/32 LED pin Map*/
//#define D3 LED_D3
//#define D4 LED_D4
//#define D5 LED_D5
//#define D6 LED_D6
//#define D7 LED_D7
//#define D8 LED_D8
//#define D9 LED_D9
//#define D10 LED_D10

/*Web Guide LED pin Map*/
#define FRD LED_1 //pin84-RD7
#define REV LED_2 //pin83-RD6
#define Limit1 LED_3 //pin82-RD5
#define Limit2 LED_4 //pin81-RD4
#define Manual LED_5 //pin78-RD3
#define Auto LED_6 //pin77-RD2
#define Start LED_7 //pin76-RD1
#define Center LED_8 //pin67-RA15
//
///*Web Guide Input pin Map*/
//#define IP1 LED_D3 //pin80-RD13
//#define IP2 LED_D4 //pin79-RD12
//#define IP3 LED_D5 //pin71-RD11
//#define IP4 LED_D6 //pin70-RD10
//#define IP5 LED_D7 //pin69-RD09
//#define IP6 LED_D8 //pin68-RD08
//#define IP7 LED_D9 //pin48-RD15
//#define IP8 LED_D10 //pin47-RD14
//
///*Web Guide Output pin Map*/
#define Motor_FRD OUTPUT_1 //pin93-RE0
#define Motor_REV OUTPUT_2 //pin94-RE1
#define Buzzer OUTPUT_3 //pin98-RE2
#define OP4 OUTPUT_4 //pin99-RE3
#define OP5 OUTPUT_5 //pin100-RE4
#define OP6 OUTPUT_6 //pin3-RE5
#define OP7 OUTPUT_7 //pin4-RE6
#define OP8 OUTPUT_8 //pin5-RE7


#define Sensor_1 INPUT_1
#define Sensor_2 INPUT_2
#define Travel_Limit_1 INPUT_3
#define Travel_Limit_2 INPUT_4
#define IP5 INPUT_5
#define IP6 INPUT_6
#define IP7 INPUT_7
#define IP8 INPUT_8
