#pragma once

#define MSP_LCD_DATA_PORT           P2OUT              
#define MSP_LCD_EXECUTE_BIT             3                 //P2.3
#define MSP_LCD_COMMUNICATION_MODE_BIT  2                 //P2.2

/************************************************************************/
/* 	                          LCD COMMANDS                              */
/************************************************************************/

#define	MSP_LCD_COMMAND_CLEAR_DISPLAY                       0x01
#define MSP_LCD_COMMAND_SET_CURSOR_HOME	                    0x02
#define MSP_LCD_COMMAND_ENTRYMODE_INCREMENT	                0x06
#define MSP_LCD_COMMAND_ENTRYMODE_INCREMENT_WITH_ROLL       0x07
#define MSP_LCD_COMMAND_ENTRYMODE_DECREMENT                 0x04
#define MSP_LCD_COMMAND_ENTRYMODE_DECREMENT_WITH_ROLL       0x05
#define MSP_LCD_COMMAND_DISPLAY_OFF	                        0x08
#define MSP_LCD_COMMAND_DISPLAY_ON                          0x0c

#define MSP_LCD_COMMAND_DATA_ROLL_LEFT                      0x18
#define MSP_LCD_COMMAND_DATA_ROLL_RIGHT                     0x1c
#define MSP_LCD_COMMAND_CURSOR_SHIFT_LEFT                   0x10
#define MSP_LCD_COMMAND_CURSOR_SHIFT_RIGHT                  0x14

#define MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE1            0x80
#define MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE2            0xc0
#define MSP_LCD_DIRECT_DISPLAY_RAM_ADDRESS_LINE3            0x28
#define MSP_LCD_CHARACTER_GEN_RAM_ADDRESS                   0x40

/************************************************************************/
/* 	                 CUSTOM DISPLAY CHARACTER SLOTS                     */
/************************************************************************/
#define MSP_LCD_CUSTOM_CHAR_0 0x00
#define MSP_LCD_CUSTOM_CHAR_1 0x01
#define MSP_LCD_CUSTOM_CHAR_2 0x02
#define MSP_LCD_CUSTOM_CHAR_3 0x03
#define MSP_LCD_CUSTOM_CHAR_4 0x04
#define MSP_LCD_CUSTOM_CHAR_5 0x05
#define MSP_LCD_CUSTOM_CHAR_6 0x06
#define MSP_LCD_CUSTOM_CHAR_7 0x07

void lcdExecuteCommand(void);

void lcdSendData(unsigned char data);

void lcdSendCharacter(unsigned char character);

void lcdSendCommand(unsigned char command);

void lcdSetUpPorts(void);

void lcdStartUp(void);

void lcdClearDisplay(void);

void lcdUploadCustomCharacters(char customCharSet, unsigned int numOfCharacters);

void lcdGoToFirstLine(void);

void lcdGoToSecondLine(void);