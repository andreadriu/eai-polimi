################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/work2/Presentation/ai_vibration_analysis_stwin_bm/Drivers/BSP/STWIN/STWIN.c \
C:/work2/Presentation/ai_vibration_analysis_stwin_bm/Drivers/BSP/STWIN/STWIN_bus.c \
C:/work2/Presentation/ai_vibration_analysis_stwin_bm/Drivers/BSP/STWIN/STWIN_motion_sensors.c \
C:/work2/Presentation/ai_vibration_analysis_stwin_bm/Drivers/BSP/STWIN/STWIN_motion_sensors_ex.c 

OBJS += \
./Drivers/BSP/STWIN/STWIN.o \
./Drivers/BSP/STWIN/STWIN_bus.o \
./Drivers/BSP/STWIN/STWIN_motion_sensors.o \
./Drivers/BSP/STWIN/STWIN_motion_sensors_ex.o 

C_DEPS += \
./Drivers/BSP/STWIN/STWIN.d \
./Drivers/BSP/STWIN/STWIN_bus.d \
./Drivers/BSP/STWIN/STWIN_motion_sensors.d \
./Drivers/BSP/STWIN/STWIN_motion_sensors_ex.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STWIN/STWIN.o: C:/work2/Presentation/ai_vibration_analysis_stwin_bm/Drivers/BSP/STWIN/STWIN.c Drivers/BSP/STWIN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4R9xx -c -I../../Core/pre_processing_library/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Middlewares/ST/AI/Inc -I../../X-CUBE-AI/App -I../../Drivers/BSP/Components/Common -I../../Drivers/CMSIS/DSP/Include -I../../Drivers/BSP/STWIN -I../../Drivers/BSP/Components/ism330dhcx -I../../Core/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STWIN/STWIN_bus.o: C:/work2/Presentation/ai_vibration_analysis_stwin_bm/Drivers/BSP/STWIN/STWIN_bus.c Drivers/BSP/STWIN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4R9xx -c -I../../Core/pre_processing_library/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Middlewares/ST/AI/Inc -I../../X-CUBE-AI/App -I../../Drivers/BSP/Components/Common -I../../Drivers/CMSIS/DSP/Include -I../../Drivers/BSP/STWIN -I../../Drivers/BSP/Components/ism330dhcx -I../../Core/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STWIN/STWIN_motion_sensors.o: C:/work2/Presentation/ai_vibration_analysis_stwin_bm/Drivers/BSP/STWIN/STWIN_motion_sensors.c Drivers/BSP/STWIN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4R9xx -c -I../../Core/pre_processing_library/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Middlewares/ST/AI/Inc -I../../X-CUBE-AI/App -I../../Drivers/BSP/Components/Common -I../../Drivers/CMSIS/DSP/Include -I../../Drivers/BSP/STWIN -I../../Drivers/BSP/Components/ism330dhcx -I../../Core/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Drivers/BSP/STWIN/STWIN_motion_sensors_ex.o: C:/work2/Presentation/ai_vibration_analysis_stwin_bm/Drivers/BSP/STWIN/STWIN_motion_sensors_ex.c Drivers/BSP/STWIN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L4R9xx -c -I../../Core/pre_processing_library/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../Middlewares/ST/AI/Inc -I../../X-CUBE-AI/App -I../../Drivers/BSP/Components/Common -I../../Drivers/CMSIS/DSP/Include -I../../Drivers/BSP/STWIN -I../../Drivers/BSP/Components/ism330dhcx -I../../Core/Inc -I../../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../Drivers/CMSIS/Include -I../../USB_DEVICE/App -I../../USB_DEVICE/Target -I../../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../../Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP-2f-STWIN

clean-Drivers-2f-BSP-2f-STWIN:
	-$(RM) ./Drivers/BSP/STWIN/STWIN.d ./Drivers/BSP/STWIN/STWIN.o ./Drivers/BSP/STWIN/STWIN.su ./Drivers/BSP/STWIN/STWIN_bus.d ./Drivers/BSP/STWIN/STWIN_bus.o ./Drivers/BSP/STWIN/STWIN_bus.su ./Drivers/BSP/STWIN/STWIN_motion_sensors.d ./Drivers/BSP/STWIN/STWIN_motion_sensors.o ./Drivers/BSP/STWIN/STWIN_motion_sensors.su ./Drivers/BSP/STWIN/STWIN_motion_sensors_ex.d ./Drivers/BSP/STWIN/STWIN_motion_sensors_ex.o ./Drivers/BSP/STWIN/STWIN_motion_sensors_ex.su

.PHONY: clean-Drivers-2f-BSP-2f-STWIN

