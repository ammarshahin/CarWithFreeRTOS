################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Mcal/PWM/src/%.obj: ../Mcal/PWM/src/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"E:/programs/eng .. programms/Coding/CCS9.2.0.00013_win64/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Ecual/Icu/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Ecual/Ultrasonic/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Mcal/Ext_Int/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Ecual/Lcd/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Ecual/Lcd/src" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/App/CarControl/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/App/CarControl/src" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Mcal/PWM/src" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Mcal/PWM/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Firmware/FreeRtos/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Ecual/Dc_Motor/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Ecual/Dc_Motor/src" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Firmware/FreeRtos/src" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Mcal/Tivaware/driverlib" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Mcal/Tivaware/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/App/testApp/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/App/testApp/src" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj/Comand/inc" --include_path="C:/Users/ammarPC/workspace_v9_2/CarProj" --include_path="E:/programs/eng .. programms/Coding/CCS9.2.0.00013_win64/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Mcal/PWM/src/$(basename $(<F)).d_raw" --obj_directory="Mcal/PWM/src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


