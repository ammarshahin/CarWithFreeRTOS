################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
App/testApp/src/Tasks.obj: ../App/testApp/src/Tasks.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Mcal/PWM/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/App/CarControl/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/App/CarControl/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Mcal/PWM/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Firmware/FreeRtos/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Ecual/Dc_Motor/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Ecual/Dc_Motor/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Firmware/FreeRtos/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Mcal/Tivaware/driverlib" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Mcal/Tivaware/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/App/testApp/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/App/testApp/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Comand/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="App/testApp/src/Tasks.d_raw" --obj_directory="App/testApp/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

App/testApp/src/testApp.obj: ../App/testApp/src/testApp.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Mcal/PWM/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/App/CarControl/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/App/CarControl/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Mcal/PWM/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Firmware/FreeRtos/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Ecual/Dc_Motor/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Ecual/Dc_Motor/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Firmware/FreeRtos/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Mcal/Tivaware/driverlib" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Mcal/Tivaware/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/App/testApp/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/App/testApp/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0/Comand/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/Car0" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="App/testApp/src/testApp.d_raw" --obj_directory="App/testApp/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

