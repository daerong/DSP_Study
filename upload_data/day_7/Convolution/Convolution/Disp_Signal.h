#pragma once

#define M 50
#define Sample_T 1

class Disp_Signal
{
private : 
	CString m_subject;
	double *Signal_Data;

public:
	Disp_Signal();
	~Disp_Signal();

	void setSubject(CString subject);
	void setVolume(int volume);
	void setSignal(double inputData[], int dataVolume);

	void Draw_Wave(CDC* pDC, CPoint CP, BYTE red, BYTE blue, BYTE green);
	void Draw_Dot(CDC* pDC, CPoint CP, BYTE red, BYTE blue, BYTE green);
	void Draw_Impulse(CDC* pDC, CPoint CP, BYTE red, BYTE blue, BYTE green);

public :
	int m_dataVolume;
};

