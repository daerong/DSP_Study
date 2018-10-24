#pragma once

#define M 50
#define Sample_T 1

class Disp_Signal
{
private : 
	CString m_subject;
	double *Signal_Data;
	int *Signal_Data_Int;
	int m_drawArea, m_distanse;

public:
	Disp_Signal();
	~Disp_Signal();

	void setSubject(CString subject);
	void setVolume(int volume);
	void setSignal(double inputData[], int dataVolume);
	void setSignal(int inputData[], int dataVolume);
	void setDrawArea(int drawArea);
	void setDistanse(int distanse);

	void Draw_Impulse(CDC* pDC, CPoint CP, BYTE red, BYTE blue, BYTE green);

public :
	int m_dataVolume;
};

