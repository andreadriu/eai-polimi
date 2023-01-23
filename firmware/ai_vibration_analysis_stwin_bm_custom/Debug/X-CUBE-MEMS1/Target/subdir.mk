################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../X-CUBE-MEMS1/Target/custom_motion_sensors.c \
../X-CUBE-MEMS1/Target/custom_motion_sensors_ex.c 

OBJS += \
./X-CUBE-MEMS1/Target/custom_motion_sensors.o \
./X-CUBE-MEMS1/Target/custom_motion_sensors_ex.o 

C_DEPS += \
./X-CUBE-MEMS1/Target/custom_motion_sensors.d \
./X-CUBE-MEMS1/Target/custom_motion_sensors_ex.d 


# Each subdirectory must supply rules for building sources it contributes
X-CUBE-MEMS1/Target/%.o X-CUBE-MEMS1/Target/%.su: ../X-CUBE-MEMS1/Target/%.c X-CUBE-MEMS1/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4R9xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/BSP/STEVAL-STWINKT1B -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/BSP/Components/ism330dhcx -I../Drivers/BSP/Components/Common -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -I../Drivers/CMSIS/DSP/Include -I../Core/Inc/Apph -I../Core/pre_processing_library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-X-2d-CUBE-2d-MEMS1-2f-Target

clean-X-2d-CUBE-2d-MEMS1-2f-Target:
	-$(RM) ./X-CUBE-MEMS1/Target/custom_motion_sensors.d ./X-CUBE-MEMS1/Target/custom_motion_sensors.o ./X-CUBE-MEMS1/Target/custom_motion_sensors.su ./X-CUBE-MEMS1/Target/custom_motion_sensors_ex.d ./X-CUBE-MEMS1/Target/custom_motion_sensors_ex.o ./X-CUBE-MEMS1/Target/custom_motion_sensors_ex.su

.PHONY: clean-X-2d-CUBE-2d-MEMS1-2f-Target

