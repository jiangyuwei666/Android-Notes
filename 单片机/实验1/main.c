#include "reg52.h"			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���
#include<intrins.h>
typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;

#define ledd P2

u16 flag = 1,ii;

sbit led = P2^0;		 //����Ƭ����P2.0�˿ڶ���Ϊled
sbit k3 = P3^2;  		//���尴��K3
sbit k4 = P3^3;  		//���尴��K4
sbit k2 = P3^0;
sbit led1 = P2^5;

void delay(u16 i)
{
	while(i --);	
}

void Int0Init()
{
	//����INT0
	IT0 = 1;//�����س�����ʽ���½��أ�
	EX0 = 1;//��INT0���ж�����	
	EA = 1;//�����ж�	
}


void Int1Init()
{
	//����INT1
	IT1 = 1;//�����س�����ʽ���½��أ�
	EX1 = 1;//��INT1���ж�����	
	EA = 1;//�����ж�	
}

//ʤ��oid keypros()
//{
//	if(k2==0)		  //��ⰴ��K1�Ƿ���
//	{	
//		for(ii=0;ii<4;ii++)
//		delay(1000);   //�������� һ���Լ10ms
//		if(k2==0)	 //�ٴ��жϰ����Ƿ���
//		{
//		 //led1 =~ led1;	
//		 	if (flag==1) flag=0;
//			if (flag==0) flag=1;
//		}
//		while(!k2);	 //��ⰴ���Ƿ��ɿ�
//	}		
//}

void main()
{
	Int0Init();  //	�����ⲿ�ж�0
	Int1Init();  //	�����ⲿ�ж�1
	while(1)
		led = 0;
//	
//	{
//		keypros();
//	}		
}


void Int0() interrupt 0		//�ⲿ�ж�0���жϺ���
{
	delay(1000);	 //��ʱ����
	if(k3 == 0)
	{
		while(k4!=0)
		{
			led=~led;
			delay(50000); //��Լ��ʱ450ms
//			led=1;
//			delay(50000); //��Լ��ʱ450ms
		}
			
	}
	
}

void Int1()	interrupt 2		//�ⲿ�ж�1���жϺ���
{
	delay(1000);	 //��ʱ����
	if(k4 == 0)
	{
		u8 i;
		ledd=0xfe;
		delay(50000); //��Լ��ʱ450ms	
		while(k3!=0)
		{			
			for(i=0;i<7;i++)	 //��led����һλ
			{
				ledd=_crol_(ledd,1);
				delay(50000); //��Լ��ʱ450ms	
				if(k3==0){P2=0XFF;break;}
			}
			for(i=0;i<7;i++)	//��led����һλ
			{
				ledd=_cror_(ledd,1);
				delay(50000); //��Լ��ʱ450ms	
				if(k3==0){P2=0XFF;break;}
			}
				
		} 
	}
}
