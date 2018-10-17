#pragma once
#define Pi 3.14159
#define Total_Data 1024
#include <math.h>
class Gen_Signal
{
public:
	Gen_Signal();
	~Gen_Signal();
public:
	CString m_string;
	int DATA_No, m_FreQ;
	double Signal_Data1[Total_Data] = { 0 };
	double Signal_Data2[Total_Data] = { 0 };
	double Signal_Data3[Total_Data] = { 0 };
	void Signal_Data();
	CString Text1;
	CString Text2;
	CString Text3;
};