################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../X-CUBE-AI/App/aiApp.c \
../X-CUBE-AI/App/network.c \
../X-CUBE-AI/App/network_data.c 

OBJS += \
./X-CUBE-AI/App/aiApp.o \
./X-CUBE-AI/App/network.o \
./X-CUBE-AI/App/network_data.o 

C_DEPS += \
./X-CUBE-AI/App/aiApp.d \
./X-CUBE-AI/App/network.d \
./X-CUBE-AI/App/network_data.d 


# Each subdirectory must supply rules for building sources it contributes
X-CUBE-AI/App/%.o X-CUBE-AI/App/%.su: ../X-CUBE-AI/App/%.c X-CUBE-AI/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4R9xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../X-CUBE-MEMS1/Target -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Drivers/BSP/STEVAL-STWINKT1B -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -I../Drivers/BSP/Components/ism330dhcx -I../Drivers/BSP/Components/Common -I../X-CUBE-AI/App -I../Middlewares/ST/AI/Inc -I../Drivers/CMSIS/DSP/Include -I../Core/Inc/Apph -I../Core/pre_processing_library/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-X-2d-CUBE-2d-AI-2f-App

clean-X-2d-CUBE-2d-AI-2f-App:
	-$(RM) ./X-CUBE-AI/App/aiApp.d ./X-CUBE-AI/App/aiApp.o ./X-CUBE-AI/App/aiApp.su ./X-CUBE-AI/App/network.d ./X-CUBE-AI/App/network.o ./X-CUBE-AI/App/network.su ./X-CUBE-AI/App/network_data.d ./X-CUBE-AI/App/network_data.o ./X-CUBE-AI/App/network_data.su

.PHONY: clean-X-2d-CUBE-2d-AI-2f-App

