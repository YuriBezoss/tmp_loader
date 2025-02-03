/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    octospi.h
  * @brief   This file contains all the function prototypes for
  *          the octospi.c file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __OCTOSPI_H__
#define __OCTOSPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

extern XSPI_HandleTypeDef hospi1;

/* USER CODE BEGIN Private defines */
uint8_t CSP_OCTOSPI_Init(void);
uint8_t CSP_OSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress);
uint8_t CSP_OSPI_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size);
uint8_t CSP_OSPI_EnableMemoryMappedMode(void);
uint8_t CSP_OSPI_Erase_Chip (void);
/* USER CODE END Private defines */

void MX_OCTOSPI1_Init(void);

/* USER CODE BEGIN Prototypes */
/*MX25L512 memory parameters*/
#define MEMORY_FLASH_SIZE               0x4000000 /* 512 MBits => 64MBytes */
#define MEMORY_BLOCK_SIZE               0x10000   /* 1024 sectors of 64KBytes */
#define MEMORY_SECTOR_SIZE              0x1000    /* 16384 subsectors of 4kBytes */
#define MEMORY_PAGE_SIZE                0x100     /* 262144 pages of 256 bytes */


/*MX25L512 commands */
#define WRITE_ENABLE_CMD 		0x06
#define READ_STATUS_REG_CMD 	0x05
#define WRITE_STATUS_REG_CMD 	0x01
#define SECTOR_ERASE_CMD 		0x20
#define CHIP_ERASE_CMD 			0xC7
//#define QUAD_IN_FAST_PROG_CMD 	0x38
#define READ_CONFIGURATION_REG_CMD 0x15
//#define QUAD_READ_IO_CMD 		0xEC
//#define QUAD_OUT_FAST_READ_CMD 0x6B
//#define QPI_ENABLE_CMD 			0x35
//#define DUMMY_CLOCK_CYCLES_READ_QUAD 10
#define RESET_ENABLE_CMD 		0x66
#define RESET_EXECUTE_CMD 		0x99
//#define DISABLE_QIP_MODE 		0xf5

/* MX25LM512ABA1G12 Macronix memory */
/* Size of the flash */
#define OSPI_FLASH_SIZE             26
#define OSPI_PAGE_SIZE              256

/* Flash commands */
#define OCTAL_IO_READ_CMD           0xEC13
#define OCTAL_PAGE_PROG_CMD         0x12ED
//#define OCTAL_READ_STATUS_REG_CMD   0x05FA
//#define OCTAL_SECTOR_ERASE_CMD      0x21DE
//#define OCTAL_WRITE_ENABLE_CMD      0x06F9
#define READ_STATUS_REG_CMD         0x05
#define WRITE_CFG_REG_2_CMD         0x72
#define WRITE_ENABLE_CMD            0x06

/* Dummy clocks cycles */
#define DUMMY_CLOCK_CYCLES_READ     6
#define DUMMY_CLOCK_CYCLES_READ_REG 4

/* Auto-polling values */
#define WRITE_ENABLE_MATCH_VALUE    0x02
#define WRITE_ENABLE_MASK_VALUE     0x02

#define MEMORY_READY_MATCH_VALUE    0x00
#define MEMORY_READY_MASK_VALUE     0x01

#define AUTO_POLLING_INTERVAL       0x10

/* Memory registers address */
#define CONFIG_REG2_ADDR1           0x0000000
#define CR2_STR_OPI_ENABLE          0x01

#define CONFIG_REG2_ADDR3           0x00000300
#define CR2_DUMMY_CYCLES_66MHZ      0x07

/* Memory delay */
#define MEMORY_REG_WRITE_DELAY      40
#define MEMORY_PAGE_PROG_DELAY      2

/* End address of the OSPI memory */
#define OSPI_END_ADDR               (1 << OSPI_FLASH_SIZE)

/* Size of buffers */
#define BUFFERSIZE                  (COUNTOF(aTxBuffer) - 1)
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define COUNTOF(__BUFFER__)         (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))
/* USER CODE END EM */
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __OCTOSPI_H__ */

