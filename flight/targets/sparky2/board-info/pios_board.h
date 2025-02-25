/**
 ******************************************************************************
 * @addtogroup TauLabsTargets Tau Labs Targets
 * @{
 * @addtogroup Sparky2 Tau Labs Sparky2 support files
 * @{
 *
 * @file       pios_board.h 
 * @author     Tau Labs, http://taulabs.org, Copyright (C) 2012-2015
 * @brief      Board specific defines
 * @see        The GNU Public License (GPL) Version 3
 * 
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

// Define board variants
#define SPARKY2_V2_0                  0x01
#define BRUSHEDSPARKY_V0_1            0x21
#define BRUSHEDSPARKY_V0_2            0x22

#include <stdbool.h>

//------------------------
// Timers and Channels Used
//------------------------
/*
Timer | Channel 1 | Channel 2 | Channel 3 | Channel 4
------+-----------+-----------+-----------+----------
TIM1  |           |           |           |
TIM2  | --------------- PIOS_DELAY -----------------
TIM3  |           |           |           |
TIM4  |           |           |           |
TIM5  |           |           |           |
TIM6  |           |           |           |
TIM7  |           |           |           |
TIM8  |           |           |           |
------+-----------+-----------+-----------+----------
*/

//------------------------
// DMA Channels Used
//------------------------
/* Channel 1  -                                 */
/* Channel 2  - SPI1 RX                         */
/* Channel 3  - SPI1 TX                         */
/* Channel 4  - SPI2 RX                         */
/* Channel 5  - SPI2 TX                         */
/* Channel 6  -                                 */
/* Channel 7  -                                 */
/* Channel 8  -                                 */
/* Channel 9  -                                 */
/* Channel 10 -                                 */
/* Channel 11 -                                 */
/* Channel 12 -                                 */

//------------------------
// BOOTLOADER_SETTINGS
//------------------------
#define BOARD_READABLE	true
#define BOARD_WRITABLE	true
#define MAX_DEL_RETRYS	3


//------------------------
// PIOS_LED
//------------------------
#define PIOS_LED_HEARTBEAT	0
#define PIOS_LED_ALARM		1
#define PIOS_LED_LINK 		2

//------------------------
// PIOS_WDG
//------------------------
#define PIOS_WATCHDOG_TIMEOUT    250
#define PIOS_WDG_REGISTER        RTC_BKP_DR4

//------------------------
// PIOS_I2C
// See also pios_board.c
//------------------------
#define PIOS_I2C_MAX_DEVS			3
extern uint32_t pios_i2c_mag_pressure_adapter_id;
#define PIOS_I2C_MAIN_ADAPTER			(pios_i2c_mag_pressure_adapter_id)
extern uint32_t pios_i2c_flexiport_adapter_id;
#define PIOS_I2C_FLEXI_ADAPTER			(pios_i2c_flexiport_adapter_id)
#define PIOS_I2C_ETASV3_ADAPTER			(PIOS_I2C_FLEXI_ADAPTER)

//-------------------------
// PIOS_COM
//
// See also pios_board.c
//-------------------------
extern uintptr_t pios_com_telem_serial_id;
extern uintptr_t pios_com_gps_id;
extern uintptr_t pios_com_telem_usb_id;
extern uintptr_t pios_com_bridge_id;
extern uintptr_t pios_com_vcp_id;
extern uintptr_t pios_com_mavlink_id;
extern uintptr_t pios_com_hott_id;
extern uintptr_t pios_com_frsky_sensor_hub_id;
extern uintptr_t pios_com_lighttelemetry_id;
extern uintptr_t pios_com_picoc_id;
extern uintptr_t pios_com_debug_id;
extern uintptr_t pios_com_frsky_sport_id;
extern uintptr_t pios_com_spiflash_logging_id;

#define PIOS_COM_GPS                    (pios_com_gps_id)
#define PIOS_COM_TELEM_USB              (pios_com_telem_usb_id)
#define PIOS_COM_TELEM_RF               (pios_com_telem_serial_id)
#define PIOS_COM_BRIDGE                 (pios_com_bridge_id)
#define PIOS_COM_VCP                    (pios_com_vcp_id)
#define PIOS_COM_MAVLINK                (pios_com_mavlink_id)
#define PIOS_COM_HOTT                   (pios_com_hott_id)
#define PIOS_COM_FRSKY_SENSOR_HUB       (pios_com_frsky_sensor_hub_id)
#define PIOS_COM_LIGHTTELEMETRY         (pios_com_lighttelemetry_id)
#define PIOS_COM_PICOC                  (pios_com_picoc_id)
#define PIOS_COM_DEBUG                  (pios_com_debug_id)
#define PIOS_COM_FRSKY_SPORT            (pios_com_frsky_sport_id)
#define PIOS_COM_OPENLOG                (uintptr_t)(NULL)
#define PIOS_COM_SPIFLASH               (pios_com_spiflash_logging_id)

#define DEBUG_LEVEL 0
#define DEBUG_PRINTF(level, ...) {if(level <= DEBUG_LEVEL && pios_com_debug_id > 0) { PIOS_COM_SendFormattedStringNonBlocking(pios_com_debug_id, __VA_ARGS__); }}

#if defined(PIOS_INCLUDE_RFM22B)
extern uint32_t pios_rfm22b_id;
extern uint32_t pios_spi_telem_flash_id;
#define PIOS_RFM22_SPI_PORT             (pios_spi_telem_flash_id)
#endif /* PIOS_INCLUDE_RFM22B */

//-------------------------
// Packet Handler
//-------------------------
#define RS_ECC_NPARITY 4
#define PIOS_PH_MAX_PACKET 255
#define PIOS_PH_WIN_SIZE 3
#define PIOS_PH_MAX_CONNECTIONS 1
extern uint32_t pios_packet_handler;
#define PIOS_PACKET_HANDLER (pios_packet_handler)

//------------------------
// TELEMETRY 
//------------------------
#define TELEM_QUEUE_SIZE         80
#define PIOS_TELEM_STACK_SIZE    624			

#define PIOS_SYSCLK										168000000
//	Peripherals that belongs to APB1 are:
//	DAC			|PWR				|CAN1,2
//	I2C1,2,3		|UART4,5			|USART3,2
//	I2S3Ext		|SPI3/I2S3		|SPI2/I2S2
//	I2S2Ext		|IWDG				|WWDG
//	RTC/BKP reg	
// TIM2,3,4,5,6,7,12,13,14

// Calculated as SYSCLK / APBPresc * (APBPre == 1 ? 1 : 2)   
// Default APB1 Prescaler = 4 
#define PIOS_PERIPHERAL_APB1_CLOCK					(PIOS_SYSCLK / 2)

//	Peripherals belonging to APB2
//	SDIO			|EXTI				|SYSCFG			|SPI1
//	ADC1,2,3				
//	USART1,6
//	TIM1,8,9,10,11
//
// Default APB2 Prescaler = 2
//
#define PIOS_PERIPHERAL_APB2_CLOCK					PIOS_SYSCLK


//-------------------------
// Interrupt Priorities
//-------------------------
#define PIOS_IRQ_PRIO_LOW                       12              // lower than RTOS
#define PIOS_IRQ_PRIO_MID                       8               // higher than RTOS
#define PIOS_IRQ_PRIO_HIGH                      5               // for SPI, ADC, I2C etc...
#define PIOS_IRQ_PRIO_HIGHEST                   4               // for USART etc...

//------------------------
// PIOS_RCVR
// See also pios_board.c
//------------------------
#define PIOS_RCVR_MAX_CHANNELS       12
#define PIOS_GCSRCVR_TIMEOUT_MS      100

//-------------------------
// Receiver PPM input
//-------------------------
#define PIOS_PPM_NUM_INPUTS          12

//-------------------------
// Receiver PWM input
//-------------------------
#define PIOS_PWM_NUM_INPUTS          8

//-------------------------
// Receiver SPEKTRUM input
//-------------------------
#define PIOS_SPEKTRUM_NUM_INPUTS     12

//-------------------------
// Receiver S.Bus input
//-------------------------
#define PIOS_SBUS_NUM_INPUTS         (16+2)

//-------------------------
// Receiver DSM input
//-------------------------
#define PIOS_DSM_NUM_INPUTS			12

//-------------------------
// Receiver HSUM input
//-------------------------
#define PIOS_HSUM_MAX_DEVS		2
#define PIOS_HSUM_NUM_INPUTS		32

//-------------------------
// Servo outputs
//-------------------------
#define PIOS_SERVO_UPDATE_HZ                    50
#define PIOS_SERVOS_INITIAL_POSITION            0 /* dont want to start motors, have no pulse till settings loaded */

//--------------------------
// Timer controller settings
//--------------------------
#define PIOS_TIM_MAX_DEVS			6

//-------------------------
// ADC
//-------------------------
#define PIOS_ADC_MAX_OVERSAMPLING       2
#define VREF_PLUS                     3.3

//-------------------------
// USB
//-------------------------
#define PIOS_USB_ENABLED                        1 /* Should remove all references to this */

//-------------------------
// ADC
//-------------------------
#define PIOS_ADC_SUB_DRIVER_MAX_INSTANCES       3

/**
 * @}
 * @}
 */
