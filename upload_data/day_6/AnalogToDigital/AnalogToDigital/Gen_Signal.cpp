#include "StdAfx.h" 
#include "Gen_Signal.h"

Gen_Signal::Gen_Signal() {
	Signal_Data = new double[1024];		// default data size
	m_dataVolume = 1024;
}

Gen_Signal::Gen_Signal(CString style, int amplitude, int frequency, int sampling) : m_string(style), m_Amplitude(amplitude), m_Frequency(frequency), DATA_No(sampling) {
	Signal_Data = new double[1024];		// default data size
	m_dataVolume = 1024;
}

Gen_Signal::~Gen_Signal() {
	delete Signal_Data;
} 

void Gen_Signal::setStyle(CString style) { m_string = style; }
void Gen_Signal::setAmp(double amplitude) { m_Amplitude = amplitude; }
void Gen_Signal::setFreq(int frequency) { m_Frequency = frequency; }
void Gen_Signal::setSampling(int sampling) { DATA_No = sampling; }
void Gen_Signal::setVolume(int volume) {
	delete Signal_Data;
	Signal_Data = new double[volume];
	m_dataVolume = volume;
}

//int Gen_Signal::getSampleVolume() { return DATA_No; }

void Gen_Signal::Make_Signal() { 

	if((m_string) == "sin") { 
		for (int x = 0; x < m_dataVolume; x++) {
			Signal_Data[x] = m_Amplitude * sin((2 * Pi * m_Frequency / DATA_No)*x + Pi / 2);
		}
	}
	else if ((m_string) == "cos") {
		for (int x = 0; x < m_dataVolume; x++) {
			Signal_Data[x] = m_Amplitude * cos((2 * Pi * m_Frequency / DATA_No)*x + Pi / 2);
		}
	}
}