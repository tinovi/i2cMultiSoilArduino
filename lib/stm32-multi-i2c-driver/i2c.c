

#include "i2c.h"
#include "mw_log_conf.h"
#include "gpio.h"

I2C_HandleTypeDef hi2c1;
I2C_HandleTypeDef hi2c2;
I2C_HandleTypeDef hi2c3;

bool state[3] = {false,false,false};
void i2c_in(){
	MX_I2C1_Init();
	MX_I2C2_Init();
	MX_I2C3_Init();
}
void i2c_init(uint8_t inst){
	MX_WWDG_Reset();
	switch(inst){
		case 0:
			//if(!state[0]){
				MX_I2C1_Init();
				state[0] = true;
			//}
		break;
		case 1:
			//if(!state[1]){
				MX_I2C2_Init();
				state[1] = true;
			//}
		break;
		case 2:
			//if(!state[2]){
				MX_I2C3_Init();
				state[2] = true;
			//}
		break;
	}
	MX_WWDG_Reset();
}


void i2c_de(uint8_t inst){
	MX_WWDG_Reset();
	if(state[inst]){
		switch(inst){
			case 0:
				HAL_I2C_DeInit(&hi2c1);
			break;
			case 1:
				HAL_I2C_DeInit(&hi2c2);
			break;
			case 2:
				HAL_I2C_DeInit(&hi2c3);
			break;
		}
		state[inst] = false;
	}
//	MX_WWDG_Stop();
}

void powOn(){
    MX_WWDG_Reset();
    GPIO_InitTypeDef GPIO_InitStruct = {0};
   GPIO_InitStruct.Pin = SENS_ON_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(SENS_ON_GPIO_Port, &GPIO_InitStruct);
    HAL_GPIO_WritePin(SENS_ON_GPIO_Port, SENS_ON_Pin, GPIO_PIN_SET);
}

void powOff(){
    MX_WWDG_Reset();
    GPIO_InitTypeDef GPIO_InitStruct = {0};
//    GPIO_InitStruct.Pin = SENS_ON_Pin;
//    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    HAL_GPIO_Init(SENS_ON_GPIO_Port, &GPIO_InitStruct);
    HAL_GPIO_WritePin(SENS_ON_GPIO_Port, SENS_ON_Pin, GPIO_PIN_RESET);


    HAL_Delay(30);
    HAL_GPIO_DeInit(SENS_ON_GPIO_Port, SENS_ON_Pin);
    GPIO_InitStruct.Pin = SENS_ON_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(SENS_ON_GPIO_Port, &GPIO_InitStruct);
}


/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
 void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x20303E5D;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
 void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0x20303E5D;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief I2C3 Initialization Function
  * @param None
  * @retval None
  */
 void MX_I2C3_Init(void)
{

  /* USER CODE BEGIN I2C3_Init 0 */

  /* USER CODE END I2C3_Init 0 */

  /* USER CODE BEGIN I2C3_Init 1 */

  /* USER CODE END I2C3_Init 1 */
  hi2c3.Instance = I2C3;
  hi2c3.Init.Timing = 0x20303E5D;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c3, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c3, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C3_Init 2 */

  /* USER CODE END I2C3_Init 2 */

}


 void HAL_I2C_MspInit(I2C_HandleTypeDef* i2cHandle)
 {

   //MW_LOG( TS_OFF, VLEVEL_M,  "HAL_I2C_MspInit: %i\r\n", i2cHandle->Instance);
   GPIO_InitTypeDef GPIO_InitStruct = {0};
   RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};
   if(i2cHandle->Instance==I2C1)
   {
   /* USER CODE BEGIN I2C1_MspInit 0 */
	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6|GPIO_PIN_7);

   /* USER CODE END I2C1_MspInit 0 */

   /** Initializes the peripherals clocks
   */
     PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
     PeriphClkInitStruct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
     if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
     {
       Error_Handler();
     }

//     __HAL_RCC_GPIOB_CLK_ENABLE();
     /**I2C1 GPIO Configuration
     PB6     ------> I2C1_SCL
     PB7     ------> I2C1_SDA
     */
     GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
     GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
     HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

     /* I2C1 clock enable */
//     __HAL_RCC_I2C1_CLK_ENABLE();
   /* USER CODE BEGIN I2C1_MspInit 1 */

   /* USER CODE END I2C1_MspInit 1 */
   }
   else if(i2cHandle->Instance==I2C2)
   {
   /* USER CODE BEGIN I2C2_MspInit 0 */
	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11|GPIO_PIN_12);

   /* USER CODE END I2C2_MspInit 0 */

   /** Initializes the peripherals clocks
   */
     PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2C2;
     PeriphClkInitStruct.I2c2ClockSelection = RCC_I2C2CLKSOURCE_PCLK1;
     if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
     {
       Error_Handler();
     }

//     __HAL_RCC_GPIOA_CLK_ENABLE();
     /**I2C2 GPIO Configuration
     PA11     ------> I2C2_SDA
     PA12     ------> I2C2_SCL
     */
     GPIO_InitStruct.Pin = GPIO_PIN_11|GPIO_PIN_12;
     GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
     HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

     /* I2C2 clock enable */
//     __HAL_RCC_I2C2_CLK_ENABLE();
   /* USER CODE BEGIN I2C2_MspInit 1 */

   /* USER CODE END I2C2_MspInit 1 */
   }
   else if(i2cHandle->Instance==I2C3)
   {
   /* USER CODE BEGIN I2C3_MspInit 0 */
	HAL_GPIO_DeInit(GPIOB, GPIO_PIN_4);
	HAL_GPIO_DeInit(GPIOA, GPIO_PIN_7);
   /* USER CODE END I2C3_MspInit 0 */

   /** Initializes the peripherals clocks
   */
     PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_I2C3;
     PeriphClkInitStruct.I2c3ClockSelection = RCC_I2C3CLKSOURCE_PCLK1;
     if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
     {
       Error_Handler();
     }

//     __HAL_RCC_GPIOB_CLK_ENABLE();
//     __HAL_RCC_GPIOA_CLK_ENABLE();
     /**I2C3 GPIO Configuration
     PB4     ------> I2C3_SDA
     PA7     ------> I2C3_SCL
     */
     GPIO_InitStruct.Pin = GPIO_PIN_4;
     GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     GPIO_InitStruct.Alternate = GPIO_AF4_I2C3;
     HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

     GPIO_InitStruct.Pin = GPIO_PIN_7;
     GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
     GPIO_InitStruct.Pull = GPIO_NOPULL;
     GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
     GPIO_InitStruct.Alternate = GPIO_AF4_I2C3;
     HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

     /* I2C3 clock enable */
//     __HAL_RCC_I2C3_CLK_ENABLE();
   /* USER CODE BEGIN I2C3_MspInit 1 */

   /* USER CODE END I2C3_MspInit 1 */
   }
 }

 void HAL_I2C_MspDeInit(I2C_HandleTypeDef* i2cHandle)
 {

//	  GPIO_InitTypeDef GPIO_InitStruct = {0};
   // MW_LOG( TS_OFF, VLEVEL_M,  "HAL_I2C_MspDeInit: %i\r\n", i2cHandle->Instance);
   if(i2cHandle->Instance==I2C1)
   {
   /* USER CODE BEGIN I2C1_MspDeInit 0 */

   /* USER CODE END I2C1_MspDeInit 0 */
     /* Peripheral clock disable */
//     __HAL_RCC_I2C1_CLK_DISABLE();

     /**I2C1 GPIO Configuration
     PB6     ------> I2C1_SCL
     PB7     ------> I2C1_SDA
     */
//     HAL_GPIO_DeInit(GPIOB, GPIO_PIN_6|GPIO_PIN_7);
//     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);


   /* USER CODE BEGIN I2C1_MspDeInit 1 */

   /* USER CODE END I2C1_MspDeInit 1 */
   }
   else if(i2cHandle->Instance==I2C2)
   {
   /* USER CODE BEGIN I2C2_MspDeInit 0 */

   /* USER CODE END I2C2_MspDeInit 0 */
     /* Peripheral clock disable */
//     __HAL_RCC_I2C2_CLK_DISABLE();

     /**I2C2 GPIO Configuration
     PA11     ------> I2C2_SDA
     PA12     ------> I2C2_SCL
     */
//     HAL_GPIO_DeInit(GPIOA, GPIO_PIN_11|GPIO_PIN_12);
//     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

   /* USER CODE BEGIN I2C2_MspDeInit 1 */

   /* USER CODE END I2C2_MspDeInit 1 */
   }
   else if(i2cHandle->Instance==I2C3)
   {
   /* USER CODE BEGIN I2C3_MspDeInit 0 */

   /* USER CODE END I2C3_MspDeInit 0 */
     /* Peripheral clock disable */
//     __HAL_RCC_I2C3_CLK_DISABLE();

     /**I2C3 GPIO Configuration
     PB4     ------> I2C3_SDA
     PA7     ------> I2C3_SCL
     */
//	 HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
//	 HAL_GPIO_DeInit(GPIOB, GPIO_PIN_4);
//   GPIO_InitStruct.Pin = GPIO_PIN_4;
//   GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//   GPIO_InitStruct.Alternate = ((uint8_t)0x00);
//   HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
//     HAL_GPIO_DeInit(GPIOA, GPIO_PIN_7);
//   GPIO_InitStruct.Pin = GPIO_PIN_7;
//   GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//   GPIO_InitStruct.Pull = GPIO_NOPULL;
//   GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//   GPIO_InitStruct.Alternate = ((uint8_t)0x00);
//  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

   /* USER CODE BEGIN I2C3_MspDeInit 1 */

   /* USER CODE END I2C3_MspDeInit 1 */
   }
 }

 bool sentCmd(i2c_handle_t *handle, uint8_t cmd){
		MX_WWDG_Reset();
 	uint8_t command_buffer[1] = {cmd};
 	HAL_StatusTypeDef def = HAL_I2C_Master_Transmit(handle->i2c_handle, handle->device_address << 1u, command_buffer, sizeof(command_buffer),
 			I2C_TIMEOUT);
 	if (def!= HAL_OK) {
 		MW_LOG(TS_OFF, VLEVEL_M,"i2c sentCmd err address: %i cmd %i err:%i\r\n", handle->device_address, cmd,def);
 		return false;
 	}else{
 		MW_LOG(TS_OFF, VLEVEL_M,"i2c sentCmd OK address: %i cmd %i err:%i  size:%i\r\n", handle->device_address, cmd,def,sizeof(command_buffer));
 	}
	MX_WWDG_Reset();
 	return true;
 }


 int getState(i2c_handle_t *handle){ //-1:no data, 0:err, 1:ok
   MX_WWDG_Reset();
   uint8_t buffer[1];
   if(HAL_I2C_Master_Receive(handle->i2c_handle, handle->device_address << 1u, buffer, sizeof(buffer), I2C_TIMEOUT) == HAL_OK){
	  //  MW_LOG( TS_OFF, VLEVEL_M,  "i2c getState OK address: %i status %i \r\n", handle->device_address, buffer[0] );
     return buffer[0];
   }else{
	    MW_LOG( TS_OFF, VLEVEL_M,  "i2c getState ERR address: %i \r\n", handle->device_address);
     return -1;
   }
	MX_WWDG_Reset();
 }

 int16_t getVal(i2c_handle_t *handle, uint8_t reg){
		MX_WWDG_Reset();

   sentCmd(handle, reg);
   int16_t ret=0;
   uint8_t buffer[2];
   if(HAL_I2C_Master_Receive(handle->i2c_handle, handle->device_address << 1u, buffer, sizeof(buffer), I2C_TIMEOUT) == HAL_OK){
 	uint8_t *pointer = (uint8_t *)&ret;
     pointer[0] = buffer[0];
     pointer[1] = buffer[1];
   }else{
	    MW_LOG( TS_OFF, VLEVEL_M,  "i2c getVal ERR address: %i \r\n", handle->device_address);
   }
   return ret;
	MX_WWDG_Reset();
 }

 uint32_t getVal32(i2c_handle_t *handle, uint8_t reg){
	MX_WWDG_Reset();
   sentCmd(handle, reg);
   uint32_t ret=0;
   uint8_t buffer[4];
   if(HAL_I2C_Master_Receive(handle->i2c_handle, handle->device_address << 1u, buffer, sizeof(buffer), I2C_TIMEOUT) == HAL_OK){
 	uint8_t *pointer = (uint8_t *)&ret;
     pointer[0] = buffer[0];
     pointer[1] = buffer[1];
     pointer[2] = buffer[2];
     pointer[3] = buffer[3];
   }
   return ret;
	MX_WWDG_Reset();
 }


 int setReg8(i2c_handle_t *handle, uint8_t reg, uint8_t val){
		MX_WWDG_Reset();
 	uint8_t command_buffer[2] = {reg, val};

	HAL_StatusTypeDef def = HAL_I2C_Master_Transmit(handle->i2c_handle, handle->device_address << 1u, command_buffer, sizeof(command_buffer),
 			I2C_TIMEOUT);
 	if (def!= HAL_OK) {
		MW_LOG( TS_OFF, VLEVEL_M,  "i2c setReg8 ERR address: %i reg %i val %i\r\n", handle->device_address, reg,val );
		return 0;
 	}
 	HAL_Delay(10);
	MX_WWDG_Reset();
   return getState(handle);
 }

 int setReg(i2c_handle_t *handle, uint8_t reg){
	MX_WWDG_Reset();
 	sentCmd(handle, reg);
 	HAL_Delay(10);
	MX_WWDG_Reset();
   return getState(handle);
 }

