LJMP     C:0029             //��ⰴ��K1�Ƿ���   
JB       k1(0x90.7),C:0015//�������� һ���Լ10ms
MOV      R7,#0xE81000   //�������� һ���Լ10ms 
MOV      R6,#0x031000   //�������� һ���Լ10ms
LCALL    delay(C:0035)
JB       k1(0x90.7),C:0012  //�ٴ��жϰ����Ƿ���
CPL      led(0xA0.0)ed=~led;         //led״̬ȡ��
JNB      k1(0x90.7),C:0012  //��ⰴ���Ƿ��ɿ� ��� 
JB       k2(0xB0.0),main(C:0003)
MOV      R7,#0xE81000   //�������� һ���Լ10ms 
MOV      R6,#0x031000   //�������� һ���Լ10ms
LCALL    delay(C:0035);   //�������� һ���Լ10ms
JB       k2(0xB0.0),C:0024  //�ٴ��жϰ����Ƿ���
CPL      led(0xA0.0)ed=~led;         //led״̬ȡ��
JB       k2(0xB0.0),main(C:0003)     //led״̬ȡ��
SJMP     C:0024
         
MOV      R0,#0x7F0,main(C:0003)     //led״̬ȡ�� 
CLR      A		 
MOV      @R0,A	 
DJNZ     R0,C:002C,main(C:0003)     //led״̬ȡ�� 		 
MOV      SP(0x81),#0x07n(C:0003)     //led״̬ȡ�� 
LJMP     main(C:0003)07n(C:0003)     //led״̬ȡ�� 
MOV      A,R7(C:0003)07n(C:0003)     //led״̬ȡ�� 		 
DEC      R7R7(C:0003)07n(C:0003)     //led״̬ȡ�� 	 
MOV      R4,0x06000307n(C:0003)     //led״̬ȡ�� 	 
JNZ      C:003C6000307n(C:0003)     //led״̬ȡ�� 	 
DEC      R6003C6000307n(C:0003)     //led״̬ȡ�� 	 
ORL      A,R43C6000307n(C:0003)     //led״̬ȡ�� 	 
JNZ      delay(C:0035)7n(C:0003)     //led״̬ȡ�� 	 
RET      delay(C:0035)7n(C:0003)     //led״̬ȡ��  
		 
		 
		 
		 
END		   