#ifndef __ILI9328_H__
#define __ILI9328_H__

#include "stdbool.h"
#include "stdint.h"
#include "stm32f1xx_hal.h"

#define LCD_MAX_X 240
#define LCD_MAX_Y 320

#define LCD_RESET_OFF (GPIOE->BSRR =GPIO_BSRR_BS1)
#define LCD_RESET_ON (GPIOE->BSRR =GPIO_BSRR_BR1)

#define LCD_DATA ((uint32_t)0x60020000)
#define LCD_REG  ((uint32_t)0x60000000)

#define ILI9328_R(__REG_NUM__)		((uint16_t)__REG_NUM__)

#define ILI9328_WRITE_CMD(__VAL__)						(*(uint16_t *) (LCD_REG) =	(__VAL__))

#define ILI9328_WRITE_DATA(__VAL__)						(*(uint16_t *) (LCD_DATA) =	(__VAL__))

#define ILI9328_READ_DATA						        (*(uint16_t *) LCD_DATA)

#define ILI9328_WRITE_RAM_PREPARE						(ILI9328_WRITE_CMD(ILI9328_R(34)))

#define ILI9328_WRITE_REG(__CMD__, __VAL__)				do      \
									{	\
										ILI9328_WRITE_CMD(__CMD__);	\
										ILI9328_WRITE_DATA(__VAL__);	\
									}while(0)	
                                                                            
#define ILI9328_SET_CURSOR(__X__, __Y__)                                do      \
                                                                        {       \
                                                                            ILI9328_WRITE_REG (ILI9328_R(32),(uint16_t)__X__);  \
                                                                            ILI9328_WRITE_REG (ILI9328_R(33),(uint16_t)__Y__);  \
                                                                        }while(0)                                                                                                                                                

uint16_t ILI9328_ReadReg ( uint8_t LCD_Reg );
void ILI9328_WriteMultipleData(uint16_t *pData, uint32_t Size);
void ILI9328_ReadMultipleData(uint16_t *pData, uint32_t Size);
uint16_t ILI9328_ReadData ( void );
void ILI9328_Reset (void);
void ILI9328_Init(void);
//void FSMC_TransferDataDMAToLCD ( void *buffer, uint16_t count, bool isRamAddressIncrement );
void LCD_PutPixel (int x, int y, uint16_t col);
void ILI9328_FillScreen (uint16_t color);


#endif