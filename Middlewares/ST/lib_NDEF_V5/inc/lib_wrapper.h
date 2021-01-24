/**
  ******************************************************************************
  * @file    lib_wrapper.h
  * @author  MMY Application Team
  * @version $Revision: 2702 $
  * @date    $Date: 2016-07-13 18:45:05 +0200 (Wed, 13 Jul 2016) $
  * @brief   This file help to have upper layer independent from HW
 ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2015 STMicroelectronics</center></h2>
  *
  * Licensed under ST MYLIBERTY SOFTWARE LICENSE AGREEMENT (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/myliberty  
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied,
  * AND SPECIFICALLY DISCLAIMING THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LIB_WRAPPER_H
#define __LIB_WRAPPER_H

/* Includes ------------------------------------------------------------------*/
//#include "common.h"
#include "x_nucleo_nfc04a1_nfctag.h"

#ifndef MIN_ST25DV
#define MIN_ST25DV(x, y) (((x) < (y)) ? (x) : (y))
#endif

#define MAX_NDEF_MEM                 0x200
#define ST25DV_MAX_SIZE              NFCTAG_4K_SIZE
#define ST25DV_NDEF_MAX_SIZE         MIN_ST25DV(ST25DV_MAX_SIZE,MAX_NDEF_MEM)
#define NFC_DEVICE_MAX_NDEFMEMORY    ST25DV_NDEF_MAX_SIZE

#define RESULTOK                     0x00
#define ERRORCODE_GENERIC            1



uint16_t NfcTag_ReadNDEF( uint8_t* pData );
uint16_t NfcTag_WriteNDEF(uint16_t Length, uint8_t* pData );
uint16_t NfcTag_WriteProprietary(uint16_t Length, uint8_t* pData );
uint16_t NfcTag_GetLength(uint16_t* Length);

#endif /* __LIB_WRAPPER_H */


/******************* (C) COPYRIGHT 2015 STMicroelectronics *****END OF FILE****/
