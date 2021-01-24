/**
  ******************************************************************************
  * @file    xnucleoihm02a1_interface.h
  * @brief   This file is used as header of the interface between the 
  *          X-NUCLEO-IHM02A1 and the NUCLEO-F4xx board.
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
#ifndef __XNUCLEO_INTERFACE_H
#define __XNUCLEO_INTERFACE_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#ifdef USE_STM32L475E_IOT01
  #include "stm32l4xx_hal.h"
  #include "stm32l475e_iot01.h"
  extern SPI_HandleTypeDef SpiHandle;
#else /* USE_STM32L475E_IOT01 */
  #ifdef USE_STM32L4XX_NUCLEO
    #include "stm32l4xx.h"
    #include "stm32l4xx_hal.h"
    #include "stm32l4xx_nucleo.h"
    #include "stm32l4xx_SPI.h"
  #else /* USE_STM32L4XX_NUCLEO */
    #include "stm32f4xx.h"
    #include "stm32f4xx_hal.h"
    #include "stm32f4xx_nucleo.h"
    #include "stm32f4xx_SPI.h"
  #endif /* USE_STM32L4XX_NUCLEO */
#endif /* USE_STM32L475E_IOT01 */

#define HSPI                                  SpiHandle

#ifdef STM32F401xE
  #define GPIO_CLK_ENABLE(OPx_GPIO_CLK_ENABLE)    (RCC->AHB1ENR |= (OPx_GPIO_CLK_ENABLE))

  /* GPIO settings for the nSTBY_nRST pins of the L6470 */
  #define L6470_nSTBY_nRST_GPIO_CLK_ENABLE        RCC_AHB1ENR_GPIOBEN   //!< nSTBY_nRST, RCC AHB peripheral clock register
  #define L6470_nSTBY_nRST_GPIO_PORT              GPIOB                 //!< nSTBY_nRST, GPIO Port
  #define L6470_nSTBY_nRST_GPIO_PIN               GPIO_PIN_5            //!< nSTBY_nRST, GPIO Pin

  /* GPIO settings for the nBUSY_SYNC pin of the L6470 */
  #define L6470_nBUSY_SYNC_GPIO_CLK_ENABLE        RCC_AHB1ENR_GPIOCEN   //!< nBUSY_SYNC, RCC AHB1 peripheral clock register
  #define L6470_nBUSY_SYNC_GPIO_PORT              GPIOC                 //!< nSTBY_nRST, GPIO Port
  #define L6470_nBUSY_SYNC_GPIO_PIN               GPIO_PIN_0            //!< nSTBY_nRST, GPIO Pin
  #define L6470_nBUSY_SYNC_IRQn                   EXTI0_IRQn            //!< nSTBY_nRST, IRQ number
  #define L6470_nBUSY_SYNC_EXTI_IRQHandler        EXTI0_IRQHandler      //!< nSTBY_nRST, IRQ handler name

  /* GPIO settings for the nFLAG pin of the L6470 */
  #define L6470_nFLAG_GPIO_CLK_ENABLE             RCC_AHB1ENR_GPIOCEN   //!< nFLAG, RCC AHB1 peripheral clock register
  #define L6470_nFLAG_GPIO_PORT                   GPIOC                 //!< nFLAG, GPIO Port
  #define L6470_nFLAG_GPIO_PIN                    GPIO_PIN_1            //!< nFLAG, GPIO Pin
  #define L6470_nFLAG_IRQn                        EXTI1_IRQn            //!< nFLAG, IRQ number
  #define L6470_nFLAG_EXTI_IRQHandler             EXTI1_IRQHandler      //!< nFLAG, IRQ handler name

  /* GPIO settings for the options about the nCS pins of the L6470 */
  #define L6470_nCS_OP0_GPIO_CLK_ENABLE           RCC_AHB1ENR_GPIOAEN   //!< nCS Option 0, RCC AHB peripheral clock register
  #define L6470_nCS_OP0_GPIO_PORT                 GPIOA                 //!< nCS Option 0, GPIO Port
  #define L6470_nCS_OP0_GPIO_PIN                  GPIO_PIN_4            //!< nCS Option 0, GPIO Pin
  #define L6470_nCS_OP1_GPIO_CLK_ENABLE           RCC_AHB1ENR_GPIOAEN   //!< nCS Option 1, RCC AHB peripheral clock register
  #define L6470_nCS_OP1_GPIO_PORT                 GPIOA                 //!< nCS Option 1, GPIO Port
  #define L6470_nCS_OP1_GPIO_PIN                  GPIO_PIN_10           //!< nCS Option 1, GPIO Pin
  #define L6470_nCS_OP2_GPIO_CLK_ENABLE           RCC_AHB1ENR_GPIOBEN   //!< nCS Option 2, RCC AHB peripheral clock register
  #define L6470_nCS_OP2_GPIO_PORT                 GPIOB                 //!< nCS Option 2, GPIO Port
  #define L6470_nCS_OP2_GPIO_PIN                  GPIO_PIN_6            //!< nCS Option 2, GPIO Pin
  #define L6470_nCS_OP3_GPIO_CLK_ENABLE           RCC_AHB1ENR_GPIOBEN   //!< nCS Option 3, RCC AHB peripheral clock register
  #define L6470_nCS_OP3_GPIO_PORT                 GPIOB                 //!< nCS Option 3, GPIO Port
  #define L6470_nCS_OP3_GPIO_PIN                  GPIO_PIN_4            //!< nCS Option 3, GPIO Pin
#else /* STM32F401xE */
  #ifdef USE_STM32L475E_IOT01
  
    #define GPIO_CLK_ENABLE(OPx_GPIO_CLK_ENABLE)    (RCC->AHB2ENR |= (OPx_GPIO_CLK_ENABLE))

    /* GPIO settings for the nSTBY_nRST pins of the L6470 */
    #define L6470_nSTBY_nRST_GPIO_CLK_ENABLE        RCC_AHB2ENR_GPIOAEN   //!< nSTBY_nRST, RCC AHB peripheral clock register
    #define L6470_nSTBY_nRST_GPIO_PORT              GPIOA                 //!< nSTBY_nRST, GPIO Port
    #define L6470_nSTBY_nRST_GPIO_PIN               GPIO_PIN_3            //!< nSTBY_nRST, GPIO Pin

    /* GPIO settings for the nBUSY_SYNC pin of the L6470 */
    #define L6470_nBUSY_SYNC_GPIO_CLK_ENABLE        RCC_AHB2ENR_GPIOCEN   //!< nBUSY_SYNC, RCC AHB1 peripheral clock register
    #define L6470_nBUSY_SYNC_GPIO_PORT              GPIOC                 //!< nSTBY_nRST, GPIO Port
    #define L6470_nBUSY_SYNC_GPIO_PIN               GPIO_PIN_0            //!< nSTBY_nRST, GPIO Pin
    #define L6470_nBUSY_SYNC_IRQn                   EXTI0_IRQn            //!< nSTBY_nRST, IRQ number
    #define L6470_nBUSY_SYNC_EXTI_IRQHandler        EXTI0_IRQHandler      //!< nSTBY_nRST, IRQ handler name

    /* GPIO settings for the nFLAG pin of the L6470 */
    #define L6470_nFLAG_GPIO_CLK_ENABLE             RCC_AHB2ENR_GPIOCEN   //!< nFLAG, RCC AHB1 peripheral clock register
    #define L6470_nFLAG_GPIO_PORT                   GPIOC                 //!< nFLAG, GPIO Port
    #define L6470_nFLAG_GPIO_PIN                    GPIO_PIN_1            //!< nFLAG, GPIO Pin
    #define L6470_nFLAG_IRQn                        EXTI1_IRQn            //!< nFLAG, IRQ number
    #define L6470_nFLAG_EXTI_IRQHandler             EXTI1_IRQHandler      //!< nFLAG, IRQ handler name

    /* GPIO settings for the options about the nCS pins of the L6470 */
    #define L6470_nCS_OP0_GPIO_CLK_ENABLE           RCC_AHB2ENR_GPIOAEN   //!< nCS Option 0, RCC AHB peripheral clock register
    #define L6470_nCS_OP0_GPIO_PORT                 GPIOA                 //!< nCS Option 0, GPIO Port
    #define L6470_nCS_OP0_GPIO_PIN                  GPIO_PIN_2            //!< nCS Option 0, GPIO Pin
 
  #else /* USE_STM32L475E_IOT01 */
    #define GPIO_CLK_ENABLE(OPx_GPIO_CLK_ENABLE)    (RCC->AHB2ENR |= (OPx_GPIO_CLK_ENABLE))

    /* GPIO settings for the nSTBY_nRST pins of the L6470 */
    #define L6470_nSTBY_nRST_GPIO_CLK_ENABLE        RCC_AHB2ENR_GPIOBEN   //!< nSTBY_nRST, RCC AHB peripheral clock register
    #define L6470_nSTBY_nRST_GPIO_PORT              GPIOB                 //!< nSTBY_nRST, GPIO Port
    #define L6470_nSTBY_nRST_GPIO_PIN               GPIO_PIN_5            //!< nSTBY_nRST, GPIO Pin

    /* GPIO settings for the nBUSY_SYNC pin of the L6470 */
    #define L6470_nBUSY_SYNC_GPIO_CLK_ENABLE        RCC_AHB2ENR_GPIOCEN   //!< nBUSY_SYNC, RCC AHB1 peripheral clock register
    #define L6470_nBUSY_SYNC_GPIO_PORT              GPIOC                 //!< nSTBY_nRST, GPIO Port
    #define L6470_nBUSY_SYNC_GPIO_PIN               GPIO_PIN_0            //!< nSTBY_nRST, GPIO Pin
    #define L6470_nBUSY_SYNC_IRQn                   EXTI0_IRQn            //!< nSTBY_nRST, IRQ number
    #define L6470_nBUSY_SYNC_EXTI_IRQHandler        EXTI0_IRQHandler      //!< nSTBY_nRST, IRQ handler name

    /* GPIO settings for the nFLAG pin of the L6470 */
    #define L6470_nFLAG_GPIO_CLK_ENABLE             RCC_AHB2ENR_GPIOCEN   //!< nFLAG, RCC AHB1 peripheral clock register
    #define L6470_nFLAG_GPIO_PORT                   GPIOC                 //!< nFLAG, GPIO Port
    #define L6470_nFLAG_GPIO_PIN                    GPIO_PIN_1            //!< nFLAG, GPIO Pin
    #define L6470_nFLAG_IRQn                        EXTI1_IRQn            //!< nFLAG, IRQ number
    #define L6470_nFLAG_EXTI_IRQHandler             EXTI1_IRQHandler      //!< nFLAG, IRQ handler name

    /* GPIO settings for the options about the nCS pins of the L6470 */
    #define L6470_nCS_OP0_GPIO_CLK_ENABLE           RCC_AHB2ENR_GPIOAEN   //!< nCS Option 0, RCC AHB peripheral clock register
    #define L6470_nCS_OP0_GPIO_PORT                 GPIOA                 //!< nCS Option 0, GPIO Port
    #define L6470_nCS_OP0_GPIO_PIN                  GPIO_PIN_4            //!< nCS Option 0, GPIO Pin
    #define L6470_nCS_OP1_GPIO_CLK_ENABLE           RCC_AHB2ENR_GPIOAEN   //!< nCS Option 1, RCC AHB peripheral clock register
    #define L6470_nCS_OP1_GPIO_PORT                 GPIOA                 //!< nCS Option 1, GPIO Port
    #define L6470_nCS_OP1_GPIO_PIN                  GPIO_PIN_10           //!< nCS Option 1, GPIO Pin
    #define L6470_nCS_OP2_GPIO_CLK_ENABLE           RCC_AHB2ENR_GPIOBEN   //!< nCS Option 2, RCC AHB peripheral clock register
    #define L6470_nCS_OP2_GPIO_PORT                 GPIOB                 //!< nCS Option 2, GPIO Port
    #define L6470_nCS_OP2_GPIO_PIN                  GPIO_PIN_6            //!< nCS Option 2, GPIO Pin
    #define L6470_nCS_OP3_GPIO_CLK_ENABLE           RCC_AHB2ENR_GPIOBEN   //!< nCS Option 3, RCC AHB peripheral clock register
    #define L6470_nCS_OP3_GPIO_PORT                 GPIOB                 //!< nCS Option 3, GPIO Port
    #define L6470_nCS_OP3_GPIO_PIN                  GPIO_PIN_4            //!< nCS Option 3, GPIO Pin   
  #endif /* USE_STM32L475E_IOT01 */
#endif /* STM32F401xE */

/**
  * @brief  The structure to store GPIO information about the NUCLEO board pin
  *         connected with the L6470 one.
  */
typedef struct {
  uint32_t gpio_clk_enable;   //!< RCC AHB peripheral clock register
  GPIO_TypeDef* port;         //!< GPIO Port
  uint16_t pin;               //!< GPIO Pin
} sL6470_GPIO;


extern sL6470_GPIO L6470_nSTBY_nRST_GPIO;
extern sL6470_GPIO L6470_nBUSY_SYNC_GPIO;
extern sL6470_GPIO L6470_nFLAG_GPIO;
extern sL6470_GPIO L6470_nCS_GPIO;
extern sL6470_GPIO L6470_nCS_GPIO_Array[];


void NUCLEO_Board_Init(void);
void User_LED_Blinking(uint8_t repetitions, uint16_t period_ms);


#ifdef __cplusplus
}
#endif

#endif /* __XNUCLEO_INTERFACE_H */
 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
