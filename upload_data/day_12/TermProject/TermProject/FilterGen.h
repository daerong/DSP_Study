#pragma once
class FilterGen
{
private:
	CString m_Type;
	double m_Amplitude;
	int m_DataArrSize;				// 저장할 갯수

public:
public:
	double *m_FreqData;				// 실제 주파수가 저장되는 배열

public:
	FilterGen();
	FilterGen(int dataVolume);
	~FilterGen();

	void setStyle(CString style);
	void setStyle(char *style);
	void setAmp(double amplitude);
	void setVolume(int dataVolume);
	
	void makeLPF(int freq, int underArea);
	void makeButterworth(int freq, int degree, int underArea);
	void makeChebyshev(int freq, int degree, int underArea);
};

