#include "main.h"
#include "spi.h"

/***********************************
GT30L32S4W SET DEFINE BEGIN
***********************************/

#define USE_HORIZONTAL 0  
#define LCD_CS_Low	SPI1_CS_GPIO_Port->BRR = (uint32_t)SPI1_CS_Pin
#define LCD_CS_High	SPI1_CS_GPIO_Port->BSRR = (uint32_t)SPI1_CS_Pin
#define LCD_DATA_CS LCD_D_C_GPIO_Port->BSRR =(uint32_t)LCD_D_C_Pin
#define LCD_COMMAND_CS LCD_D_C_GPIO_Port->BRR =(uint32_t)LCD_D_C_Pin

#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_Width 128
#define LCD_Heigh 160

#else
#define LCD_W 160
#define LCD_H 128
#endif

/***********************************
GT30L32S4W SET DEFINE END
***********************************/

/***********************************
GC90A1 SET DEFINE BEGIN
***********************************/
#define ORIENTATION 2

#define COL_ADDR_SET        0x2A
#define ROW_ADDR_SET        0x2B
#define MEM_WR              0x2C
#define COLOR_MODE          0x3A
#define COLOR_MODE__12_BIT  0x03
#define COLOR_MODE__16_BIT  0x05
#define COLOR_MODE__18_BIT  0x06
#define MEM_WR_CONT         0x3C

/***********************************
GC90A1 SET DEFINE END
***********************************/

void LCD_SPI_FULLMASTER(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData,
                                              uint16_t Size);
void LCD_WR_DATA8(uint8_t dat);
void LCD_Write_Data16(uint16_t);
void LCD_Write_REG(uint8_t dat);
void LCD_Adr_Set(uint8_t x1,uint8_t x2,uint8_t y1,uint8_t y2);
void GC90A1_Init(void);
void LCD_Init(void);
void LCD_Fill(uint8_t xsta,uint8_t xend,uint8_t ysta,uint8_t yend,uint16_t color);
void LCD_Fillin(uint8_t xsta,uint8_t ysta,uint8_t xend,uint8_t yend,uint16_t color);
void LCD_Bitmap(uint8_t xsta,uint8_t ysta,uint8_t Width,uint8_t Heigh,const uint8_t* data);
void LCD_DrawPoint(uint8_t x,uint8_t y,uint16_t PixelIndex);
void LCD_Draw16BppLine(uint8_t x,uint8_t y,uint8_t Width,const uint8_t* data);
