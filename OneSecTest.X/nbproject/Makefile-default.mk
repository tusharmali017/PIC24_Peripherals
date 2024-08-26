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
FINAL_IMAGE=${DISTDIR}/OneSecTest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/OneSecTest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=APP/app.c BIOS/bios.c BIOS/timer1.c BIOS/uart1.c BIOS/pinmap.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/APP/app.o ${OBJECTDIR}/BIOS/bios.o ${OBJECTDIR}/BIOS/timer1.o ${OBJECTDIR}/BIOS/uart1.o ${OBJECTDIR}/BIOS/pinmap.o ${OBJECTDIR}/main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/APP/app.o.d ${OBJECTDIR}/BIOS/bios.o.d ${OBJECTDIR}/BIOS/timer1.o.d ${OBJECTDIR}/BIOS/uart1.o.d ${OBJECTDIR}/BIOS/pinmap.o.d ${OBJECTDIR}/main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/APP/app.o ${OBJECTDIR}/BIOS/bios.o ${OBJECTDIR}/BIOS/timer1.o ${OBJECTDIR}/BIOS/uart1.o ${OBJECTDIR}/BIOS/pinmap.o ${OBJECTDIR}/main.o

# Source Files
SOURCEFILES=APP/app.c BIOS/bios.c BIOS/timer1.c BIOS/uart1.c BIOS/pinmap.c main.c



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
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/OneSecTest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ1024GB610
MP_LINKER_FILE_OPTION=,--script=p24FJ1024GB610.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/APP/app.o: APP/app.c  .generated_files/flags/default/a49b1eceba0dc90ee117b431c9f0cec792092bd8 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/APP" 
	@${RM} ${OBJECTDIR}/APP/app.o.d 
	@${RM} ${OBJECTDIR}/APP/app.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  APP/app.c  -o ${OBJECTDIR}/APP/app.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/APP/app.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/BIOS/bios.o: BIOS/bios.c  .generated_files/flags/default/38b00840125a91727baa7cd912e2a254462e787 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/BIOS" 
	@${RM} ${OBJECTDIR}/BIOS/bios.o.d 
	@${RM} ${OBJECTDIR}/BIOS/bios.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BIOS/bios.c  -o ${OBJECTDIR}/BIOS/bios.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/BIOS/bios.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/BIOS/timer1.o: BIOS/timer1.c  .generated_files/flags/default/3bf4dfd744a5260674393f358c27c1fb55d50e9d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/BIOS" 
	@${RM} ${OBJECTDIR}/BIOS/timer1.o.d 
	@${RM} ${OBJECTDIR}/BIOS/timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BIOS/timer1.c  -o ${OBJECTDIR}/BIOS/timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/BIOS/timer1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/BIOS/uart1.o: BIOS/uart1.c  .generated_files/flags/default/6c9d7c3446bf81ebc17834e83108f2866ab3dcad .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/BIOS" 
	@${RM} ${OBJECTDIR}/BIOS/uart1.o.d 
	@${RM} ${OBJECTDIR}/BIOS/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BIOS/uart1.c  -o ${OBJECTDIR}/BIOS/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/BIOS/uart1.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/BIOS/pinmap.o: BIOS/pinmap.c  .generated_files/flags/default/ea2f9413db2b0f05bdc0fd37c2a8c60b2da9c02 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/BIOS" 
	@${RM} ${OBJECTDIR}/BIOS/pinmap.o.d 
	@${RM} ${OBJECTDIR}/BIOS/pinmap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BIOS/pinmap.c  -o ${OBJECTDIR}/BIOS/pinmap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/BIOS/pinmap.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/3befb1ce8348965c102fbd7b1f045916b67f86f3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/APP/app.o: APP/app.c  .generated_files/flags/default/bc57ffded9047eac6c6c3bd4c93d478bee811d25 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/APP" 
	@${RM} ${OBJECTDIR}/APP/app.o.d 
	@${RM} ${OBJECTDIR}/APP/app.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  APP/app.c  -o ${OBJECTDIR}/APP/app.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/APP/app.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/BIOS/bios.o: BIOS/bios.c  .generated_files/flags/default/570783195f3368825abd651b209d7d0b9a3b197e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/BIOS" 
	@${RM} ${OBJECTDIR}/BIOS/bios.o.d 
	@${RM} ${OBJECTDIR}/BIOS/bios.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BIOS/bios.c  -o ${OBJECTDIR}/BIOS/bios.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/BIOS/bios.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/BIOS/timer1.o: BIOS/timer1.c  .generated_files/flags/default/d6f0b511dd40e2f50d8bef48b3e6724b533bbfaa .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/BIOS" 
	@${RM} ${OBJECTDIR}/BIOS/timer1.o.d 
	@${RM} ${OBJECTDIR}/BIOS/timer1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BIOS/timer1.c  -o ${OBJECTDIR}/BIOS/timer1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/BIOS/timer1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/BIOS/uart1.o: BIOS/uart1.c  .generated_files/flags/default/56ce655c3cc5d8e34bbe35a07b71837b7a66aeec .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/BIOS" 
	@${RM} ${OBJECTDIR}/BIOS/uart1.o.d 
	@${RM} ${OBJECTDIR}/BIOS/uart1.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BIOS/uart1.c  -o ${OBJECTDIR}/BIOS/uart1.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/BIOS/uart1.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/BIOS/pinmap.o: BIOS/pinmap.c  .generated_files/flags/default/3589718e249affcb79e48244b71e9aa0c4c2f81c .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/BIOS" 
	@${RM} ${OBJECTDIR}/BIOS/pinmap.o.d 
	@${RM} ${OBJECTDIR}/BIOS/pinmap.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  BIOS/pinmap.c  -o ${OBJECTDIR}/BIOS/pinmap.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/BIOS/pinmap.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/26642d716a68e4683c282c1f1ae88aed24e7740b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
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
${DISTDIR}/OneSecTest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/OneSecTest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG -D__MPLAB_DEBUGGER_ICD4=1  -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,--defsym=__MPLAB_DEBUGGER_ICD4=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/OneSecTest.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/OneSecTest.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/OneSecTest.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
