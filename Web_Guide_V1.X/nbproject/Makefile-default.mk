#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Web_Guide_V1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Web_Guide_V1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=bsp/adc.c bsp/rtcc.c bsp/buttons.c bsp/lcd.c bsp/leds.c bsp/lcd_printf.c bsp/timer_1ms.c bsp/Digital_Output.c main.c system.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/bsp/adc.o ${OBJECTDIR}/bsp/rtcc.o ${OBJECTDIR}/bsp/buttons.o ${OBJECTDIR}/bsp/lcd.o ${OBJECTDIR}/bsp/leds.o ${OBJECTDIR}/bsp/lcd_printf.o ${OBJECTDIR}/bsp/timer_1ms.o ${OBJECTDIR}/bsp/Digital_Output.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o
POSSIBLE_DEPFILES=${OBJECTDIR}/bsp/adc.o.d ${OBJECTDIR}/bsp/rtcc.o.d ${OBJECTDIR}/bsp/buttons.o.d ${OBJECTDIR}/bsp/lcd.o.d ${OBJECTDIR}/bsp/leds.o.d ${OBJECTDIR}/bsp/lcd_printf.o.d ${OBJECTDIR}/bsp/timer_1ms.o.d ${OBJECTDIR}/bsp/Digital_Output.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/system.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/bsp/adc.o ${OBJECTDIR}/bsp/rtcc.o ${OBJECTDIR}/bsp/buttons.o ${OBJECTDIR}/bsp/lcd.o ${OBJECTDIR}/bsp/leds.o ${OBJECTDIR}/bsp/lcd_printf.o ${OBJECTDIR}/bsp/timer_1ms.o ${OBJECTDIR}/bsp/Digital_Output.o ${OBJECTDIR}/main.o ${OBJECTDIR}/system.o

# Source Files
SOURCEFILES=bsp/adc.c bsp/rtcc.c bsp/buttons.c bsp/lcd.c bsp/leds.c bsp/lcd_printf.c bsp/timer_1ms.c bsp/Digital_Output.c main.c system.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Web_Guide_V1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ1024GB610
MP_LINKER_FILE_OPTION=,--script=p24FJ1024GB610.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/bsp/adc.o: bsp/adc.c  .generated_files/4477cca93e41100cb7d4a061b21c7909a2a8761.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/adc.o.d 
	@${RM} ${OBJECTDIR}/bsp/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/adc.c  -o ${OBJECTDIR}/bsp/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/adc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/rtcc.o: bsp/rtcc.c  .generated_files/cc57d19758425759e943e9a798a7a6f37499f9a3.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/rtcc.o.d 
	@${RM} ${OBJECTDIR}/bsp/rtcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/rtcc.c  -o ${OBJECTDIR}/bsp/rtcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/rtcc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/buttons.o: bsp/buttons.c  .generated_files/f288bd11a2c4eed6f5b90f483455c58ecac0ff47.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/buttons.o.d 
	@${RM} ${OBJECTDIR}/bsp/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/buttons.c  -o ${OBJECTDIR}/bsp/buttons.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/buttons.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/lcd.o: bsp/lcd.c  .generated_files/b7c2cf4209e77c8ad7fcc886680846b004e4b532.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/lcd.o.d 
	@${RM} ${OBJECTDIR}/bsp/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/lcd.c  -o ${OBJECTDIR}/bsp/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/lcd.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/leds.o: bsp/leds.c  .generated_files/e6f5d9799a083ee91a059fc9aa9b585c58d2c706.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/leds.o.d 
	@${RM} ${OBJECTDIR}/bsp/leds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/leds.c  -o ${OBJECTDIR}/bsp/leds.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/leds.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/lcd_printf.o: bsp/lcd_printf.c  .generated_files/607cd8c94161780cc162a54c765aca5bdeff34c1.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/lcd_printf.o.d 
	@${RM} ${OBJECTDIR}/bsp/lcd_printf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/lcd_printf.c  -o ${OBJECTDIR}/bsp/lcd_printf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/lcd_printf.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/timer_1ms.o: bsp/timer_1ms.c  .generated_files/b3ef2c8dda8c2fde6f27560762e50afeddc9f748.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/bsp/timer_1ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/timer_1ms.c  -o ${OBJECTDIR}/bsp/timer_1ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/timer_1ms.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/Digital_Output.o: bsp/Digital_Output.c  .generated_files/7510158b7a4418d3c52945c841266109885c444d.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/Digital_Output.o.d 
	@${RM} ${OBJECTDIR}/bsp/Digital_Output.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/Digital_Output.c  -o ${OBJECTDIR}/bsp/Digital_Output.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/Digital_Output.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/13effd8cef03f1295e906b3f634de0925ed65411.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/fbee156c7296549464da4d9abb90a86779702e24.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/bsp/adc.o: bsp/adc.c  .generated_files/cb0a35ee4bd18fbb0e7e4a292cbb87cb85249b72.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/adc.o.d 
	@${RM} ${OBJECTDIR}/bsp/adc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/adc.c  -o ${OBJECTDIR}/bsp/adc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/adc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/rtcc.o: bsp/rtcc.c  .generated_files/f7164c3a918db296e78568e1aa0678a2d845b465.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/rtcc.o.d 
	@${RM} ${OBJECTDIR}/bsp/rtcc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/rtcc.c  -o ${OBJECTDIR}/bsp/rtcc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/rtcc.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/buttons.o: bsp/buttons.c  .generated_files/99eb4c8d957f2963376729930a132d1ac235a435.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/buttons.o.d 
	@${RM} ${OBJECTDIR}/bsp/buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/buttons.c  -o ${OBJECTDIR}/bsp/buttons.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/buttons.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/lcd.o: bsp/lcd.c  .generated_files/3822e7d9f05d75c5091c383a5ba418b1c77798c8.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/lcd.o.d 
	@${RM} ${OBJECTDIR}/bsp/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/lcd.c  -o ${OBJECTDIR}/bsp/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/lcd.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/leds.o: bsp/leds.c  .generated_files/b7a79fa4b60b5e3c7d1609b3f97523b1fde0a036.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/leds.o.d 
	@${RM} ${OBJECTDIR}/bsp/leds.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/leds.c  -o ${OBJECTDIR}/bsp/leds.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/leds.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/lcd_printf.o: bsp/lcd_printf.c  .generated_files/b93405599fe4f4e7b2d9f230fef520bf60783168.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/lcd_printf.o.d 
	@${RM} ${OBJECTDIR}/bsp/lcd_printf.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/lcd_printf.c  -o ${OBJECTDIR}/bsp/lcd_printf.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/lcd_printf.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/timer_1ms.o: bsp/timer_1ms.c  .generated_files/d5ba8232d8590f10874a803c4f4946da13e32d70.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/timer_1ms.o.d 
	@${RM} ${OBJECTDIR}/bsp/timer_1ms.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/timer_1ms.c  -o ${OBJECTDIR}/bsp/timer_1ms.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/timer_1ms.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/bsp/Digital_Output.o: bsp/Digital_Output.c  .generated_files/e94659bb6a08ba6a023473d9964f41004e9871d8.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}/bsp" 
	@${RM} ${OBJECTDIR}/bsp/Digital_Output.o.d 
	@${RM} ${OBJECTDIR}/bsp/Digital_Output.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  bsp/Digital_Output.c  -o ${OBJECTDIR}/bsp/Digital_Output.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/bsp/Digital_Output.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/bfbb21b89436a17e6201a1f3907a265e9dcd9c43.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/system.o: system.c  .generated_files/a1a5e8d4ec63a673e02bebfaf49e512edcb33c50.flag .generated_files/8ab545786e3347d84c0f15a0012cf6e8148ea312.flag
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  system.c  -o ${OBJECTDIR}/system.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Web_Guide_V1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Web_Guide_V1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--no-isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Web_Guide_V1.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Web_Guide_V1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--no-isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Web_Guide_V1.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
