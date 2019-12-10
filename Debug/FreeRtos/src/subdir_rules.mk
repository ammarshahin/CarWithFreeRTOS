################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FreeRtos/src/heap_1.obj: ../FreeRtos/src/heap_1.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/src" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRtos/src/heap_1.d_raw" --obj_directory="FreeRtos/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRtos/src/list.obj: ../FreeRtos/src/list.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/src" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRtos/src/list.d_raw" --obj_directory="FreeRtos/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRtos/src/port.obj: ../FreeRtos/src/port.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/src" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRtos/src/port.d_raw" --obj_directory="FreeRtos/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRtos/src/portasm.obj: ../FreeRtos/src/portasm.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/src" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRtos/src/portasm.d_raw" --obj_directory="FreeRtos/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRtos/src/queue.obj: ../FreeRtos/src/queue.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/src" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRtos/src/queue.d_raw" --obj_directory="FreeRtos/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRtos/src/tasks.obj: ../FreeRtos/src/tasks.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/FreeRtos/src" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRtos/src/tasks.d_raw" --obj_directory="FreeRtos/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


