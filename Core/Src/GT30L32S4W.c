#include "GT30L32S4W.h"
extern DMA_HandleTypeDef hdma_spi1_tx;

void LCD_SPI_FULLMASTER(SPI_HandleTypeDef *hspi, uint8_t *pTxData, uint8_t *pRxData,
                                              uint16_t Size)
{
	HAL_SPI_TransmitReceive_DMA(hspi,pTxData,pRxData,Size);
}

void LCD_WR_DATA8(uint8_t dat)
{
	
	uint8_t buf;
	
	buf=dat;
	
	LCD_CS_Low;
	
//	HAL_SPI_TransmitReceive_DMA(&hspi1,&dat,&buf,1);
//	while(HAL_DMA_GetState(&hdma_spi1_tx)!=1);
//	while(HAL_DMA_GetState(&hdma_spi1_rx)!=1);
	
	HAL_SPI_Transmit_DMA(&hspi1,&buf,1);
	while(HAL_DMA_GetState(&hdma_spi1_tx)!=1);
	
	//HAL_SPI_Transmit(&hspi1,&dat,1,100);
	
	//LCD_CS_High;
}
void LCD_Write_Data16(uint16_t dat)
{
	uint8_t buf[2];
	buf[0]=(dat&0xFF00)>>8;
	buf[1]=dat&0x00FF;
	
	LCD_CS_Low;
	
	HAL_SPI_Transmit_DMA(&hspi1,buf,2);
	while(HAL_DMA_GetState(&hdma_spi1_tx)!=1);
	
//	LCD_WR_DATA8(dat>>8);
//	LCD_WR_DATA8(dat);
}

void LCD_Write_REG(uint8_t dat)
{
	LCD_CS_High;
	
	LCD_CS_Low;
	
	LCD_COMMAND_CS;
	
	LCD_WR_DATA8(dat);
	
	LCD_DATA_CS;
	
	LCD_CS_High;
	
}

void LCD_Adr_Set(uint8_t x1,uint8_t x2,uint8_t y1,uint8_t y2)
{
		LCD_Write_REG(0x2a);
		LCD_WR_DATA8(0X00);
		LCD_WR_DATA8(0x02+x1);
		LCD_WR_DATA8(0X00);
		LCD_WR_DATA8(0x02+x2); //x Init start =  2
		LCD_Write_REG(0x2b);
		LCD_WR_DATA8(0X00);
		LCD_WR_DATA8(0x01+y1);
		LCD_WR_DATA8(0X00);
		LCD_WR_DATA8(0x01+y2); //y Init start = 1
		LCD_Write_REG(0x00);
}
void GC90A1_Init(void)
{
		//GC9A01_set_chip_select(1);
    //HAL_Delay(5);
    //GC9A01_set_reset(0);
    //HAL_Delay(10);
    //GC9A01_set_reset(1);
    //HAL_Delay(120);
    
    /* Initial Sequence */ 
    
		//HAL_GPIO_WritePin(LCD_BL_GPIO_Port,LCD_BL_Pin,GPIO_PIN_SET);
		HAL_Delay(200);
	
    LCD_Write_REG(0xEF);
    
    LCD_Write_REG(0xEB);
    LCD_WR_DATA8(0x14);
    
    LCD_Write_REG(0xFE);
    LCD_Write_REG(0xEF);
    
    LCD_Write_REG(0xEB);
    LCD_WR_DATA8(0x14);
    
    LCD_Write_REG(0x84);
    LCD_WR_DATA8(0x40);
    
    LCD_Write_REG(0x85);
    LCD_WR_DATA8(0xFF);
    
    LCD_Write_REG(0x86);
    LCD_WR_DATA8(0xFF);
    
    LCD_Write_REG(0x87);
    LCD_WR_DATA8(0xFF);
    
    LCD_Write_REG(0x88);
    LCD_WR_DATA8(0x0A);
    
    LCD_Write_REG(0x89);
    LCD_WR_DATA8(0x21);
    
    LCD_Write_REG(0x8A);
    LCD_WR_DATA8(0x00);
    
    LCD_Write_REG(0x8B);
    LCD_WR_DATA8(0x80);
    
    LCD_Write_REG(0x8C);
    LCD_WR_DATA8(0x01);
    
    LCD_Write_REG(0x8D);
    LCD_WR_DATA8(0x01);
    
    LCD_Write_REG(0x8E);
    LCD_WR_DATA8(0xFF);
    
    LCD_Write_REG(0x8F);
    LCD_WR_DATA8(0xFF);
    
    
    LCD_Write_REG(0xB6);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x00);
    
    LCD_Write_REG(0x36);
    
#if ORIENTATION == 0
    LCD_WR_DATA8(0x18);
#elif ORIENTATION == 1
    LCD_WR_DATA8(0x28);
#elif ORIENTATION == 2
    LCD_WR_DATA8(0x48);
#else
    LCD_WR_DATA8(0x88);
#endif

		LCD_Write_REG(COLOR_MODE);
    LCD_WR_DATA8(COLOR_MODE__16_BIT);
    
    LCD_Write_REG(0x90);
    LCD_WR_DATA8(0x08);
    LCD_WR_DATA8(0x08);
    LCD_WR_DATA8(0x08);
    LCD_WR_DATA8(0x08);
    
    LCD_Write_REG(0xBD);
    LCD_WR_DATA8(0x06);
    
    LCD_Write_REG(0xBC);
    LCD_WR_DATA8(0x00);
    
    LCD_Write_REG(0xFF);
    LCD_WR_DATA8(0x60);
    LCD_WR_DATA8(0x01);
    LCD_WR_DATA8(0x04);
    
    LCD_Write_REG(0xC3);
    LCD_WR_DATA8(0x13);
    LCD_Write_REG(0xC4);
    LCD_WR_DATA8(0x13);
    
    LCD_Write_REG(0xC9);
    LCD_WR_DATA8(0x22);
    
    LCD_Write_REG(0xBE);
    LCD_WR_DATA8(0x11);
    
    LCD_Write_REG(0xE1);
    LCD_WR_DATA8(0x10);
    LCD_WR_DATA8(0x0E);
    
    LCD_Write_REG(0xDF);
    LCD_WR_DATA8(0x21);
    LCD_WR_DATA8(0x0c);
    LCD_WR_DATA8(0x02);
    
    LCD_Write_REG(0xF0);
    LCD_WR_DATA8(0x45);
    LCD_WR_DATA8(0x09);
    LCD_WR_DATA8(0x08);
    LCD_WR_DATA8(0x08);
    LCD_WR_DATA8(0x26);
    LCD_WR_DATA8(0x2A);
    
    LCD_Write_REG(0xF1);
    LCD_WR_DATA8(0x43);
    LCD_WR_DATA8(0x70);
    LCD_WR_DATA8(0x72);
    LCD_WR_DATA8(0x36);
    LCD_WR_DATA8(0x37);
    LCD_WR_DATA8(0x6F);
    
    LCD_Write_REG(0xF2);
    LCD_WR_DATA8(0x45);
    LCD_WR_DATA8(0x09);
    LCD_WR_DATA8(0x08);
    LCD_WR_DATA8(0x08);
    LCD_WR_DATA8(0x26);
    LCD_WR_DATA8(0x2A);
    
    LCD_Write_REG(0xF3);
    LCD_WR_DATA8(0x43);
    LCD_WR_DATA8(0x70);
    LCD_WR_DATA8(0x72);
    LCD_WR_DATA8(0x36);
    LCD_WR_DATA8(0x37);
    LCD_WR_DATA8(0x6F);
    
    LCD_Write_REG(0xED);
    LCD_WR_DATA8(0x1B);
    LCD_WR_DATA8(0x0B);
    
    LCD_Write_REG(0xAE);
    LCD_WR_DATA8(0x77);
    
    LCD_Write_REG(0xCD);
    LCD_WR_DATA8(0x63);
    
    LCD_Write_REG(0x70);
    LCD_WR_DATA8(0x07);
    LCD_WR_DATA8(0x07);
    LCD_WR_DATA8(0x04);
    LCD_WR_DATA8(0x0E);
    LCD_WR_DATA8(0x0F);
    LCD_WR_DATA8(0x09);
    LCD_WR_DATA8(0x07);
    LCD_WR_DATA8(0x08);
    LCD_WR_DATA8(0x03);
    
    LCD_Write_REG(0xE8);
    LCD_WR_DATA8(0x34);
    
    LCD_Write_REG(0x62);
    LCD_WR_DATA8(0x18);
    LCD_WR_DATA8(0x0D);
    LCD_WR_DATA8(0x71);
    LCD_WR_DATA8(0xED);
    LCD_WR_DATA8(0x70);
    LCD_WR_DATA8(0x70);
    LCD_WR_DATA8(0x18);
    LCD_WR_DATA8(0x0F);
    LCD_WR_DATA8(0x71);
    LCD_WR_DATA8(0xEF);
    LCD_WR_DATA8(0x70);
    LCD_WR_DATA8(0x70);
    
    LCD_Write_REG(0x63);
    LCD_WR_DATA8(0x18);
    LCD_WR_DATA8(0x11);
    LCD_WR_DATA8(0x71);
    LCD_WR_DATA8(0xF1);
    LCD_WR_DATA8(0x70);
    LCD_WR_DATA8(0x70);
    LCD_WR_DATA8(0x18);
    LCD_WR_DATA8(0x13);
    LCD_WR_DATA8(0x71);
    LCD_WR_DATA8(0xF3);
    LCD_WR_DATA8(0x70);
    LCD_WR_DATA8(0x70);
    
    LCD_Write_REG(0x64);
    LCD_WR_DATA8(0x28);
    LCD_WR_DATA8(0x29);
    LCD_WR_DATA8(0xF1);
    LCD_WR_DATA8(0x01);
    LCD_WR_DATA8(0xF1);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x07);
    
    LCD_Write_REG(0x66);
    LCD_WR_DATA8(0x3C);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0xCD);
    LCD_WR_DATA8(0x67);
    LCD_WR_DATA8(0x45);
    LCD_WR_DATA8(0x45);
    LCD_WR_DATA8(0x10);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x00);
    
    LCD_Write_REG(0x67);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x3C);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x01);
    LCD_WR_DATA8(0x54);
    LCD_WR_DATA8(0x10);
    LCD_WR_DATA8(0x32);
    LCD_WR_DATA8(0x98);
    
    LCD_Write_REG(0x74);
    LCD_WR_DATA8(0x10);
    LCD_WR_DATA8(0x85);
    LCD_WR_DATA8(0x80);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x00);
    LCD_WR_DATA8(0x4E);
    LCD_WR_DATA8(0x00);
    
    LCD_Write_REG(0x98);
    LCD_WR_DATA8(0x3e);
    LCD_WR_DATA8(0x07);
    
    LCD_Write_REG(0x35);
    LCD_Write_REG(0x21);
    
    LCD_Write_REG(0x11);
    HAL_Delay(120);
    LCD_Write_REG(0x29);
    HAL_Delay(20);
}
void LCD_Init(void)
{
	//LCD_GPIO_Init();
	
	/*HAL_GPIO_WritePin(FSO_CS_GPIO_Port,FSO_CS_Pin,GPIO_PIN_RESET);
	HAL_Delay(100);
	HAL_GPIO_WritePin(FSO_CS_GPIO_Port,FSO_CS_Pin,GPIO_PIN_SET);
	HAL_Delay(100);*/
	
//	HAL_GPIO_WritePin(LCD_BL_GPIO_Port,LCD_BL_Pin,GPIO_PIN_SET);
//  HAL_Delay(200);
	
	//************* Start Initial Sequence **********//
//	LCD_Write_REG(0x01); //Software Reset 
//	HAL_Delay(150);              //Delay 150ms 
	LCD_Write_REG(0x11); //Sleep out 
	HAL_Delay(200);              //Delay 150ms 
	//------------------------------------ST7735S Frame Rate-----------------------------------------// 
	LCD_Write_REG(0xB1); //
	LCD_WR_DATA8(0x05); 
	LCD_WR_DATA8(0x3C); 
	LCD_WR_DATA8(0x3C); 
	LCD_Write_REG(0xB2); 
	LCD_WR_DATA8(0x05);
	LCD_WR_DATA8(0x3C); 
	LCD_WR_DATA8(0x3C); 
	LCD_Write_REG(0xB3); 
	LCD_WR_DATA8(0x05); 
	LCD_WR_DATA8(0x3C); 
	LCD_WR_DATA8(0x3C); 
	LCD_WR_DATA8(0x05); 
	LCD_WR_DATA8(0x3C); 
	LCD_WR_DATA8(0x3C); 
	//------------------------------------End ST7735S Frame Rate---------------------------------// 
	LCD_Write_REG(0xB4); //Dot inversion 
	LCD_WR_DATA8(0x03); 
	//------------------------------------ST7735S Power Sequence---------------------------------// 
	LCD_Write_REG(0xC0); 
	LCD_WR_DATA8(0x28); 
	LCD_WR_DATA8(0x08); 
	LCD_WR_DATA8(0x04); 
	LCD_Write_REG(0xC1); 
	LCD_WR_DATA8(0XC0); 
	LCD_Write_REG(0xC2); 
	LCD_WR_DATA8(0x0D); 
	LCD_WR_DATA8(0x00); 
	LCD_Write_REG(0xC3); 
	LCD_WR_DATA8(0x8D); 
	LCD_WR_DATA8(0x2A); 
	LCD_Write_REG(0xC4); 
	LCD_WR_DATA8(0x8D); 
	LCD_WR_DATA8(0xEE); 
	//---------------------------------End ST7735S Power Sequence-------------------------------------// 
	LCD_Write_REG(0xC5); //VCOM 
	LCD_WR_DATA8(0x1A); 
	LCD_Write_REG(0x36); //MX, MY, RGB mode 
	if(USE_HORIZONTAL==0)LCD_WR_DATA8(0x00);
	else if(USE_HORIZONTAL==1)LCD_WR_DATA8(0xC0);
	else if(USE_HORIZONTAL==2)LCD_WR_DATA8(0x70);
	else LCD_WR_DATA8(0xA0); 
	//------------------------------------ST7735S Gamma Sequence---------------------------------// 
	LCD_Write_REG(0xE0); 
	LCD_WR_DATA8(0x04); 
	LCD_WR_DATA8(0x22); 
	LCD_WR_DATA8(0x07); 
	LCD_WR_DATA8(0x0A); 
	LCD_WR_DATA8(0x2E); 
	LCD_WR_DATA8(0x30); 
	LCD_WR_DATA8(0x25); 
	LCD_WR_DATA8(0x2A); 
	LCD_WR_DATA8(0x28); 
	LCD_WR_DATA8(0x26); 
	LCD_WR_DATA8(0x2E); 
	LCD_WR_DATA8(0x3A); 
	LCD_WR_DATA8(0x00); 
	LCD_WR_DATA8(0x01); 
	LCD_WR_DATA8(0x03); 
	LCD_WR_DATA8(0x13); 
	LCD_Write_REG(0xE1); 
	LCD_WR_DATA8(0x04); 
	LCD_WR_DATA8(0x16); 
	LCD_WR_DATA8(0x06); 
	LCD_WR_DATA8(0x0D); 
	LCD_WR_DATA8(0x2D); 
	LCD_WR_DATA8(0x26); 
	LCD_WR_DATA8(0x23); 
	LCD_WR_DATA8(0x27); 
	LCD_WR_DATA8(0x27); 
	LCD_WR_DATA8(0x25); 
	LCD_WR_DATA8(0x2D); 
	LCD_WR_DATA8(0x3B); 
	LCD_WR_DATA8(0x00); 
	LCD_WR_DATA8(0x01); 
	LCD_WR_DATA8(0x04); 
	LCD_WR_DATA8(0x13); 
	//------------------------------------End ST7735S Gamma Sequence-----------------------------// 
	LCD_Write_REG(0x3A); //65k mode 
	LCD_WR_DATA8(0x05); 
	//------------------------------------ADDRESS SET-----------------------------//
	LCD_Adr_Set(0,127,0,128);
	LCD_Write_REG(0x29); //Display on 
} 
void LCD_Fill(uint8_t xsta,uint8_t xend,uint8_t ysta,uint8_t yend,uint16_t color)
{
		LCD_Write_REG(0x2a);
		LCD_WR_DATA8(0X00);
		LCD_WR_DATA8(0x02+xsta);
		LCD_WR_DATA8(0X00);
		LCD_WR_DATA8(0x02+xend); //x Init start =  2
		LCD_Write_REG(0x2b);
		LCD_WR_DATA8(0X00);
		LCD_WR_DATA8(0x01+ysta);
		LCD_WR_DATA8(0X00);
		LCD_WR_DATA8(0x01+yend); //y Init start = 1
		LCD_Write_REG(0x2c);
	/*for(i=ysta;i<yend+1;i++)
	{													   	 	
		for(j=xsta;j<xend+1;j++)
		{
			LCD_Write_Data16(color);
		}
	}		*/
	
	for(int i=0;i<(xend-xsta+1)*(yend-ysta+1);i++)
		{
			LCD_Write_Data16(color);
		}
	LCD_Write_REG(0x29);
}

void LCD_Fillin(uint8_t xsta,uint8_t xend,uint8_t ysta,uint8_t yend,uint16_t color)
{
	int i,j;
	uint8_t buf[256];
	LCD_Adr_Set(xsta,xend,ysta,yend);
	LCD_Write_REG(0x2C);

	LCD_CS_Low;
	
	for(i=((xend-xsta+1)*(yend-ysta+1)/256);i>=0;i--)
	{
		for(j=0;j<256;j+=2){
			buf[j]=color>>8;
			buf[j+1]=color&0x00FF;
		}
		if(i==0){
			if(((xend-xsta+1)*(yend-ysta+1)%256)==0){}
				else{
					HAL_SPI_Transmit_DMA(&hspi1,buf,((xend-xsta+1)*(yend-ysta+1)%256));
					while(HAL_DMA_GetState(&hdma_spi1_tx)!=1);
				}		
		}
			else{
				HAL_SPI_Transmit_DMA(&hspi1,buf,256);
				while(HAL_DMA_GetState(&hdma_spi1_tx)!=1);
			}
	}
	
	LCD_Write_REG(0x29);
}
void LCD_Bitmap(uint8_t xsta,uint8_t ysta,uint8_t Width,uint8_t Heigh,const uint8_t* data)
{
	int i;
	
	LCD_Adr_Set(xsta,xsta+Width-1,ysta,ysta+Heigh-1);
	
	LCD_Write_REG(0x2C);
	
	LCD_CS_Low;
	
	for(i=0;i<Width*Heigh;i++){
		LCD_WR_DATA8(*(data+1));
		LCD_WR_DATA8(*data);
		data+=2;
	}
	//HAL_SPI_Transmit(&hspi1,data,(Width*Heigh*2),100);
	
	LCD_CS_High;
}

void LCD_DrawPoint(uint8_t x,uint8_t y,uint16_t PixelIndex)
{
	LCD_Adr_Set(x,x,y,y);
	
	LCD_Write_REG(0x2C);
	
	LCD_Write_Data16(PixelIndex);
	
	LCD_CS_High;
}

void LCD_Draw16BppLine(uint8_t x,uint8_t y,uint8_t Width,const uint8_t* data)
{
	int i;
	uint8_t buf[256];
	
	LCD_Adr_Set(x,x+Width-1,y,y);
	
	LCD_Write_REG(0x2C);
	
	LCD_CS_Low;
	
	for(i=0;i<Width*2;i+=2){
		buf[i]=*(data+i+1);
		buf[i+1]=*(data+i);
	}
	
	HAL_SPI_Transmit_DMA(&hspi1,buf,Width*2);
	while(HAL_DMA_GetState(&hdma_spi1_tx)!=1);
	

}
