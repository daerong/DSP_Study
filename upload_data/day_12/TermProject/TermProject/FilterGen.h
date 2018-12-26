#pragma once
class FilterGen
{
private:
	CString m_Type;
	double m_Amplitude;
	int m_DataArrSize;				// ������ ����

public:
public:
	double *m_FreqData;				// ���� ���ļ��� ����Ǵ� �迭

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

