#pragma once
#define Pi 3.14159
#define No_Total 1024
#include <math.h>
class Gen_Signal
{
public:
	Gen_Signal();
	~Gen_Signal();
public:
	CString m_string;
	int DATA_No, m_FreQ;
	double Sin_Data[No_Total], Cos_Data[No_Total];
	void Signal_Data();
};