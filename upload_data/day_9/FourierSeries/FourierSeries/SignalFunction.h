#pragma once
#define PI 3.14

class SignalFunction
{
private:
	int m_DataArrSize;				// 저장할 갯수

public:
	SignalFunction();
	SignalFunction(int dataVolume);
	~SignalFunction();

	void setVolume(int dataVolume);

	int convolution(double inputSig[], int InputWidth, int inputSignalStart, double TransSig[], int TransWidth, int transSignalStart, int *resultStart);
	void fourierTransform(double inputSig[], int InputWidth, int resultWidth, int m_FS_Freq, int m_CoeNo);

public:
	double *m_SigResult_Sin;				// 실제 신호가 저장되는 배열
	double *m_SigResult_Cos;
	double *m_SigResult;
};

