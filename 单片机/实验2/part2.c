#include "reg52.h"			 //���ļ��ж����˵�Ƭ����һЩ���⹦�ܼĴ���

typedef unsigned int u16;	  //���������ͽ�����������
typedef unsigned char u8;
sbit led0 = P2^0;

sbit k1 = P3^0;


void delay(u16 i)
{
	while(i --);
}


void main()
{
	while(1)
	{
		if(k1 == 0)
		{
			delay(1000);
			if (k1 == 0)
			{
				led0 =~ led0;
			}
			while(!k1);
		} 
	}	
}