################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Mcal/PWM/src/PWM.obj: ../Mcal/PWM/src/PWM.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Firmware/FreeRtos/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Firmware/FreeRtos/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Mcal/Ext_Int/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Mcal/Ext_Int/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Mcal/PWM/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Mcal/PWM/src" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Mcal/Tivaware/driverlib" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Mcal/Tivaware/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/App/CarControl/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/App/testApp/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Ecual/Dc_Motor/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Ecual/Icu/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Ecual/Lcd/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Ecual/Ultrasonic/inc" --include_path="C:/Users/AVE-LAP-44/Desktop/CC Ws/CarProj/Comand/inc" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Mcal/PWM/src/PWM.d_raw" --obj_directory="Mcal/PWM/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


