################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/jamha/Downloads/en.fp-cld-azure1/STM32CubeFunctionPack_AZURE1_V3.3.2/Middlewares/ST/STM32_MetaDataManager/MetaDataManager.c 

OBJS += \
./Middlewares/MetaDataManager/MetaDataManager.o 

C_DEPS += \
./Middlewares/MetaDataManager/MetaDataManager.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/MetaDataManager/MetaDataManager.o: C:/Users/jamha/Downloads/en.fp-cld-azure1/STM32CubeFunctionPack_AZURE1_V3.3.2/Middlewares/ST/STM32_MetaDataManager/MetaDataManager.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=c99 -DSTM32L475xx -DUSE_HAL_DRIVER -DUSE_STM32L475E_IOT01 '-DNO_LOGGING=1' '-DEINVAL=-1' '-DENOMEM=EINVAL' '-DUSE_GENERICACCESSKEY_IOTHUB=0' '-DREFCOUNT_ATOMIC_DONTCARE=1' '-DDONT_USE_UPLOADTOBLOB=1' -DUSE_MBED_TLS -DUSE_WIFI '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' -c -I../../../../Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../../../../../../../../Drivers/STM32L4xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/B-L475E-IOT01 -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/M24SR -I../../../../../../../../Drivers/BSP/Components/es_wifi -I../../../../../../../../Drivers/BSP/Components/hts221 -I../../../../../../../../Drivers/BSP/Components/lis3mdl -I../../../../../../../../Drivers/BSP/Components/lps22hb -I../../../../../../../../Drivers/BSP/Components/lsm6dsl -I../../../../../../../../Middlewares/ST/STM32_MetaDataManager -I../../../../../../../../Middlewares/ST/lib_NDEF/inc -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/umqtt/inc -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/iothub_client/inc -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/c-utility/inc -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/c-utility/pal/generic -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/serializer/inc -I../../../../../../../../Middlewares/Third_Parties/Azure-IoT-SDK-C/parson -I../../../../../../../../Middlewares/Third_Parties/mbedtls/include -O2 -ffunction-sections -Wall -Wno-unused-variable -Wno-unused-function -Wno-maybe-uninitialized -Wno-incompatible-pointer-types -Wno-format -fstack-usage -MMD -MP -MF"Middlewares/MetaDataManager/MetaDataManager.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

