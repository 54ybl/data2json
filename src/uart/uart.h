/*
 * uart.h
 *
 * created: 2023/5/11
 *  author: 
 */

#ifndef _UART_H
#define _UART_H

#ifdef __cplusplus
extern "C" {
#endif

char buff[256];

void UART4_Config_Init(void);
int UART4_Read(void);
void UART4_Test(char* buff);

int UART5_Read(void);
void UART5_Config_Init(void);
void UART5_Test(char* buff);

#ifdef __cplusplus
}
#endif

#endif // _UART_H

