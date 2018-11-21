#pragma once
#define PI 3.14

class SignalFunction
{
private:
	int m_DataArrSize;				// ������ ����

public:
	double *m_SigResult;				// ���� ��ȣ�� ����Ǵ� �迭

public:
	SignalFunction();
	SignalFunction(int dataVolume);
	~SignalFunction();

	void setVolume(int dataVolume);

	int convolution(double inputSig[], int InputWidth, int inputSignalStart, double TransSig[], int TransWidth, int transSignalStart, int *resultStart);
	void fourierSeries(char *type, double inputSig[], int InputWidth, int resultWidth, int m_FS_Freq);
};

