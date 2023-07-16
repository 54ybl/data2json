/*
 * uart.c
 *
 * created: 2023/5/11
 *  author: 
 */



#include "uart.h"
#include "ls1b.h"
#include "ls1b_gpio.h"
#include "ns16550.h"
#include "stdio.h"
#include "string.h"
#include "uart.h"

void UART4_Config_Init(void)
{
    unsigned int BaudRate = 115200;
    ls1x_uart_init(devUART4,(void *)BaudRate); //��ʼ������
    ls1x_uart_open(devUART4,NULL); //�򿪴���
}

void UART4_Test(char* buff){
    //��������
    ls1x_uart_write(devUART4,buff,strlen(buff),NULL);
}

void UART5_Config_Init(void)
{
    unsigned int BaudRate = 115200;
    ls1x_uart_init(devUART5,(void *)BaudRate); //��ʼ������
    ls1x_uart_open(devUART5,NULL); //�򿪴���
}

void UART5_Test(char* buff){
    //��������
    ls1x_uart_write(devUART5,buff,strlen(buff),NULL);
    // delay_ms(500);
}


int UART5_Read(void)
{
    int count = 0;
    count = ls1x_uart_read(devUART5, buff, 256, NULL);
    if(strncmp(buff, "anyone", 6) == 0)
    {
        char tmp[256];
        strcpy(tmp,"{\"B\":\"02:02:17:00:01:01\"}");
        ls1x_uart_write(devUART5,tmp,strlen(tmp),NULL);
    }
    else if (strncmp(buff, "time", 4) == 0)
    {
        char tmp[8] = "0";
        char time[8] = "0";
        strncpy(tmp,buff,7);
        strncpy(time,&buff[4],3);
        int number = 0, i = 0;
                    for (i = 0; time[i] != '\0'; i++)
                    {
                        if (time[i] >= '0' && time[i] <= '9')
                            number = number * 16 + time[i] - '0'; // �ַ�����ASCII��������ֵ��48�����������ַ���ֵ��ȥ�����ַ�'0'��ֵ�õ��������ַ�����ֵ
                        else if (time[i] >= 'A' && time[i] <= 'F')
                            number = number * 16 + time[i] - 'A' + 10;
                        else if (time[i] >= 'a' && time[i] <= 'f')
                            number = number * 16 + time[i] - 'a' + 10;
                    }
        printf("��ʱ:%dms",number);
        return number;
    }
    
}