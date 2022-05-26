/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "main.h"
#include "crc.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "GUI.h"
#include "GT30L32S4W.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
extern DMA_HandleTypeDef hdma_spi1_tx;
//extern GUI_CONST_STORAGE GUI_BITMAP bmYAGAMILIGHT;
extern int SP_call_count;
extern int DB_call_count;
extern int button;
extern int FR_call_count;
uint8_t UART_TRANS_OVER;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int fputc(int c, FILE *stream)    //??fputc??
{

    HAL_UART_Transmit(&huart2, (unsigned char *)&c, 1, 1000);   
    return 1;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	int i;
	uint8_t PSU_DATA[256]={0},UART_COMMAND[3];
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_DMA_Init();
  MX_SPI1_Init();
  MX_CRC_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
	HAL_GPIO_WritePin(LCD_BL_GPIO_Port,LCD_BL_Pin,GPIO_PIN_SET);
//	printf("GUI_INIT\r\n");
//	GUI_Init();
//	printf("GUI_PASS\r\n");


	//HAL_Delay(3000);


	//HAL_I2C_Master_Receive(&hi2c1,0x50<<1,PSU_DATA,10,100);
	
	PSU_DATA[0] = 0xFF;
	PSU_DATA[1] = 0xEE;
	
	PSU_DATA[2] = 0xCC;
	
	//HAL_I2C_Mem_Read(&hi2c1,0x50<<1,0x8D,1,PSU_DATA,4,100);
	
	
//	
//	HAL_Delay(5);
//	
//	HAL_I2C_Mem_Read(&hi2c1,0x50<<1,0x3A,1,PSU_DATA,5,100);
	
	
//	HAL_I2C_Mem_Write(&hi2c1,0x50<<1,0x3A,1,&PSU_DATA[2],1,100);
//	
//	HAL_Delay(10);
//	
//	HAL_I2C_Mem_Write(&hi2c1,0x50<<1,0x3D,1,&PSU_DATA[2],1,100);
//	
//	HAL_Delay(10);
//	
//	HAL_I2C_Mem_Write(&hi2c1,0x50<<1,0x3B,1,PSU_DATA,2,100);
//	
//	HAL_Delay(10);
//	
//	HAL_I2C_Mem_Write(&hi2c1,0x50<<1,0x3C,1,PSU_DATA,2,100);
//	
//	HAL_Delay(10);
//	
//	HAL_I2C_Mem_Write(&hi2c1,0x50<<1,0x3E,1,PSU_DATA,2,100);
//	
//	HAL_Delay(10);
//	
//	HAL_I2C_Mem_Write(&hi2c1,0x50<<1,0x3F,1,PSU_DATA,2,100);
//	
//	HAL_Delay(3);
//	
//	HAL_I2C_Mem_Read(&hi2c1,0x50<<1,0x81,1,PSU_DATA,2,100);
	

//	for(i=0;i<256;i++){
//		printf("PSU_DATA[%d] : 0x%x\r\n",i,PSU_DATA[i]);
//	}
	
	//printf("GO\r\n");
	
	UART_COMMAND[0] = 1;
	UART_COMMAND[1] = 11;
	UART_COMMAND[2] = 31;
	
	UART_TRANS_OVER=0;
	
	HAL_UART_Receive_IT(&huart2,UART_COMMAND,3);
	
	while(UART_TRANS_OVER!=1){
//		printf("UART_COMMAND[0] : 0x%x\r\n",UART_COMMAND[0]);
//		printf("UART_COMMAND[1] : 0x%x\r\n",UART_COMMAND[1]);
//		printf("UART_COMMAND[2] : 0x%x\r\n",UART_COMMAND[2]);
//		printf("UART_TRANS_OVER : %d\r\n",UART_TRANS_OVER);
		HAL_Delay(2000);
	}
	//HAL_UART_Transmit(&huart2,UART_COMMAND , 3, 1000);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
		
    /* USER CODE BEGIN 3 */
//		HAL_UART_Receive_IT(&huart2,UART_COMMAND,3);
//		
//		while( [0]!=0xFF){}
//			
//		HAL_I2C_Mem_Read(&hi2c1,0x50<<1,UART_COMMAND[1],1,PSU_DATA,UART_COMMAND[2],100);
//			
//		UART_COMMAND[0] = 0;	
		
		//HAL_UART_Transmit(&huart2,UART_COMMAND , 3, 1000);
		
		printf("UART_COMMAND[0] : 0x%x\r\n",UART_COMMAND[0]);
		printf("UART_COMMAND[1] : 0x%x\r\n",UART_COMMAND[1]);
		printf("UART_COMMAND[2] : 0x%x\r\n",UART_COMMAND[2]);
		
		printf("UART_TRANS_OVER : %d\r\n",UART_TRANS_OVER);
		
		HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 10;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	while(HAL_UART_GetState(&huart2) == HAL_UART_STATE_BUSY_RX);
	UART_TRANS_OVER=1;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

