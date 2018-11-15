#pragma once


class SignalFunction
{
private:
	int m_DataArrSize;				// ������ ����

public:
	double *m_SigResult;				// ���� ��ȣ�� ����Ǵ� �迭
	_complex *m_complexResult;			// An, Bn ���� ����

public:
	SignalFunction();
	SignalFunction(int dataVolume);
	~SignalFunction();

	void setVolume(int dataVolume);

	int convolution(double inputSig[], int InputWidth, int inputSignalStart, double TransSig[], int TransWidth, int transSignalStart, int *resultStart);
	void fourierSeries(double inputSig[], int InputWidth, int resultWidth, int m_FS_Freq);
	void inverseFourierSeries(char *type, _complex inputFS[], int InputWidth, int resultWidth, int m_FS_Freq);
};

