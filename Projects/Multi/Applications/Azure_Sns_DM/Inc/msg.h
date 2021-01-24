/**
  ******************************************************************************
  * @file    msg.h
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    08-May-2018
  * @brief   Trace message API.
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
#ifndef __MSG_H__
#define __MSG_H__

#include <stdio.h>
#include <stdlib.h>

#ifdef   ENABLE_IOT_INFO
#define MSG_INFO
#endif

#ifdef ENABLE_IOT_WARN
#define MSG_WARNING
#endif
#ifdef ENABLE_IOT_ERROR
#define MSG_ERROR
#endif

#ifdef ENABLE_IOT_DEBUG
#define MSG_DEBUG       
#endif


/**
 * @brief Debug level logging macro.
 *
 * Macro to expose function, line number as well as desired log message.
 */
#ifdef MSG_DEBUG
#define msg_debug(...)    \
	{\
	printf("DEBUG:   %s L#%d ", __func__, __LINE__);  \
	printf(__VA_ARGS__); \
	}
#else
#define msg_debug(...)
#endif


/**
 * @brief Info level logging macro.
 *
 * Macro to expose desired log message.  Info messages do not include automatic function names and line numbers.
 */
#ifdef MSG_INFO
#define msg_info(...)    \
	{\
	printf(__VA_ARGS__); \
	}
#else
#define msg_info(...)
#endif

/**
 * @brief Warn level logging macro.
 *
 * Macro to expose function, line number as well as desired log message.
 */
#ifdef MSG_WARNING
#define msg_warning(...)   \
	{ \
	printf("WARN:  %s L#%d ", __func__, __LINE__);  \
	printf(__VA_ARGS__); \
	}
#else
#define msg_warning(...)
#endif

/**
 * @brief Error level logging macro.
 *
 * Macro to expose function, line number as well as desired log message.
 */
#ifdef MSG_ERROR
#define msg_error(...)  \
	{ \
	printf("ERROR: %s L#%d ", __func__, __LINE__); \
	printf(__VA_ARGS__); \
	}
#else
#define msg_error(...)
#endif

#endif /* __MSG_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
