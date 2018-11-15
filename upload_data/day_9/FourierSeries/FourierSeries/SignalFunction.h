#pragma once
#define PI 3.14

class SignalFunction
{
private:
	int m_DataArrSize;				// 저장할 갯수

public:
	double *m_SigResult;				// 실제 신호가 저장되는 배열

public:
	SignalFunction();
	SignalFunction(int dataVolume);
	~SignalFunction();

	void setVolume(int dataVolume);

	int convolution(double inputSig[], int InputWidth, int inputSignalStart, double TransSig[], int TransWidth, int transSignalStart, int *resultStart);
	void fourierSeries(char *type, double inputSig[], int InputWidth, int resultWidth, int m_FS_Freq);
};

