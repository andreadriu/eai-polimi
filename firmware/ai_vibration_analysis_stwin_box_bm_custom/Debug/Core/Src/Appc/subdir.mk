################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Appc/app_mems_int_pin_a_interface.c \
../Core/Src/Appc/sensor_app.c 

OBJS += \
./Core/Src/Appc/app_mems_int_pin_a_interface.o \
./Core/Src/Appc/sensor_app.o 

C_DEPS += \
./Core/Src/Appc/app_mems_int_pin_a_interface.d \
./Core/Src/Appc/sensor_app.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Appc/%.o Core/Src/Appc/%.su: ../Core/Src/Appc/%.c Core/Src/Appc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32U585xx -c -I../Core/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc -I../Drivers/STM32U5xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32U5xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../Drivers/BSP/STEVAL-STWINBX1 -I../Drivers/BSP/Components/ism330dhcx -I../Drivers/BSP/Components/Common -I../Core/Inc/Apph -I../Drivers/CMSIS/DSP/Include -I../Core/pre_processing_library/Inc -I../Middlewares/ST/AI/Inc -I../X-CUBE-AI/App -I../USB_Device/App -I../USB_Device/Target -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Appc

clean-Core-2f-Src-2f-Appc:
	-$(RM) ./Core/Src/Appc/app_mems_int_pin_a_interface.d ./Core/Src/Appc/app_mems_int_pin_a_interface.o ./Core/Src/Appc/app_mems_int_pin_a_interface.su ./Core/Src/Appc/sensor_app.d ./Core/Src/Appc/sensor_app.o ./Core/Src/Appc/sensor_app.su

.PHONY: clean-Core-2f-Src-2f-Appc

