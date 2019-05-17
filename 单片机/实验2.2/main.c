#include "reg52.h"			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���

typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;


u16 led;

void delay(u16 i)
{
	while(i --);
}


void Timer0Init()
{
	TMOD|=0X01;//ѡ��Ϊ��ʱ��0ģʽ��������ʽ1������TR0��������

	TH0=0XFC;	//����ʱ������ֵ����ʱ1ms
	TL0=0X18;	
	ET0=1;//�򿪶�ʱ��0�ж�����
	EA=1;//�����ж�
	TR0=1;//�򿪶�ʱ��			
}


void main()
{
	Timer0Init();
	while(1);
}


void Timer0() interrupt 1
{
	static u16 i;
	TH0 = 0xfc;
	TL0 = 0x18;
	i ++;
	if (i == 500)
	{
		i = 0;
		led --;
		P2 = led; 
		if (led == 0) led = 0xff;
	}
	
	
}