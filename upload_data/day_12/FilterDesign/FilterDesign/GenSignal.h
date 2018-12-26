#pragma once

class GenSignal
{
private : 
	CString m_Type;
	double m_Amplitude;
	int m_DataArrSize;				// ������ ����

public:
	double *m_SigData;				// ���� ��ȣ�� ����Ǵ� �迭

public :
	GenSignal();
	GenSignal(int dataVolume);
	~GenSignal();

	void setStyle(CString style);
	void setStyle(char *style);
	void setAmp(double amplitude);
	void setVolume(int dataVolume);

	//int getSampleVolume();
	void makeSin(int frequency, int sampling, double phase);
	void makeCos(int frequency, int sampling, double phase);
	void makeImpulse();
	void makeImpulse(int position);
	void makeImpulseTrain(int interval);
	void makeUniform();
	void makeTriangular(int median, int width);
	void makeRectangle(int median, int width);
	void makeGaussian(int mean, int sigma);

};