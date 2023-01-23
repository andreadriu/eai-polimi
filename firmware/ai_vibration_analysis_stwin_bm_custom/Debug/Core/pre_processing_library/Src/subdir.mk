################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/pre_processing_library/Src/pre_processing_app.c \
../Core/pre_processing_library/Src/pre_processing_core.c \
../Core/pre_processing_library/Src/sys_functions.c 

OBJS += \
./Core/pre_processing_library/Src/pre_processing_app.o \
./Core/pre_processing_library/Src/pre_processing_core.o \
./Core/pre_processing_library/Src/sys_functions.o 

C_DEPS += \
./Core/pre_processing_library/Src/pre_processing_app.d \
./Core/pre_processing_library/Src/pre_processing_core.d \
./Core/pre_processing_library/Src/sys_functions.d 


# Each subdirectory must supply rules for building sources it contributes
Core/pre_processing_library/Src/%.o Core/pre_processing_library/Src/%.su: ../Core/pre_processing_library/Src/%.c Core/pre_processing_library/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4R9xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/BSP/STEVAL-STWINKT1B -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/BSP/Components/ism330dhcx -I../Drivers/BSP/Components/Common -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -I../Drivers/CMSIS/DSP/Include -I../Core/Inc/Apph -I../Core/pre_processing_library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-pre_processing_library-2f-Src

clean-Core-2f-pre_processing_library-2f-Src:
	-$(RM) ./Core/pre_processing_library/Src/pre_processing_app.d ./Core/pre_processing_library/Src/pre_processing_app.o ./Core/pre_processing_library/Src/pre_processing_app.su ./Core/pre_processing_library/Src/pre_processing_core.d ./Core/pre_processing_library/Src/pre_processing_core.o ./Core/pre_processing_library/Src/pre_processing_core.su ./Core/pre_processing_library/Src/sys_functions.d ./Core/pre_processing_library/Src/sys_functions.o ./Core/pre_processing_library/Src/sys_functions.su

.PHONY: clean-Core-2f-pre_processing_library-2f-Src

