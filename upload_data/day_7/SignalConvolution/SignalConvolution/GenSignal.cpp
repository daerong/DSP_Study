#include "StdAfx.h" 
#include "GenSignal.h"

GenSignal::GenSignal() : m_Type(""), m_Amplitude(1), m_DataArrSize(1024), m_SigData(NULL) 
{
}

GenSignal::GenSignal(int dataVolume) : m_Type(""), m_Amplitude(1), m_DataArrSize(dataVolume)
{
	m_SigData = new double[dataVolume];
	for (int i = 0; i < dataVolume; i++) {
		m_SigData[i] = 0.0;
	}
}

GenSignal::~GenSignal() {
	delete m_SigData;
} 

void GenSignal::setStyle(CString style) { m_Type = style; }
void GenSignal::setStyle(char *style) { m_Type = style; }
void GenSignal::setAmp(double amplitude) { m_Amplitude = amplitude; }
void GenSignal::setVolume(int dataVolume) { 
	m_DataArrSize = dataVolume; 
	
	delete m_SigData;
	m_SigData = NULL;
	
	m_SigData = new double[dataVolume];
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigData[i] = 0.0;
	}
}

void GenSignal::makeSin(int frequency, int sampling, double phase) { 
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigData[i] = 0.0;
	}
	if (m_Type == "Sin" || m_Type == "sin") {
		for (int x = 0; x < m_DataArrSize; x++) {
			m_SigData[x] = -1 * m_Amplitude * sin((2 * Pi * frequency / sampling) * x + phase * Pi);
		}
	}
}
void GenSignal::makeCos(int frequency, int sampling, double phase) {
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigData[i] = 0.0;
	}
	if (m_Type == "Cos" || m_Type == "cos") {
		for (int x = 0; x < m_DataArrSize; x++) {
			m_SigData[x] = m_Amplitude * cos((2 * Pi * frequency / sampling) * x + phase * Pi);
		}
	}
}
void GenSignal::makeImpulse() {
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigData[i] = 0.0;
	}
	if (m_Type == "Impulse" || m_Type == "impulse") {
		m_SigData[0] = m_Amplitude;
	}
}
void GenSignal::makeImpulse(int position) {
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigData[i] = 0.0;
	}
	if (m_DataArrSize <= position) return;			// (error) 배열의 범위 밖 참조
	if (m_Type == "Impulse" || m_Type == "impulse") {
		m_SigData[position] = m_Amplitude;
	}
}
void GenSignal::makeImpulseTrain(int interval) {
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigData[i] = 0.0;
	}
	if (m_Type == "Impulse Train" || m_Type == "impulse train") {
		for (int x = 0; x < m_DataArrSize; x += interval) {
			m_SigData[x] = m_Amplitude;
		}
	}
}
void GenSignal::makeUniform() {
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigData[i] = 0.0;
	}
	if (m_Type == "Uniform" || m_Type == "uniform") {
		for (int x = 0; x < m_DataArrSize; x++) {
			m_SigData[x] = m_Amplitude;
		}
	}
}