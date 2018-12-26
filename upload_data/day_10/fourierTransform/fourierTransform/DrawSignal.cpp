#include "stdafx.h"
#include "DrawSignal.h"

#define M 50			// 배율(Magnification)

DrawSignal::DrawSignal() : m_DataArrSize(1024), m_Interval(1)
{
}
DrawSignal::DrawSignal(int dataVolume) : m_DataArrSize(dataVolume), m_Interval(1)
{
	m_SigData = new double[dataVolume];
	for (int i = 0; i < dataVolume; i++) {
		m_SigData[i] = 0.0;
	}
}
DrawSignal::~DrawSignal() {
	delete m_SigData;
}

void DrawSignal::setVolume(int dataVolume) {
	m_DataArrSize = dataVolume;
	
	delete m_SigData;
	m_SigData = NULL;

	m_SigData = new double[dataVolume];
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigData[i] = 0.0;
	}
}
void DrawSignal::setInterval(int interval) {
	if(interval > 0) m_Interval = interval;
}
void DrawSignal::setSignal(double inputData[]) {	// inputData의 크기가 작을 경우, 잘못된 메모리를 복사합니다.
	memcpy(m_SigData, inputData, sizeof(double)*m_DataArrSize);
}
void DrawSignal::setSignal(double inputData[], int volume) {
	if (m_DataArrSize != volume) {

		delete m_SigData;
		m_SigData = NULL;

		m_SigData = new double[volume];
		m_DataArrSize = volume;
		for (int i = 0; i < m_DataArrSize; i++) {
			m_SigData[i] = 0.0;
		}
	}
	memcpy(m_SigData, inputData, sizeof(double)*m_DataArrSize);
}

void DrawSignal::drawWave(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green) {
	int start_x = CP.x + sigStart;
	int start_y = CP.y;

	CPen pen(PS_SOLID, 1, RGB(red, blue, green));
	CPen *pOldPen = pDC->SelectObject(&pen);

	int yData1, yData2;

	for (int t = m_Interval; t < m_DataArrSize; t += m_Interval) {
		yData1 = start_y - (int)round(m_SigData[t - m_Interval] * M);
		yData2 = start_y - (int)round(m_SigData[t] * M);
		pDC->MoveTo(start_x + (t - m_Interval), yData1);
		pDC->LineTo(start_x + t, yData2);
	}

	pDC->SelectObject(pOldPen);
}

void DrawSignal::drawDot(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green) {
	int start_x = CP.x + sigStart;
	int start_y = CP.y;

	for (int t = 0; t < m_DataArrSize; t += m_Interval) {
		pDC->SetPixel(start_x + t, start_y - int(m_SigData[t] * M), RGB(red, blue, green));
	}
}

void DrawSignal::drawImpulse(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green) {
	int start_x = CP.x + sigStart;
	int start_y = CP.y;

	CPen pen(PS_SOLID, 1, RGB(red, blue, green));
	CPen *pOldPen = pDC->SelectObject(&pen);

	int yData;

	for (int t = 0; t < m_DataArrSize; t += m_Interval) {
		yData = start_y - (int)round(m_SigData[t] * M);
		pDC->MoveTo(start_x + t, start_y);
		pDC->LineTo(start_x + t, yData);
	}

	pDC->SelectObject(pOldPen);
}

void DrawSignal::drawImpulseNormalize(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green) {
	int start_x = CP.x + sigStart;
	int start_y = CP.y;

	CPen pen(PS_SOLID, 1, RGB(red, blue, green));
	CPen *pOldPen = pDC->SelectObject(&pen);

	int yData;

	double normalizeFactor = 0.0;

	for (int t = 0; t < m_DataArrSize; t += m_Interval) {
		if (m_SigData[t] > normalizeFactor) normalizeFactor = m_SigData[t];
		else if(-1 * m_SigData[t] > normalizeFactor)  normalizeFactor = -1 * m_SigData[t];
	}

	for (int t = 0; t < m_DataArrSize; t += m_Interval) {
		yData = start_y - (int)round(m_SigData[t] * M / normalizeFactor);
		pDC->MoveTo(start_x + t, start_y);
		pDC->LineTo(start_x + t, yData);
	}

	pDC->SelectObject(pOldPen);
}

void DrawSignal::drawImpulseNormalizeFourier(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green) {
	int start_x = CP.x + sigStart;
	int start_y = CP.y;

	CPen pen(PS_SOLID, 1, RGB(red, blue, green));
	CPen *pOldPen = pDC->SelectObject(&pen);

	int yData;

	double normalizeFactor = 0.0;

	for (int t = 0; t < m_DataArrSize; t += m_Interval) {
		if (m_SigData[t] > normalizeFactor) normalizeFactor = m_SigData[t];
		else if (-1 * m_SigData[t] > normalizeFactor)  normalizeFactor = -1 * m_SigData[t];
	}

	double swap = 0.0;

	for (int i = 0; i < m_DataArrSize/2; i++) {
		//swap = m_SigData[m_DataArrSize / 2 - 1 - i];
		//m_SigData[m_DataArrSize/2 -1 - i] = m_SigData[i];
		//m_SigData[i] = swap;

		swap = m_SigData[m_DataArrSize - 1 - i];
		m_SigData[m_DataArrSize - 1 - i] = m_SigData[m_DataArrSize / 2 - i];
		m_SigData[m_DataArrSize / 2 - i] = swap;
	}

	for (int t = 0; t < m_DataArrSize; t += m_Interval) {
		yData = start_y - (int)round(m_SigData[t] * M / normalizeFactor);
		pDC->MoveTo(start_x + t, start_y);
		pDC->LineTo(start_x + t, yData);
	}

	pDC->SelectObject(pOldPen);

	CString Text;
	Text.Format(_T("%f"), normalizeFactor);
	pDC->TextOut(30, 30, Text);
}

void DrawSignal::drawStair(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green) {
	int start_x = CP.x + sigStart;
	int start_y = CP.y;

	CPen pen(PS_SOLID, 1, RGB(red, blue, green));
	CPen *pOldPen = pDC->SelectObject(&pen);

	int yData1, yData2;

	for (int t = m_Interval; t < m_DataArrSize; t += m_Interval) {
		yData1 = start_y - (int)round(m_SigData[t - m_Interval] * M);
		yData2 = start_y - (int)round(m_SigData[t] * M);
		pDC->MoveTo(start_x + (t - m_Interval), yData1);
		pDC->LineTo(start_x + t, yData1);
		pDC->MoveTo(start_x + t, yData1);
		pDC->LineTo(start_x + t, yData2);
	}

	pDC->SelectObject(pOldPen);
}