################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/jamha/Downloads/en.fp-cld-azure1/STM32CubeFunctionPack_AZURE1_V3.3.2/Projects/Multi/Applications/Azure_Sns_DM/SW4STM32/B-L475E-IOT01/startup_stm32l475xx.s 

C_SRCS += \
C:/Users/jamha/Downloads/en.fp-cld-azure1/STM32CubeFunctionPack_AZURE1_V3.3.2/Projects/Multi/Applications/Azure_Sns_DM/Src/syscalls.c 

OBJS += \
./Azure_Sns_DM/SW4STM32/startup_stm32l475xx.o \
./Azure_Sns_DM/SW4STM32/syscalls.o 

S_DEPS += \
./Azure_Sns_DM/SW4STM32/startup_stm32l475xx.d 

C_DEPS += \
./Azure_Sns_DM/SW4STM32/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
Azure_Sns_DM/SW4STM32/startup_stm32l475xx.o: C:/Users/jamha/Downloads/en.fp-cld-azure1/STM32CubeFunctionPack_AZURE1_V3.3.2/Projects/Multi/Applications/Azure_Sns_DM/SW4STM32/B-L475E-IOT01/startup_stm32l475xx.s
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -c -x assembler-with-cpp -MMD -MP -MF"Azure_Sns_DM/SW4STM32/startup_stm32l475xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
Azure_Sns_DM/SW4STM32/syscalls.o: C:/Users/jamha/Downloads/en.fp-cld-azure1/STM32CubeFunctionPack_AZURE1_V3.3.2/Projects/Multi/Applications/Azure_Sns_DM/Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -DSTM32L475xx -DUSE_HAL_DRIVER -DUSE_STM32L475E_IOT01 '-DNO_LOGGING=1' '-DEINVAL=-1' '-DENOMEM=EINVAL' '-DUSE_GENERICACCESSKEY_IOTHUB=0' '-DREFCOUNT_ATOMIC_DONTCARE=1' '-DDONT_USE_UPLOADTOBLOB=1' -DUSE_MBED_TLS -DUSE_WIFI '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' -c -I../../../../Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/B-L475E-IOT01 -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/M24SR -I../../../../../../../../Drivers/BSP/Components/es_wifi -I../../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../../Drivers/BSP/Components/lis3mdl -I../../../../../../../../Drivers/BSP/Components/lps22hb -I../../../../../../../../Drivers/BSP/Components/lsm6dsl -I../../../../../../../../Middlewares/ST/STM32_MetaDataManager -I../../../../../../../../Middlewares/ST/lib_NDEF/inc -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/umqtt/inc -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/iothub_client/inc -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/c-utility/inc -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/c-utility/pal/generic -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/serializer/inc -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/parson -I../../../../../../../../Middlewares/Third_Parties/mbedtls/include -O2 -ffunction-sections -Wall -Wno-unused-variable -Wno-unused-function -Wno-maybe-uninitialized -Wno-incompatible-pointer-types -Wno-format -fstack-usage -MMD -MP -MF"Azure_Sns_DM/SW4STM32/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

