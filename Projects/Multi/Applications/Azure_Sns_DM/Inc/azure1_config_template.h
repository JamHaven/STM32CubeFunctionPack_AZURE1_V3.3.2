/**
  ******************************************************************************
  * @file    azure1_config.h
  * @author  Central LAB
  * @version V3.3.0
  * @date    08-May-2018
  * @brief   azure1 configuration
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2018 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __azure1_CONFIG_H
#define __azure1_CONFIG_H

/* Exported define ------------------------------------------------------------*/

/*************** Enable Print Informations ******************/
#define AZURE_ENABLE_PRINTF

/*************** Default WIFI Credential ******************/
#ifndef STM32F429xx
#define AZURE_DEFAULT_SSID ""
#define AZURE_DEFAULT_SECKEY ""
#define AZURE_DEFAULT_PRIV_MODE WPA_Personal
#endif /* STM32F429xx */

/* Uncomment the following line for enabling the modifications for Azure IoT Central solution */
#ifndef STM32F401xE
  // #define AZURE_IOT_CENTRAL
#endif /* STM32F401xE */

#ifndef AZURE_IOT_CENTRAL
  /* Uncomment the following define for enabling the Registration */
  // #define AZURE_ENABLE_REGISTRATION
#endif /* AZURE_IOT_CENTRAL  */

/* For configuring the WIFI in Mini AP mode
 * connect to "captiveportal.net" and set like miniAP PassKey "anonymous" and choose mode "Station" */
//#define AZURE_MINI_AP

/* NTP end point */
#define NTP_ENDPOINT_IPADDRESS_DEFAULT         "time.nist.gov"
#define NTP_ENDPOINT_TCPPORT           37

#ifdef AZURE_ENABLE_REGISTRATION
  #define WEB_DASHBOARD_URL "stm32ode.azurewebsites.net"
#else /* AZURE_ENABLE_REGISTRATION */
  /* String containing Hostname, Device Id & Device Key in the format:                         */
  // #define AZUREDEVICECONNECTIONSTRING "HostName=HomeBase.azure-devices.net;DeviceId=STM32;SharedAccessKey=8bx9mn+jOJ0gm4J+QdVnIIUlklW5N/7O5o/IH/CZlXY="
	#define AZUREDEVICECONNECTIONSTRING ""
#endif /* AZURE_ENABLE_REGISTRATION */

/*************** Don't Change the following defines *************/

/* Package Version only numbers 0->9 */
#define AZURE_VERSION_MAJOR '3'
#define AZURE_VERSION_MINOR '3'
#define AZURE_VERSION_PATCH '0'

/* Package Name */
#ifdef STM32F401xE
  #define AZURE_PACKAGENAME "Azure_Sns"
#else /* STM32F401xE */
  #define AZURE_PACKAGENAME "Azure_Sns_DM"
#endif /* STM32F401xE */

#ifdef AZURE_ENABLE_PRINTF
  #define AZURE_PRINTF(...) printf(__VA_ARGS__)
#else /* AZURE_ENABLE_PRINTF */
  #define AZURE_PRINTF(...)
#endif /* AZURE_ENABLE_PRINTF */

#ifdef USE_STM32L475E_IOT01
/**
 * UART1
 */
#define CFG_HW_UART1_BAUDRATE             115200
#define CFG_HW_UART1_WORDLENGTH           UART_WORDLENGTH_8B
#define CFG_HW_UART1_STOPBITS             UART_STOPBITS_1
#define CFG_HW_UART1_PARITY               UART_PARITY_NONE
#define CFG_HW_UART1_HWFLOWCTL            UART_HWCONTROL_NONE
#define CFG_HW_UART1_MODE                 UART_MODE_TX_RX
#define CFG_HW_UART1_ADVFEATUREINIT       UART_ADVFEATURE_NO_INIT

/**
 * NFC
 */

/**
  * @brief  M24SR_EEPROM_Size_Version
  */
#define M24SR04_NDEF_MAX_SIZE                0x200
#define M24SR16_NDEF_MAX_SIZE                0x800
#define M24SR64_NDEF_MAX_SIZE                0x2000
/* The maximum size of a NDEF will be 64kBits with M24SR64 */
/* if smaller memory used update this define to save space */
#define NFC_TT4_NDEF_MAX_SIZE          M24SR16_NDEF_MAX_SIZE

/**
  * @brief  M24SR_GPO_Config_Mode
  */
#define M24SR_I2C_GPO_POLLING   0 /* Normal  I�C polling */
#define M24SR_I2C_GPO_SYNCHRO   1 /* allow to use GPO polling as I2C synchronization */ 
#define M24SR_I2C_GPO_INTERRUPT 2 /* allow to use GPO interrupt as I2C synchronization */ 
/* The maximum size of a NDEF will be 64kBits with M24SR64 */
/* if smaller memory used update this define to save space */
#define M24SR_I2C_GPO_MODE            M24SR_I2C_GPO_INTERRUPT
    
/**
 * WIFI
 */
#define  WIFI_CONNECT_MAX_ATTEMPT_COUNT  3
#define  WIFI_GET_IP_MAX_ATTEMPT_COUNT  10
#define  WIFI_WRITE_TIMEOUT   400
#define  WIFI_READ_TIMEOUT    400
#define WIFI_PRODUCT_INFO_SIZE ES_WIFI_MAX_SSID_NAME_SIZE
#define WIFI_PAYLOAD_SIZE      ES_WIFI_PAYLOAD_SIZE
#endif /* USE_STM32L475E_IOT01 */
#endif /* __azure1_CONFIG_H */

/******************* (C) COPYRIGHT 2018 STMicroelectronics *****END OF FILE****/
