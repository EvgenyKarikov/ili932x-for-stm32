#include "ili9328.h"

// Чтение регистра LCD
uint16_t ILI9328_ReadReg ( uint8_t ILI9328_Reg )
{
    ILI9328_WRITE_CMD(ILI9328_Reg);
    return ILI9328_READ_DATA;	 
} 

void ILI9328_WriteMultipleData(uint16_t *pData, uint32_t Size)
{
    while (Size--) 
    {        
        *(uint16_t *) (LCD_DATA)= *pData++;
    }
}

void ILI9328_ReadMultipleData(uint16_t *pData, uint32_t Size)
{
    while (Size--) 
    {	    
        *pData++ = *(uint16_t *) LCD_DATA;
    }
}

void ILI9328_FillScreen (uint16_t color)
{
    uint32_t j= LCD_MAX_X * LCD_MAX_Y; //240*320
    ILI9328_SET_CURSOR (0, 0);
    ILI9328_WRITE_RAM_PREPARE;
    while(j--)
    {
        ILI9328_WRITE_DATA(color);        
    }
}

void ILI9328_Init(void)
{
    if  ( (ILI9328_ReadReg (ILI9328_R(0)) & (0x9320)) == 0x9320  )
    {
        ILI9328_WRITE_REG (0x00e7,0x0010);
        ILI9328_WRITE_REG (ILI9328_R(0),0x0001);       // start internal osc
        ILI9328_WRITE_REG (ILI9328_R(1),0x0100);
        ILI9328_WRITE_REG (ILI9328_R(2),0x0700);       // power on sequence        
        ILI9328_WRITE_REG (ILI9328_R(3),0x1010 );        // importance
        ILI9328_WRITE_REG (ILI9328_R(4),0x0000);
        ILI9328_WRITE_REG (ILI9328_R(8),0x0207);
        ILI9328_WRITE_REG (ILI9328_R(9),0x0000);
        ILI9328_WRITE_REG (ILI9328_R(10),0x0000);       // display setting
        ILI9328_WRITE_REG (ILI9328_R(12),0x0001);       // display setting
        ILI9328_WRITE_REG (ILI9328_R(13),0x0000);
        ILI9328_WRITE_REG (ILI9328_R(15),0x0000);     // Power On sequence
        ILI9328_WRITE_REG (ILI9328_R(16),0x0000);
        ILI9328_WRITE_REG (ILI9328_R(17),0x0007);
        ILI9328_WRITE_REG (0x0012,0x0000);
        ILI9328_WRITE_REG (0x0013,0x0000);  
        HAL_Delay (50); 
        ILI9328_WRITE_REG (0x0010,0x1590);
        ILI9328_WRITE_REG (0x0011,0x0227);  
        HAL_Delay (50);  
        ILI9328_WRITE_REG (0x0012,0x009c);  
        HAL_Delay (50); 
        ILI9328_WRITE_REG (0x0013,0x1900);
        ILI9328_WRITE_REG (0x0029,0x0023);
        ILI9328_WRITE_REG (0x002b,0x000e);  // set framerate
        HAL_Delay (50);
        ILI9328_WRITE_REG (0x0020,0x0000);
        ILI9328_WRITE_REG (0x0021,0x0000);  
        HAL_Delay (50);  
        ILI9328_WRITE_REG (0x0030,0x0007);
        ILI9328_WRITE_REG (0x0031,0x0707);
        ILI9328_WRITE_REG (0x0032,0x0006);
        ILI9328_WRITE_REG (0x0035,0x0704);
        ILI9328_WRITE_REG (0x0036,0x1f04);
        ILI9328_WRITE_REG (0x0037,0x0004);
        ILI9328_WRITE_REG (0x0038,0x0000);
        ILI9328_WRITE_REG (0x0039,0x0706);
        ILI9328_WRITE_REG (0x003c,0x0701);
        ILI9328_WRITE_REG (0x003d,0x000f);  HAL_Delay (50);  // delay 50 ms
        ILI9328_WRITE_REG (0x0050,0x0000);
        ILI9328_WRITE_REG (0x0051,0x00ef);
        ILI9328_WRITE_REG (0x0052,0x0000);
        ILI9328_WRITE_REG (0x0053,0x013f);
        ILI9328_WRITE_REG (0x0060,0xa700);
        ILI9328_WRITE_REG (0x0061,0x0001);
        ILI9328_WRITE_REG (0x006a,0x0000);
        ILI9328_WRITE_REG (0x0080,0x0000);
        ILI9328_WRITE_REG (0x0081,0x0000);
        ILI9328_WRITE_REG (0x0082,0x0000);
        ILI9328_WRITE_REG (0x0083,0x0000);
        ILI9328_WRITE_REG (0x0084,0x0000);
        ILI9328_WRITE_REG (0x0085,0x0000);
        ILI9328_WRITE_REG (0x0090,0x0010);
        ILI9328_WRITE_REG (0x0092,0x0000);
        ILI9328_WRITE_REG (0x0093,0x0003);
        ILI9328_WRITE_REG (0x0095,0x0110);
        ILI9328_WRITE_REG (0x0097,0x0000);
        ILI9328_WRITE_REG (0x0098,0x0000);  // display on sequence
        ILI9328_WRITE_REG (0x0007,0x0133);        //Power On
        ILI9328_WRITE_REG (0x0020,0x0000);
        ILI9328_WRITE_REG (0x0021,0x0000);
        //*******----------**********----------**********---------*
    }
    ILI9328_FillScreen(0xf);
}	
