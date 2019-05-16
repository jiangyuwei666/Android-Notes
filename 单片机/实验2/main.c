#include "reg52.h"			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���

typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;

sbit led=P2^0;	 //����P20����led


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
	Timer0Init();  //��ʱ��0��ʼ��
	while(1);		
}


void Timer0() interrupt 1
{
	static u16 i;
	TH0=0XFC;	//����ʱ������ֵ����ʱ1ms
	TL0=0X18;
	i++;
	if(i==1000)
	{
		i=0;
		led=~led;	
	}	
}