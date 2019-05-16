/**************************************************************************************
*		              LCD1602Һ����ʾʵ��												  *
ʵ���������س�������LCD1602Һ���ڿ������ϣ�������ʾ
ע�������������õ���ģ����ʾ�����Խ�74HC595ģ���ϵ�JP595�̽�Ƭ�ε���																				  
***************************************************************************************/

#include "reg52.h"			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���
#include "lcd.h"

typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;

u8 count, k1Num;
char hour, min, second;
u8 date[]="  2019-5-16";
// u8 time[]="   23:59:50";
u8 time[]="   00:00:00";

void write_time(u8 add, u8 date)
{
	u8 m, n;
	m = date / 10;  //ȡ��date��ʮλ�͸�λ
	n = date % 10;
	LcdWriteCom(add + 0x80 + 0x40);
	LcdWriteData(0x30 + m);
	LcdWriteData(0x30 + n);

}



void delay(uint z)
{
	u16 x, y;
	for (x = z; x > 0; x --)
		for (y = 110; y > 0; y --);
}



void keyScan()
{
	rd = 0;
	if (k1 == 0)
	{
		delay(5);
		if (k1 == 0)
		{
			k1Num ++;
			while(!k1);  //�ȴ�����
			if (k1Num == 1)
			{
				TR0 = 0; 	//��ʱֹͣ
				LcdWriteCom(0x80 + 0x40 + 10); //���ù��λ���� ��
				LcdWriteCom(0x0f);	  // �����˸
			}
			if (k1Num == 2)
			{
				TR0 = 0; 	//��ʱֹͣ
				LcdWriteCom(0x80 + 0x40 + 7); //���ù��λ���� �� 
				LcdWriteCom(0x0f);	  // �����˸
			}
			if (k1Num == 3)
			{
				TR0 = 0; 	//��ʱֹͣ
				LcdWriteCom(0x80 + 0x40 + 4); //���ù��λ���� ʱ
				LcdWriteCom(0x0f);	  // �����˸
			}
			if (k1Num == 4)
			{
				LcdWriteCom(0x0c);	  // ��겻��˸
				k1Num = 0;
				TR0 = 1; 	//��ʱֹͣ
			}
			
		}
	}
	
	if (k1Num != 0)	 // ��ʾ���ü��Ѿ�����(�����˸)
	{
		if (k2 == 0)
		{
			delay(5);
			if (k2 == 0)
			{
				while(!k2);     //�ȴ�����
				if (k1Num == 1) //˵����������λ��
				{
					second ++;
					if (second == 60) second = 0;
					write_time(9, second);			  // ˢ��ʱ��
					LcdWriteCom(0x80 + 0x40 + 10);	 //���ù���λ��
				}
				if (k1Num == 2) //˵������ڷֵ�λ��
				{
					min ++;
					if (min == 60) min = 0;
					write_time(6, min);
					LcdWriteCom(0x80 + 0x40 + 7);
				}
				if (k1Num == 3) //˵�������ʱ��λ��
				{
					hour ++;
					if (hour == 24) hour = 0;
					write_time(3, hour);
					LcdWriteCom(0x80 + 0x40 + 4);
				}
			}
		}
		if (k3 == 0)
		{
			delay(5);
			if (k3 == 0)
			{
				while(!k3);     //�ȴ�����
				if (k1Num == 1) //˵����������λ��
				{
					second --;
					if (second < 0) second = 59;
					write_time(9, second);			  // ˢ��ʱ��
					LcdWriteCom(0x80 + 0x40 + 10);	  //���ù���λ��
						 
				}
				if (k1Num == 2) //˵������ڷֵ�λ��
				{
					min --;
					if (min < 0) min = 59;
					write_time(6, min);
					LcdWriteCom(0x80 + 0x40 + 7);
				}
				if (k1Num == 3) //˵�������ʱ��λ��
				{
					hour --;
					if (hour < 0) hour = 23;
					write_time(3, hour);
					LcdWriteCom(0x80 + 0x40 + 4);
				}
			}
		}
	}
}






void main(void)
{
	u16 i;
	LcdInit();
	for(i = 0; i < 11; i ++)
	{
		LcdWriteData(date[i]);	
	}
	LcdWriteCom(0x40+0x80);
	for (i = 0; i < 11; i ++)
	{
		LcdWriteData(time[i]);
	}
	TMOD = 0x01;
	TH0 = (65526 - 50000) / 256;
	TL0 = (65526 - 50000) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;

	//hour = 23;
	//min = 59;
	//second = 50;
	
	while(1)
	{
		keyScan();
		
	}				
}



void timer0() interrupt 1
{
	TH0 = (65526 - 50000) / 256;
	TL0 = (65526 - 50000) % 256;
	count ++;
	if (count == 20)
		{
		 count = 0;
		 second ++;
		 if (second == 60)
		 {
		 	second = 0;
			min ++;
			if (min == 60)
			{
				min = 0;
				hour ++;
				if (hour == 24)
				{
					hour = 0;
				}
				write_time(3, hour);
			}
			write_time(6, min);
		 }
		 write_time(9, second);
		 
		}
}