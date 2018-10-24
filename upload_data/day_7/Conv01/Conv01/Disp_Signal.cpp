#include "stdafx.h"
#include "Disp_Signal.h"


Disp_Signal::Disp_Signal() {
	Signal_Data = new double[1024];		// default data size
	m_dataVolume = 1024;
	m_drawArea = 16;
	m_distanse = 1;
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

void Disp_Signal::setSignal(int inputData[], int dataVolume) {
	delete Signal_Data_Int;
	Signal_Data_Int = new int[dataVolume];
	m_dataVolume = dataVolume;
	memcpy(Signal_Data, inputData, sizeof(int)*dataVolume);
}

void Disp_Signal::setDrawArea(int drawArea) {
	m_drawArea = drawArea;
}

void Disp_Signal::setDistanse(int distanse) {
	m_distanse = distanse;
}

void Disp_Signal::Draw_Impulse(CDC* pDC, CPoint CP, BYTE red, BYTE blue, BYTE green) {		// cpoint는 좌표관련 x,y를 쉽게 사용할 수 있게함
	int start_x = CP.x;
	int start_y = CP.y;

	CPen pen(PS_SOLID, 1, RGB(red, blue, green));
	CPen *pOldPen = pDC->SelectObject(&pen);

	for (int t = 0; t < m_drawArea; t += Sample_T) {
		pDC->MoveTo(start_x + t * m_distanse, start_y);
		pDC->LineTo(start_x + t * m_distanse, start_y - Signal_Data[t] * M);
	}

	pDC->SelectObject(pOldPen);
}
