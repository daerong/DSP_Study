#include "StdAfx.h" 
#include "Gen_Signal.h"

/* Disp_Coor()���� ��� */
#define X_Start 20
#define Y_Start 20
#define X_End X_Start+1024
#define Y_End Y_Start+750
#define Y_Depth 3
#define Y_Raise 150
/* Disp_Coor()���� ��� */

/* Gen_Signal()���� ��� */
#define Pi 3.14159
#define FreQ 1			//1Hz ���ļ�
#define DATA_No 512		//1�ֱ�data��
#define M 0.5			//��ȣũ�����
#include <math.h>

/* Gen_Signal()���� ��� */

Gen_Signal::Gen_Signal() {
} 
Gen_Signal::~Gen_Signal() { 
} 
void Gen_Signal::Signal_Data() { 
	int x, m_freQ;

	if((m_string) == "sin") { 
		m_freQ = 1;
		for (x = 0; x < X_End - X_Start; x++)
		{
			Text1 = "Sin�Լ�, f = 1[Hz], N = 512[Hz]";
			Signal_Data1[x] = M * sin((2 * Pi * m_freQ / DATA_No)*x + Pi / 2);
		}

		m_freQ = 3;
		for (x = 0; x < X_End - X_Start; x++)
		{
			Text2 = "Sin�Լ�, f = 3[Hz], N = 512[Hz]";
			Signal_Data2[x] = M * sin((2 * Pi * m_freQ / DATA_No)*x + Pi / 2);
		}

		m_freQ = 9;
		for (x = 0; x < X_End - X_Start; x++)
		{
			Text3 = "Sin�Լ�, f = 9[Hz], N = 512[Hz]";
			Signal_Data3[x] = M * sin((2 * Pi * m_freQ / DATA_No)*x + Pi / 2);
		}
	} 
	else if((m_string) == "cos") { 
		m_freQ = 1;
		for (x = 0; x < X_End - X_Start; x++)
		{
			Text1 = "Cos�Լ�, f = 1[Hz], N = 512[Hz]";
			Signal_Data1[x] = M * cos((2 * Pi * m_freQ / DATA_No)*x + Pi / 2);
		}

		m_freQ = 3;
		for (x = 0; x < X_End - X_Start; x++)
		{
			Text2 = "Cos�Լ�, f = 3[Hz], N = 512[Hz]";
			Signal_Data2[x] = M * cos((2 * Pi * m_freQ / DATA_No)*x + Pi / 2);
		}

		m_freQ = 9;
		for (x = 0; x < X_End - X_Start; x++)
		{
			Text3 = "Cos�Լ�, f = 9[Hz], N = 512[Hz]";
			Signal_Data3[x] = M * cos((2 * Pi * m_freQ / DATA_No)*x + Pi / 2);
		}
	} 


	
}