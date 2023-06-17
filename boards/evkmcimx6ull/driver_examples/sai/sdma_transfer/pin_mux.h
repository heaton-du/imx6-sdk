/*
 * Copyright (c) 2015-2016, Freescale Semiconductor, Inc.
 * Copyright 2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

#include "board.h"

/* UART1_RX_DATA (coord K16), UART1_RXD */
#define BOARD_INITPINS_UART1_RXD_PERIPHERAL                                UART1   /*!< Device name: UART1 */
#define BOARD_INITPINS_UART1_RXD_SIGNAL                                  uart_rx   /*!< UART1 signal: uart_rx */
#define BOARD_INITPINS_UART1_RXD_PIN_NAME                          UART1_RX_DATA   /*!< Pin name */
#define BOARD_INITPINS_UART1_RXD_LABEL                               "UART1_RXD"   /*!< Label */
#define BOARD_INITPINS_UART1_RXD_NAME                                "UART1_RXD"   /*!< Identifier name */

/* UART1_TX_DATA (coord K14), UART1_TXD */
#define BOARD_INITPINS_UART1_TXD_PERIPHERAL                                UART1   /*!< Device name: UART1 */
#define BOARD_INITPINS_UART1_TXD_SIGNAL                                  uart_tx   /*!< UART1 signal: uart_tx */
#define BOARD_INITPINS_UART1_TXD_PIN_NAME                          UART1_TX_DATA   /*!< Pin name */
#define BOARD_INITPINS_UART1_TXD_LABEL                               "UART1_TXD"   /*!< Label */
#define BOARD_INITPINS_UART1_TXD_NAME                                "UART1_TXD"   /*!< Identifier name */

/* JTAG_TMS (coord P14), SAI2_MCLK */
#define BOARD_INITPINS_SAI2_MCLK_PERIPHERAL                                 SAI2   /*!< Device name: SAI2 */
#define BOARD_INITPINS_SAI2_MCLK_SIGNAL                                 sai_mclk   /*!< SAI2 signal: sai_mclk */
#define BOARD_INITPINS_SAI2_MCLK_PIN_NAME                               JTAG_TMS   /*!< Pin name */
#define BOARD_INITPINS_SAI2_MCLK_LABEL                               "SAI2_MCLK"   /*!< Label */
#define BOARD_INITPINS_SAI2_MCLK_NAME                                "SAI2_MCLK"   /*!< Identifier name */

/* JTAG_TRST_B (coord N14), SAI2_TXD */
#define BOARD_INITPINS_SAI2_TXD_PERIPHERAL                                  SAI2   /*!< Device name: SAI2 */
#define BOARD_INITPINS_SAI2_TXD_SIGNAL                               sai_tx_data   /*!< SAI2 signal: sai_tx_data */
#define BOARD_INITPINS_SAI2_TXD_PIN_NAME                             JTAG_TRST_B   /*!< Pin name */
#define BOARD_INITPINS_SAI2_TXD_LABEL                                 "SAI2_TXD"   /*!< Label */
#define BOARD_INITPINS_SAI2_TXD_NAME                                  "SAI2_TXD"   /*!< Identifier name */

/* JTAG_TDO (coord N15), SAI2_SYNC */
#define BOARD_INITPINS_SAI2_SYNC_PERIPHERAL                                 SAI2   /*!< Device name: SAI2 */
#define BOARD_INITPINS_SAI2_SYNC_SIGNAL                              sai_tx_sync   /*!< SAI2 signal: sai_tx_sync */
#define BOARD_INITPINS_SAI2_SYNC_PIN_NAME                               JTAG_TDO   /*!< Pin name */
#define BOARD_INITPINS_SAI2_SYNC_LABEL                               "SAI2_SYNC"   /*!< Label */
#define BOARD_INITPINS_SAI2_SYNC_NAME                                "SAI2_SYNC"   /*!< Identifier name */

/* JTAG_TDI (coord N16), SAI2_BCLK */
#define BOARD_INITPINS_SAI2_BCLK_PERIPHERAL                                 SAI2   /*!< Device name: SAI2 */
#define BOARD_INITPINS_SAI2_BCLK_SIGNAL                              sai_tx_bclk   /*!< SAI2 signal: sai_tx_bclk */
#define BOARD_INITPINS_SAI2_BCLK_PIN_NAME                               JTAG_TDI   /*!< Pin name */
#define BOARD_INITPINS_SAI2_BCLK_LABEL                               "SAI2_BCLK"   /*!< Label */
#define BOARD_INITPINS_SAI2_BCLK_NAME                                "SAI2_BCLK"   /*!< Identifier name */

/* UART5_TX_DATA (coord F17), I2C2_SCL */
#define BOARD_INITPINS_I2C2_SCL_GPIO                                       GPIO1   /*!< GPIO device name: GPIO1 */
#define BOARD_INITPINS_I2C2_SCL_GPIO_PIN                                     30U   /*!< GPIO1 pin index: 30 */
#define BOARD_INITPINS_I2C2_SCL_PIN_NAME                           UART5_TX_DATA   /*!< Pin name */
#define BOARD_INITPINS_I2C2_SCL_LABEL                                 "I2C2_SCL"   /*!< Label */
#define BOARD_INITPINS_I2C2_SCL_NAME                                  "I2C2_SCL"   /*!< Identifier name */

/* UART5_RX_DATA (coord G13), I2C2_SDA */
#define BOARD_INITPINS_I2C2_SDA_GPIO                                       GPIO1   /*!< GPIO device name: GPIO1 */
#define BOARD_INITPINS_I2C2_SDA_GPIO_PIN                                     31U   /*!< GPIO1 pin index: 31 */
#define BOARD_INITPINS_I2C2_SDA_PIN_NAME                           UART5_RX_DATA   /*!< Pin name */
#define BOARD_INITPINS_I2C2_SDA_LABEL                                 "I2C2_SDA"   /*!< Label */
#define BOARD_INITPINS_I2C2_SDA_NAME                                  "I2C2_SDA"   /*!< Identifier name */

/* UART5_TX_DATA (coord F17), I2C2_SCL */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_PERIPHERAL                         I2C2   /*!< Device name: I2C2 */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_SIGNAL                          i2c_scl   /*!< I2C2 signal: i2c_scl */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_PIN_NAME                  UART5_TX_DATA   /*!< Pin name */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_LABEL                        "I2C2_SCL"   /*!< Label */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SCL_NAME                         "I2C2_SCL"   /*!< Identifier name */

/* UART5_RX_DATA (coord G13), I2C2_SDA */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_PERIPHERAL                         I2C2   /*!< Device name: I2C2 */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_SIGNAL                          i2c_sda   /*!< I2C2 signal: i2c_sda */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_PIN_NAME                  UART5_RX_DATA   /*!< Pin name */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_LABEL                        "I2C2_SDA"   /*!< Label */
#define BOARD_I2C_CONFIGUREPINS_I2C2_SDA_NAME                         "I2C2_SDA"   /*!< Identifier name */

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/*!
 * @brief Initialize I2C pins.
 *
 */
void BOARD_I2C_ConfigurePins(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PIN_MUX_H_ */
