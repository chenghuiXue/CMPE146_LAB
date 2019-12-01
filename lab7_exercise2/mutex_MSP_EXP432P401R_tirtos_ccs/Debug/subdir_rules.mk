################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/haoxc/Code_Compose9_2/mutex_MSP_EXP432P401R_tirtos_ccs" --include_path="C:/Users/haoxc/Code_Compose9_2/mutex_MSP_EXP432P401R_tirtos_ccs/Debug" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/third_party/CMSIS/Include" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/ti/posix/ccs" --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/haoxc/Code_Compose9_2/mutex_MSP_EXP432P401R_tirtos_ccs/Debug/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-834213471:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-834213471-inproc

build-834213471-inproc: ../mutex.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/ccs920/xdctools_3_60_01_27_core/xs" --xdcpath="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source;C:/ti/simplelink_msp432p4_sdk_3_30_00_13/kernel/tirtos/packages;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M4F -p ti.platforms.msp432:MSP432P401R -r release -c "C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS" --compileOptions "-mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path=\"C:/Users/haoxc/Code_Compose9_2/mutex_MSP_EXP432P401R_tirtos_ccs\" --include_path=\"C:/Users/haoxc/Code_Compose9_2/mutex_MSP_EXP432P401R_tirtos_ccs/Debug\" --include_path=\"C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source\" --include_path=\"C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/third_party/CMSIS/Include\" --include_path=\"C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/ti/posix/ccs\" --include_path=\"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include\" --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on  " "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-834213471 ../mutex.cfg
configPkg/compiler.opt: build-834213471
configPkg/: build-834213471

build-2132758193:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-2132758193-inproc

build-2132758193-inproc: ../mutex.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/ccs920/ccs/utils/sysconfig/sysconfig_cli.bat" -s "C:/ti/simplelink_msp432p4_sdk_3_30_00_13/.metadata/product.json" -o "syscfg" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/ti_drivers_config.c: build-2132758193 ../mutex.syscfg
syscfg/ti_drivers_config.h: build-2132758193
syscfg/syscfg_c.rov.xs: build-2132758193
syscfg/: build-2132758193

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/haoxc/Code_Compose9_2/mutex_MSP_EXP432P401R_tirtos_ccs" --include_path="C:/Users/haoxc/Code_Compose9_2/mutex_MSP_EXP432P401R_tirtos_ccs/Debug" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/third_party/CMSIS/Include" --include_path="C:/ti/simplelink_msp432p4_sdk_3_30_00_13/source/ti/posix/ccs" --include_path="C:/ti/ccs920/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --advice:power=none -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/haoxc/Code_Compose9_2/mutex_MSP_EXP432P401R_tirtos_ccs/Debug/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


