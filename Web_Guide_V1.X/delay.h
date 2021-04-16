// Documentation for this file. If the \file tag isn't present,
// this file won't be documented.
#ifndef DELAY_H
#define DELAY_H

#ifndef DEBOUNCE_DLY
#define DEBOUNCE_DLY  15   //in milliseconds
#endif
#define FCY 16000000UL
#define CYCLES_PER_MS ((uint32)(FCY * 0.001))

#define CYCLES_PER_US ((uint32)(FCY * 0.000001))

//#include "pic24_util.h"  // Need u32_heartbeatCount
#include <libpic30.h>    // Has __delay32
#include "generic.h"

uint32 u32_heartbeatCount; 

inline static void delayAndUpdateHeartbeatCount(uint32 u32_cyc) {
  __delay32(u32_cyc);
  u32_heartbeatCount += (u32_cyc >> 4);
//  doHeartbeat();
}

#define DELAY_MS(ms)  delayAndUpdateHeartbeatCount(CYCLES_PER_MS * ((uint32) ms));

#define DELAY_US(us)  delayAndUpdateHeartbeatCount(CYCLES_PER_US * ((uint32) us));
 
#endif