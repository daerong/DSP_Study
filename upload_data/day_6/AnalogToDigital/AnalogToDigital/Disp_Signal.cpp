#include "stdafx.h"
#include "Disp_Signal.h"


Disp_Signal::Disp_Signal() {
	Signal_Data = new double[1024];		// default data size
	m_dataVolume = 1024;
}

Disp_Signal::~Disp_Signal() {
	delete Signal_Data;
}

void Disp_Signal::setSubject(CString subject) { m_subject = subject; }

void Disp_Signal::setVolume(int volume) {
	delete Signal_Data;
	Signal_Data = new double[volume];
	m_dataVolume = volume;
}

void Disp_Signal::setSignal(double inputData[], int dataVolume) {
	delete Signal_Data;
	Signal_Data = new double[dataVolume];
	m_dataVolume = dataVolume;
	memcpy(Signal_Data, inputData, sizeof(double)*dataVolume);
}

void Disp_Signal::Draw_Wave(CDC* pDC, CPoint CP, BYTE red, BYTE blue, BYTE green) {
	int start_x = CP.x;
	int start_y = CP.y;

	if (!m_subject.IsEmpty()) { pDC->TextOut(start_x + m_dataVolume + 10, start_y, m_subject); }

	for (int t = 0; t < m_dataVolume; t += 1)
	{
		pDC->SetPixel(start_x + t, start_y - int(Signal_Data[t] * M), RGB(red, blue, green));
	}
}

void Disp_Signal::Draw_Dot(CDC* pDC, CPoint CP, BYTE red, BYTE blue, BYTE green) {
	int start_x = CP.x;
	int start_y = CP.y;

	if (!m_subject.IsEmpty()) { pDC->TextOut(start_x + m_dataVolume + 10, start_y, m_subject); }

	for (int t = 0; t < m_dataVolume; t += Sample_T)
	{
		pDC->SetPixel(start_x + t, start_y - int(Signal_Data[t] * M), RGB(red, blue, green));
	}
}

void Disp_Signal::Draw_Impulse(CDC* pDC, CPoint CP, BYTE red, BYTE blue, BYTE green) {		// cpoint는 좌표관련 x,y를 쉽게 사용할 수 있게함
	int start_x = CP.x;
	int start_y = CP.y;

	if (!m_subject.IsEmpty()) { pDC->TextOut(start_x + m_dataVolume + 10, start_y, m_subject); }

	CPen pen(PS_SOLID, 1, RGB(red, blue, green));
	CPen *pOldPen = pDC->SelectObject(&pen);

	for (int t = 0; t < m_dataVolume; t += Sample_T) {
		pDC->MoveTo(start_x + t, start_y);
		pDC->LineTo(start_x + t, start_y - Signal_Data[t] * M);
	}

	pDC->SelectObject(pOldPen);
}
