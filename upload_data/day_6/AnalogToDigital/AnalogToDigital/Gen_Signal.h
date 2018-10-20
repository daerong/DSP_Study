#pragma once

#define Pi 3.14159
#include <math.h>

class Gen_Signal
{
private : 
	CString m_string;
	int DATA_No, m_Frequency;
	double m_Amplitude;

public :
	Gen_Signal();
	Gen_Signal(CString style, int amplitude, int frequency, int sampling);
	~Gen_Signal();

	void setStyle(CString style);
	void setAmp(double amplitude);
	void setFreq(int frequency);
	void setSampling(int sampling);
	void setVolume(int volume);
	//int getSampleVolume();
	void Make_Signal();

public:
	double *Signal_Data;
	int m_dataVolume;
};