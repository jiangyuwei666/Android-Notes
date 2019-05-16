# include "reg52.h"			 


typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;

sbit k1 = P1^7;
sbit led = P2^0;
sbit k2 = P3^0;

void delay(u16 i)
{
	while(i --);
}

void main(void)
{
	
	while(1)
	
	{
		if(k1==0)		  //��ⰴ��K1�Ƿ���
		{	
			delay(1000);   //�������� һ���Լ10ms
			if(k1==0)	 //�ٴ��жϰ����Ƿ���
			{
				led=~led;	  //led״̬ȡ��
			}
			while(!k1);	 //��ⰴ���Ƿ��ɿ�
		}
		if(k2==0)		  //��ⰴ��K1�Ƿ���
		{	
			delay(1000);   //�������� һ���Լ10ms
			if(k2==0)	 //�ٴ��жϰ����Ƿ���
			{
				led=~led;	  //led״̬ȡ��
			}
			while(!k2);	 //��ⰴ���Ƿ��ɿ�
		}	
	}				
}