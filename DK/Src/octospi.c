/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    octospi.c
  * @brief   This file provides code for the configuration
  *          of the OCTOSPI instances.
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
/* Includes ------------------------------------------------------------------*/
#include "octospi.h"

/* USER CODE BEGIN 0 */
static uint8_t OSPI_WriteEnable(void);
static uint8_t OSPI_AutoPollingMemReady(void);
static uint8_t OSPI_Configuration(void);
static uint8_t OSPI_ResetChip(void);
/* USER CODE END 0 */

XSPI_HandleTypeDef hospi1;

/* OCTOSPI1 init function */
void MX_OCTOSPI1_Init(void)
{

  /* USER CODE BEGIN OCTOSPI1_Init 0 */

  /* USER CODE END OCTOSPI1_Init 0 */

  /* USER CODE BEGIN OCTOSPI1_Init 1 */

  /* USER CODE END OCTOSPI1_Init 1 */
  hospi1.Instance = OCTOSPI1;
  hospi1.Init.FifoThresholdByte = 4;
  hospi1.Init.MemoryMode = HAL_XSPI_SINGLE_MEM;
  hospi1.Init.MemoryType = HAL_XSPI_MEMTYPE_MACRONIX;
  hospi1.Init.MemorySize = HAL_XSPI_SIZE_256MB;
  hospi1.Init.ChipSelectHighTimeCycle = 1;
  hospi1.Init.FreeRunningClock = HAL_XSPI_FREERUNCLK_DISABLE;
  hospi1.Init.ClockMode = HAL_XSPI_CLOCK_MODE_0;
  hospi1.Init.WrapSize = HAL_XSPI_WRAP_NOT_SUPPORTED;
  hospi1.Init.ClockPrescaler = 1;
  hospi1.Init.SampleShifting = HAL_XSPI_SAMPLE_SHIFT_NONE;
  hospi1.Init.DelayHoldQuarterCycle = HAL_XSPI_DHQC_ENABLE;
  hospi1.Init.ChipSelectBoundary = HAL_XSPI_BONDARYOF_NONE;
  hospi1.Init.DelayBlockBypass = HAL_XSPI_DELAY_BLOCK_BYPASS;
  hospi1.Init.Refresh = 0;
  if (HAL_XSPI_Init(&hospi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN OCTOSPI1_Init 2 */

  /* USER CODE END OCTOSPI1_Init 2 */

}

void HAL_XSPI_MspInit(XSPI_HandleTypeDef* xspiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
  if(xspiHandle->Instance==OCTOSPI1)
  {
  /* USER CODE BEGIN OCTOSPI1_MspInit 0 */

  /* USER CODE END OCTOSPI1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_OSPI;
    PeriphClkInitStruct.PLL2.PLL2Source = RCC_PLL2_SOURCE_HSI;
    PeriphClkInitStruct.PLL2.PLL2M = 8;
    PeriphClkInitStruct.PLL2.PLL2N = 45;
    PeriphClkInitStruct.PLL2.PLL2P = 2;
    PeriphClkInitStruct.PLL2.PLL2Q = 2;
    PeriphClkInitStruct.PLL2.PLL2R = 2;
    PeriphClkInitStruct.PLL2.PLL2RGE = RCC_PLL2_VCIRANGE_3;
    PeriphClkInitStruct.PLL2.PLL2VCOSEL = RCC_PLL2_VCORANGE_WIDE;
    PeriphClkInitStruct.PLL2.PLL2FRACN = 0;
    PeriphClkInitStruct.PLL2.PLL2ClockOut = RCC_PLL2_DIVR;
    PeriphClkInitStruct.OspiClockSelection = RCC_OSPICLKSOURCE_PLL2R;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    /* OCTOSPI1 clock enable */
    __HAL_RCC_OSPI1_CLK_ENABLE();

    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    /**OCTOSPI1 GPIO Configuration
    PG9     ------> OCTOSPI1_IO6
    PF10     ------> OCTOSPI1_CLK
    PG6     ------> OCTOSPI1_NCS
    PC2     ------> OCTOSPI1_IO2
    PD12     ------> OCTOSPI1_IO1
    PC0     ------> OCTOSPI1_IO7
    PD13     ------> OCTOSPI1_IO3
    PB1     ------> OCTOSPI1_IO0
    PH3     ------> OCTOSPI1_IO5
    PB2     ------> OCTOSPI1_DQS
    PH2     ------> OCTOSPI1_IO4
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPI1;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPI1;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OCTOSPI1;
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPI1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPI1;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OCTOSPI1;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_1;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF6_OCTOSPI1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_OCTOSPI1;
    HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_OCTOSPI1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* OCTOSPI1 interrupt Init */
    HAL_NVIC_SetPriority(OCTOSPI1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(OCTOSPI1_IRQn);
  /* USER CODE BEGIN OCTOSPI1_MspInit 1 */

  /* USER CODE END OCTOSPI1_MspInit 1 */
  }
}

void HAL_XSPI_MspDeInit(XSPI_HandleTypeDef* xspiHandle)
{

  if(xspiHandle->Instance==OCTOSPI1)
  {
  /* USER CODE BEGIN OCTOSPI1_MspDeInit 0 */

  /* USER CODE END OCTOSPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_OSPI1_CLK_DISABLE();

    /**OCTOSPI1 GPIO Configuration
    PG9     ------> OCTOSPI1_IO6
    PF10     ------> OCTOSPI1_CLK
    PG6     ------> OCTOSPI1_NCS
    PC2     ------> OCTOSPI1_IO2
    PD12     ------> OCTOSPI1_IO1
    PC0     ------> OCTOSPI1_IO7
    PD13     ------> OCTOSPI1_IO3
    PB1     ------> OCTOSPI1_IO0
    PH3     ------> OCTOSPI1_IO5
    PB2     ------> OCTOSPI1_DQS
    PH2     ------> OCTOSPI1_IO4
    */
    HAL_GPIO_DeInit(GPIOG, GPIO_PIN_9|GPIO_PIN_6);

    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_10);

    HAL_GPIO_DeInit(GPIOC, GPIO_PIN_2|GPIO_PIN_0);

    HAL_GPIO_DeInit(GPIOD, GPIO_PIN_12|GPIO_PIN_13);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_1|GPIO_PIN_2);

    HAL_GPIO_DeInit(GPIOH, GPIO_PIN_3|GPIO_PIN_2);

    /* OCTOSPI1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(OCTOSPI1_IRQn);
  /* USER CODE BEGIN OCTOSPI1_MspDeInit 1 */

  /* USER CODE END OCTOSPI1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */
/* QUADSPI init function */
uint8_t
CSP_OCTOSPI_Init(void) {
    //prepare QSPI peripheral for ST-Link Utility operations
    if (HAL_XSPI_DeInit(&hospi1) != HAL_OK) {
        return HAL_ERROR;
    }
    MX_OCTOSPI1_Init();
    if (OSPI_ResetChip() != HAL_OK) {
        return HAL_ERROR;
    }
    HAL_Delay(1);
    if (OSPI_AutoPollingMemReady() != HAL_OK) {
        return HAL_ERROR;
    }
    if (OSPI_WriteEnable() != HAL_OK) {
        return HAL_ERROR;
    }
    if (OSPI_Configuration() != HAL_OK) {
        return HAL_ERROR;
    }
    return HAL_OK;
}

uint8_t
CSP_OSPI_Erase_Chip(void) {
	XSPI_RegularCmdTypeDef  sCommand = {0};
	XSPI_AutoPollingTypeDef sConfig = {0};

    if (OSPI_WriteEnable() != HAL_OK) {
        return HAL_ERROR;
    }

    /* Erasing Sequence --------------------------------- */
    sCommand.Instruction 		= CHIP_ERASE_CMD;
    sCommand.InstructionMode 	= HAL_XSPI_INSTRUCTION_1_LINE;
    sCommand.InstructionWidth   = HAL_XSPI_INSTRUCTION_8_BITS;
    sCommand.InstructionDTRMode = HAL_XSPI_INSTRUCTION_DTR_DISABLE;

    sCommand.Address       		= 0;
    sCommand.AddressWidth       = HAL_XSPI_ADDRESS_32_BITS;
    sCommand.AddressMode 		= HAL_XSPI_ADDRESS_NONE;
    sCommand.AddressDTRMode     = HAL_XSPI_ADDRESS_DTR_DISABLE;

    sCommand.AlternateBytesMode = HAL_XSPI_ALT_BYTES_NONE;
    sCommand.DQSMode            = HAL_XSPI_DQS_DISABLE;
    sCommand.SIOOMode           = HAL_XSPI_SIOO_INST_EVERY_CMD;
    sCommand.DummyCycles 		= 0;

    sCommand.DataMode 			= HAL_XSPI_DATA_NONE;
    sCommand.DataDTRMode        = HAL_XSPI_DATA_DTR_DISABLE;

    if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
        return HAL_ERROR;
    }
    if (OSPI_AutoPollingMemReady() != HAL_OK) {
        return HAL_ERROR;
    }
    return HAL_OK;
}

uint8_t
OSPI_AutoPollingMemReady(void) {

	XSPI_RegularCmdTypeDef  sCommand = {0};
	XSPI_AutoPollingTypeDef sConfig = {0};

    /* Configure automatic polling mode to wait for memory ready ------ */
	sCommand.OperationType      = HAL_XSPI_OPTYPE_COMMON_CFG;

	sCommand.Instruction        = READ_STATUS_REG_CMD;
	sCommand.InstructionMode    = HAL_XSPI_INSTRUCTION_1_LINE;
	sCommand.InstructionWidth   = HAL_XSPI_INSTRUCTION_8_BITS;
	sCommand.InstructionDTRMode = HAL_XSPI_INSTRUCTION_DTR_DISABLE;

	sCommand.Address            = 0x0;
	sCommand.AddressMode        = HAL_XSPI_ADDRESS_NONE;
	sCommand.AddressWidth       = HAL_XSPI_ADDRESS_32_BITS;
	sCommand.AddressDTRMode     = HAL_XSPI_ADDRESS_DTR_DISABLE;

	sCommand.AlternateBytesMode = HAL_XSPI_ALT_BYTES_NONE;

	sCommand.DataMode           = HAL_XSPI_DATA_1_LINE;
	sCommand.DataDTRMode        = HAL_XSPI_DATA_DTR_DISABLE;
	sCommand.DataLength         = 1;

	sCommand.DummyCycles        = 0;
	sCommand.DQSMode            = HAL_XSPI_DQS_DISABLE;
	sCommand.SIOOMode           = HAL_XSPI_SIOO_INST_EVERY_CMD;

	if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
		return HAL_ERROR;
	}

    sConfig.MatchValue    = 0x00;
    sConfig.MatchMask     = 0x01;
    sConfig.MatchMode     = HAL_XSPI_MATCH_MODE_AND;
    sConfig.IntervalTime  = 0x10;
    sConfig.AutomaticStop = HAL_XSPI_AUTOMATIC_STOP_ENABLE;

    if (HAL_XSPI_AutoPolling(&hospi1, &sConfig, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
    	return HAL_ERROR;
    }

    return HAL_OK;
}

static uint8_t
OSPI_WriteEnable(void) {
	XSPI_RegularCmdTypeDef  sCommand = {0};
	XSPI_AutoPollingTypeDef sConfig = {0};

    /* Enable write operations ------------------------------------------ */
	sCommand.OperationType      = HAL_XSPI_OPTYPE_COMMON_CFG;
	sCommand.Instruction        = WRITE_ENABLE_CMD;
	sCommand.InstructionMode    = HAL_XSPI_INSTRUCTION_1_LINE;
	sCommand.InstructionWidth   = HAL_XSPI_INSTRUCTION_8_BITS;
	sCommand.InstructionDTRMode = HAL_XSPI_INSTRUCTION_DTR_DISABLE;
	sCommand.AddressMode        = HAL_XSPI_ADDRESS_NONE;
	sCommand.AlternateBytesMode = HAL_XSPI_ALT_BYTES_NONE;
	sCommand.DataMode           = HAL_XSPI_DATA_NONE;
	sCommand.DummyCycles        = 0;
	sCommand.DQSMode            = HAL_XSPI_DQS_DISABLE;
	sCommand.SIOOMode           = HAL_XSPI_SIOO_INST_EVERY_CMD;

    if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
        return HAL_ERROR;
    }

    /* Configure automatic polling mode to wait for write enabling ---- */
    sCommand.Instruction    = READ_STATUS_REG_CMD;
    sCommand.DataMode       = HAL_XSPI_DATA_1_LINE;
    sCommand.DataDTRMode    = HAL_XSPI_DATA_DTR_DISABLE;
    sCommand.DataLength     = 1;

    if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
    	return HAL_ERROR;
    }

    /* Configure automatic polling mode to wait for write enabling ---- */
    sConfig.MatchValue    = 0x02;
    sConfig.MatchMask     = 0x02;
    sConfig.MatchMode     = HAL_XSPI_MATCH_MODE_AND;
    sConfig.IntervalTime  = 0x10;
    sConfig.AutomaticStop = HAL_XSPI_AUTOMATIC_STOP_ENABLE;

    if (HAL_XSPI_AutoPolling(&hospi1, &sConfig, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
    	return HAL_ERROR;
    }

    return HAL_OK;
}

/* Enable Octal mode and set dummy cycles count */
uint8_t
OSPI_Configuration(void) {
	XSPI_RegularCmdTypeDef  sCommand = {0};
	  XSPI_AutoPollingTypeDef sConfig = {0};
	  uint8_t reg;

	  /* Enable write operations ---------------------------------------- */
	  sCommand.OperationType      = HAL_XSPI_OPTYPE_COMMON_CFG;
	  sCommand.Instruction        = WRITE_ENABLE_CMD;
	  sCommand.InstructionMode    = HAL_XSPI_INSTRUCTION_1_LINE;
	  sCommand.InstructionWidth   = HAL_XSPI_INSTRUCTION_8_BITS;
	  sCommand.InstructionDTRMode = HAL_XSPI_INSTRUCTION_DTR_DISABLE;
	  sCommand.AddressMode        = HAL_XSPI_ADDRESS_NONE;
	  sCommand.AlternateBytesMode = HAL_XSPI_ALT_BYTES_NONE;
	  sCommand.DataMode           = HAL_XSPI_DATA_NONE;
	  sCommand.DummyCycles        = 0;
	  sCommand.DQSMode            = HAL_XSPI_DQS_DISABLE;
	  sCommand.SIOOMode           = HAL_XSPI_SIOO_INST_EVERY_CMD;

	  if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  /* Configure automatic polling mode to wait for write enabling ---- */
	  sCommand.Instruction = READ_STATUS_REG_CMD;
	  sCommand.DataMode    = HAL_XSPI_DATA_1_LINE;
	  sCommand.DataDTRMode = HAL_XSPI_DATA_DTR_DISABLE;
	  sCommand.DataLength  = 1;

	  if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  sConfig.MatchValue    = WRITE_ENABLE_MATCH_VALUE;
	  sConfig.MatchMask     = WRITE_ENABLE_MASK_VALUE;
	  sConfig.MatchMode     = HAL_XSPI_MATCH_MODE_AND;
	  sConfig.IntervalTime  = AUTO_POLLING_INTERVAL;
	  sConfig.AutomaticStop = HAL_XSPI_AUTOMATIC_STOP_ENABLE;

	  if (HAL_XSPI_AutoPolling(&hospi1, &sConfig, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  /* Write Configuration register 2 (with new dummy cycles) --------- */
	  sCommand.Instruction    = WRITE_CFG_REG_2_CMD;
	  sCommand.Address        = CONFIG_REG2_ADDR3;
	  sCommand.AddressMode    = HAL_XSPI_ADDRESS_1_LINE;
	  sCommand.AddressWidth   = HAL_XSPI_ADDRESS_32_BITS;
	  sCommand.AddressDTRMode = HAL_XSPI_ADDRESS_DTR_DISABLE;

	  if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  reg = 0x07;

	  if (HAL_XSPI_Transmit(&hospi1, &reg, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  /* Wait that the memory is ready ---------------------------------- */
	  sCommand.Instruction = READ_STATUS_REG_CMD;
	  sCommand.AddressMode = HAL_XSPI_ADDRESS_NONE;

	  if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  sConfig.MatchValue = MEMORY_READY_MATCH_VALUE;
	  sConfig.MatchMask  = MEMORY_READY_MASK_VALUE;

	  if (HAL_XSPI_AutoPolling(&hospi1, &sConfig, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  /* Enable write operations ---------------------------------------- */
	  sCommand.Instruction = WRITE_ENABLE_CMD;
	  sCommand.DataMode    = HAL_XSPI_DATA_NONE;

	  if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  /* Configure automatic polling mode to wait for write enabling ---- */
	  sCommand.Instruction = READ_STATUS_REG_CMD;
	  sCommand.DataMode    = HAL_XSPI_DATA_1_LINE;

	  if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  sConfig.MatchValue = WRITE_ENABLE_MATCH_VALUE;
	  sConfig.MatchMask  = WRITE_ENABLE_MASK_VALUE;

	  if (HAL_XSPI_AutoPolling(&hospi1, &sConfig, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  /* Write Configuration register 2 (with octal mode) --------------- */
	  sCommand.Instruction = WRITE_CFG_REG_2_CMD;
	  sCommand.Address     = CONFIG_REG2_ADDR1;
	  sCommand.AddressMode = HAL_XSPI_ADDRESS_1_LINE;

	  if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  reg = 0x01;

	  if (HAL_XSPI_Transmit(&hospi1, &reg, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	  {
		  return HAL_ERROR;
	  }

	  /* Wait that the configuration is effective and check that memory is ready */
	  HAL_Delay(MEMORY_REG_WRITE_DELAY);

	  /* Wait that the memory is ready ---------------------------------- */
	  OSPI_AutoPollingMemReady();

	  return HAL_OK;
}

uint8_t
CSP_OSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress) {
	XSPI_RegularCmdTypeDef  sCommand = {0};
	XSPI_AutoPollingTypeDef sConfig = {0};

    EraseStartAddress = EraseStartAddress
                        - EraseStartAddress % MEMORY_SECTOR_SIZE;

    /* Erasing Sequence -------------------------------------------------- */
    sCommand.Instruction 		= SECTOR_ERASE_CMD;
    sCommand.InstructionMode 	= HAL_XSPI_INSTRUCTION_1_LINE;
    sCommand.InstructionWidth   = HAL_XSPI_INSTRUCTION_8_BITS;
    sCommand.InstructionDTRMode = HAL_XSPI_INSTRUCTION_DTR_DISABLE;

    sCommand.AddressWidth       = HAL_XSPI_ADDRESS_32_BITS;
    sCommand.AddressMode 		= HAL_XSPI_ADDRESS_1_LINE;
    sCommand.AddressDTRMode     = HAL_XSPI_ADDRESS_DTR_DISABLE;

    sCommand.AlternateBytesMode = HAL_XSPI_ALT_BYTES_NONE;
    sCommand.DQSMode            = HAL_XSPI_DQS_DISABLE;
    sCommand.SIOOMode           = HAL_XSPI_SIOO_INST_EVERY_CMD;
    sCommand.DummyCycles 		= 0;

    sCommand.DataMode 			= HAL_XSPI_DATA_NONE;
    sCommand.DataDTRMode        = HAL_XSPI_DATA_DTR_DISABLE;

    while (EraseEndAddress >= EraseStartAddress) {
        sCommand.Address = (EraseStartAddress & 0x0FFFFFFF);
        if (OSPI_WriteEnable() != HAL_OK) {
            return HAL_ERROR;
        }
        if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
            return HAL_ERROR;
        }
        EraseStartAddress += MEMORY_SECTOR_SIZE;
        if (OSPI_AutoPollingMemReady() != HAL_OK) {
            return HAL_ERROR;
        }
    }

    return HAL_OK;
}

uint8_t
CSP_OSPI_WriteMemory(uint8_t* buffer, uint32_t address, uint32_t buffer_size) {
	XSPI_RegularCmdTypeDef  sCommand = {0};
    uint32_t end_addr, current_size, current_addr;

    /* Calculation of the size between the write address and the end of the page */
    current_addr = 0;

    //
    while (current_addr <= address) {
        current_addr += MEMORY_PAGE_SIZE;
    }
    current_size = current_addr - address;

    /* Check if the size of the data is less than the remaining place in the page */
    if (current_size > buffer_size) {
        current_size = buffer_size;
    }

    /* Initialize the adress variables */
    current_addr = address;
    end_addr = address + buffer_size;

    sCommand.OperationType      = HAL_XSPI_OPTYPE_COMMON_CFG;
    sCommand.Instruction        = OCTAL_PAGE_PROG_CMD;
    sCommand.InstructionMode    = HAL_XSPI_INSTRUCTION_8_LINES;
    sCommand.InstructionWidth   = HAL_XSPI_INSTRUCTION_16_BITS;
    sCommand.InstructionDTRMode = HAL_XSPI_INSTRUCTION_DTR_ENABLE;
    sCommand.AddressMode        = HAL_XSPI_ADDRESS_8_LINES;
    sCommand.AddressWidth       = HAL_XSPI_ADDRESS_32_BITS;
    sCommand.AddressDTRMode     = HAL_XSPI_ADDRESS_DTR_ENABLE;
    sCommand.AlternateBytesMode = HAL_XSPI_ALT_BYTES_NONE;
    sCommand.DataDTRMode        = HAL_XSPI_DATA_DTR_ENABLE;
    sCommand.DataLength  		= buffer_size;
    sCommand.SIOOMode           = HAL_XSPI_SIOO_INST_EVERY_CMD;
    sCommand.DataMode           = HAL_XSPI_DATA_8_LINES;
    sCommand.Address            = address;
    sCommand.DummyCycles        = 0;
    sCommand.DQSMode            = HAL_XSPI_DQS_DISABLE;

    /* Perform the write page by page */
    do {
        sCommand.Address = current_addr;
        sCommand.DataLength = current_size;

        if (current_size == 0) {
            return HAL_OK;
        }

        /* Enable write operations */
        if (OSPI_WriteEnable() != HAL_OK) {
            return HAL_ERROR;
        }

        /* Configure the command */
        if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
            return HAL_ERROR;
        }

        /* Transmission of the data */
        if (HAL_XSPI_Transmit(&hospi1, buffer, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
            return HAL_ERROR;
        }

        /* Configure automatic polling mode to wait for end of program */
        if (OSPI_AutoPollingMemReady() != HAL_OK) {
            return HAL_ERROR;
        }

        /* Update the address and size variables for next page programming */
        current_addr += current_size;
        buffer += current_size;
        current_size = ((current_addr + MEMORY_PAGE_SIZE) > end_addr) ? (end_addr - current_addr) : MEMORY_PAGE_SIZE;
    } while (current_addr <= end_addr);

    return HAL_OK;
}

uint8_t
CSP_OSPI_EnableMemoryMappedMode(void) {
	XSPI_RegularCmdTypeDef  sCommand = {0};
	XSPI_MemoryMappedTypeDef sMemMappedCfg = {0};

    /* Configure automatic polling mode to wait for end of erase ------ */
    OSPI_AutoPollingMemReady();

    /* Enable write operations ---------------------------------------- */
    OSPI_WriteEnable();

    /* Memory-mapped mode configuration ------------------------------- */
    sCommand.OperationType = HAL_XSPI_OPTYPE_WRITE_CFG;
    sCommand.Instruction   = OCTAL_PAGE_PROG_CMD;
    sCommand.DataMode      = HAL_XSPI_DATA_8_LINES;
    sCommand.DataLength    = 1;
    sCommand.DQSMode       = HAL_XSPI_DQS_ENABLE;

    if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
    	return HAL_ERROR;
    }

    sCommand.OperationType = HAL_XSPI_OPTYPE_READ_CFG;
    sCommand.Instruction   = OCTAL_IO_READ_CMD;
    sCommand.DummyCycles   = DUMMY_CLOCK_CYCLES_READ;
    sCommand.DQSMode       = HAL_XSPI_DQS_DISABLE;

    if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
    	return HAL_ERROR;
    }

    sMemMappedCfg.TimeOutActivation  = HAL_XSPI_TIMEOUT_COUNTER_ENABLE;
    sMemMappedCfg.TimeoutPeriodClock = 0x50;
    if (HAL_XSPI_MemoryMapped(&hospi1, &sMemMappedCfg) != HAL_OK)
    {
    	return HAL_ERROR;
    }
    return HAL_OK;
}

uint8_t
OSPI_ResetChip(void) {
	XSPI_RegularCmdTypeDef  sCommand = {0};
    uint32_t temp = 0;
    /* Erasing Sequence -------------------------------------------------- */
    sCommand.OperationType      = HAL_XSPI_OPTYPE_COMMON_CFG;
    sCommand.Instruction        = RESET_ENABLE_CMD;
    sCommand.InstructionMode    = HAL_XSPI_INSTRUCTION_1_LINE;
    sCommand.InstructionWidth   = HAL_XSPI_INSTRUCTION_8_BITS;
    sCommand.InstructionDTRMode = HAL_XSPI_INSTRUCTION_DTR_DISABLE;
    sCommand.AddressMode        = HAL_XSPI_ADDRESS_NONE;
    sCommand.AlternateBytesMode = HAL_XSPI_ALT_BYTES_NONE;
    sCommand.DataMode           = HAL_XSPI_DATA_NONE;
    sCommand.DummyCycles        = 0;
    sCommand.DQSMode            = HAL_XSPI_DQS_DISABLE;
    sCommand.SIOOMode           = HAL_XSPI_SIOO_INST_EVERY_CMD;

    if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE)
        != HAL_OK) {
        return HAL_ERROR;
    }
    for (temp = 0; temp < 0x2f; temp++) {
        __NOP();
    }

    sCommand.Instruction        = RESET_EXECUTE_CMD;

    if (HAL_XSPI_Command(&hospi1, &sCommand, HAL_XSPI_TIMEOUT_DEFAULT_VALUE)
        != HAL_OK) {
        return HAL_ERROR;
    }
    return HAL_OK;
}

/* USER CODE END 1 */
