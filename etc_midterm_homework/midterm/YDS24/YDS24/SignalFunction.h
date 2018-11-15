#pragma once


class SignalFunction
{
private:
	int m_DataArrSize;				// 저장할 갯수

public:
	double *m_SigResult;				// 실제 신호가 저장되는 배열
	_complex *m_complexResult;			// An, Bn 개별 저장

public:
	SignalFunction();
	SignalFunction(int dataVolume);
	~SignalFunction();

	void setVolume(int dataVolume);

	int convolution(double inputSig[], int InputWidth, int inputSignalStart, double TransSig[], int TransWidth, int transSignalStart, int *resultStart);
	void fourierSeries(double inputSig[], int InputWidth, int resultWidth, int m_FS_Freq);
	void inverseFourierSeries(char *type, _complex inputFS[], int InputWidth, int resultWidth, int m_FS_Freq);
};

