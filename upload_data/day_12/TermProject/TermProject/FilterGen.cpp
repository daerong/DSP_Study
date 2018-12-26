#include "stdafx.h"
#include "FilterGen.h"
#include <math.h>

#define PI 3.14

FilterGen::FilterGen() : m_Type(""), m_Amplitude(1), m_DataArrSize(1024), m_FreqData(NULL)
{
}

FilterGen::FilterGen(int dataVolume) : m_Type(""), m_Amplitude(1), m_DataArrSize(dataVolume)
{
	m_FreqData = new double[dataVolume];
	for (int i = 0; i < dataVolume; i++) {
		m_FreqData[i] = 0.0;
	}
}

FilterGen::~FilterGen()
{
	delete m_FreqData;
}


void FilterGen::setStyle(CString style) { m_Type = style; }
void FilterGen::setStyle(char *style) { m_Type = style; }
void FilterGen::setAmp(double amplitude) { m_Amplitude = amplitude; }
void FilterGen::setVolume(int dataVolume) {
	m_DataArrSize = dataVolume;

	delete m_FreqData;
	m_FreqData = NULL;

	m_FreqData = new double[dataVolume];
	for (int i = 0; i < m_DataArrSize; i++) {
		m_FreqData[i] = 0.0;
	}
}

void FilterGen::makeLPF(int freq, int underArea) {
	for (int i = 0; i < m_DataArrSize; i++) {
		m_FreqData[i] = m_Amplitude;
	}

	for (int f = freq; f <= m_DataArrSize - underArea; f++) {
		if (f != m_DataArrSize - underArea)m_FreqData[underArea + f] = 0;
		m_FreqData[underArea - f] = 0;
	}
}

void FilterGen::makeButterworth(int freq, int degree, int underArea) {
	for (int i = 0; i < m_DataArrSize; i++) {
		m_FreqData[i] = 0.0;
	}


	for (int f = 0; f <= m_DataArrSize - underArea; f++) {
		double W_Wc_2n = 0;

		//주파수 상에서 버터워스 필터를 구현한다.
		W_Wc_2n = pow((double)(2 * PI*f) / (2 * PI*freq), 2 * degree);
		if (f != m_DataArrSize - underArea)m_FreqData[underArea + f] = m_Amplitude / sqrt(1 + W_Wc_2n);
		m_FreqData[underArea - f] = m_Amplitude / sqrt(1 + W_Wc_2n);
	}
}

void FilterGen::makeChebyshev(int freq, int degree, int underArea) {
	for (int i = 0; i < m_DataArrSize; i++) {
		m_FreqData[i] = 0.0;
	}

	for (int f = 0; f <= m_DataArrSize - underArea; f++) {
		double epsilon = 0.5;
		double Cn = 0;
		double W_Wc = 0;

		//주파수 상에서 체비셰브 필터를 구현한다.
		W_Wc = (double)((2 * PI*f) / (2 * PI*freq));
		if (fabs(W_Wc) <= 1) { Cn = cos((double)degree*(acos(W_Wc))); }
		else if (fabs(W_Wc) > 1) { Cn = cosh((double)degree*(acosh(W_Wc))); }
			
		if (f != m_DataArrSize - underArea)m_FreqData[underArea + f] = fabs(m_Amplitude / sqrt(1 + (pow(epsilon, 2)*pow(Cn, 2))));
		m_FreqData[underArea - f] = fabs(m_Amplitude / sqrt(1 + (pow(epsilon, 2)*pow(Cn, 2))));
	}
}



