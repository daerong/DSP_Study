#include "stdafx.h"
#include "SignalFunction.h"

#define PI 3.14

SignalFunction::SignalFunction() : m_DataArrSize(1024)
{
}
SignalFunction::SignalFunction(int dataVolume) : m_DataArrSize(dataVolume)
{
	m_SigResult_Sin = new double[dataVolume];
	for (int i = 0; i < dataVolume; i++) {
		m_SigResult_Sin[i] = 0.0;
		m_SigResult_Cos[i] = 0.0;
		m_SigResult[i] = 0.0;
	}
}
SignalFunction::~SignalFunction()
{
	delete m_SigResult_Sin;
	delete m_SigResult_Cos;
	delete m_SigResult;
}

void SignalFunction::setVolume(int dataVolume) {
	m_DataArrSize = dataVolume;
	
	delete m_SigResult_Sin;
	delete m_SigResult_Cos;
	delete m_SigResult;
	m_SigResult_Sin = NULL;
	m_SigResult_Cos = NULL;
	m_SigResult;

	m_SigResult_Sin = new double[dataVolume];
	m_SigResult_Cos = new double[dataVolume];
	m_SigResult = new double[dataVolume];

	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigResult_Sin[i] = 0.0;
		m_SigResult_Cos[i] = 0.0;
		m_SigResult[i] = 0.0;
	}
}

int SignalFunction::convolution(double inputSig[], int InputWidth, int inputSignalStart, double TransSig[], int TransWidth, int transSignalStart, int *resultStart) {
	double resizeFactor = 0.0;

	m_DataArrSize = InputWidth + TransWidth;			// 총 길이
	
	double *reverseInput = new double[InputWidth];		// input을 뒤집은 함수
	for (int i = 0; i < InputWidth; i++) {
		reverseInput[i] = 0.0;
	}
	for (int i = 0; i < InputWidth; i++) {
		reverseInput[i] = inputSig[InputWidth - 1 - i];
	}

	int reverseInputStart = -1 * (InputWidth + inputSignalStart);		// 뒤집어진 함수의 시작점

	delete m_SigResult;
	m_SigResult = NULL;

	m_SigResult = new double[m_DataArrSize];			// convolution 연산 후 데이터가 저장될 배열
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigResult[i] = 0.0;
	}

	int ConvSignalStart = transSignalStart + inputSignalStart;			// convolution 연산 후 데이터의 시작점
	double convolutionResult = 0.0;

	for (int i = 0; i < m_DataArrSize; i++) {
		convolutionResult = 0.0;
		if (i < InputWidth) {
			for (int j = 0; j <= i; j++) {
				convolutionResult += reverseInput[InputWidth - 1 - (i - j)] * TransSig[j];
			}
			m_SigResult[i] = convolutionResult;
			if (resizeFactor < m_SigResult[i]) { resizeFactor = m_SigResult[i]; }
		}
		else {
			for (int j = i - InputWidth; j <= TransWidth; j++) {
				convolutionResult += reverseInput[j - (i - InputWidth)] * TransSig[j];
			}
			m_SigResult[i] = convolutionResult;
			if (resizeFactor < m_SigResult[i]) { resizeFactor = m_SigResult[i]; }
		}
	}

	delete reverseInput;

	for (int i = 0; i < m_DataArrSize; i++) { m_SigResult[i] /= resizeFactor; }

	*resultStart = ConvSignalStart;
	return m_DataArrSize;
}

void SignalFunction::fourierTransform(double inputSig[], int InputWidth, int resultWidth, int m_FS_Freq, int m_CoeNo) {
	m_DataArrSize = resultWidth;

	if (m_CoeNo > InputWidth) return;			// 배열 overflow 방지

	delete m_SigResult_Sin;
	delete m_SigResult_Cos;
	m_SigResult_Sin = NULL;
	m_SigResult_Cos = NULL;
	
	m_SigResult_Sin = new double[m_DataArrSize];			// fourierTransform 연산 후 데이터가 저장될 배열
	m_SigResult_Cos = new double[m_DataArrSize];

	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigResult_Sin[i] = 0.0;
		m_SigResult_Cos[i] = 0.0;
	}

	for (int n = 0; n < m_DataArrSize; n++)
	{
		m_SigResult_Sin[n] = 0.0;
		m_SigResult_Cos[n] = 0.0;

		for (int i = 1; i < m_CoeNo; i += 1)
		{            
			m_SigResult_Sin[n] += inputSig[i] * sin(2 * PI*i*n / m_FS_Freq);
			m_SigResult_Cos[n] += inputSig[i] * cos(2 * PI*i*n / m_FS_Freq);
		}
	}
}



