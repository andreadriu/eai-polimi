################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/work2/Presentation/ai_vibration_analysis_stwin_bm/Core/Startup/startup_stm32l4r9zijx.s 

OBJS += \
./Core/Startup/startup_stm32l4r9zijx.o 

S_DEPS += \
./Core/Startup/startup_stm32l4r9zijx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/startup_stm32l4r9zijx.o: C:/work2/Presentation/ai_vibration_analysis_stwin_bm/Core/Startup/startup_stm32l4r9zijx.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"C:/work2/Presentation/ai_vibration_analysis_stwin_bm/STM32_CUBE_IDE/Core" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32l4r9zijx.d ./Core/Startup/startup_stm32l4r9zijx.o

.PHONY: clean-Core-2f-Startup

