#include "stdafx.h"
#include "SignalFunction.h"

SignalFunction::SignalFunction() : m_DataArrSize(1024)
{
}
SignalFunction::SignalFunction(int dataVolume) : m_DataArrSize(dataVolume)
{
	m_SigResult = new double[dataVolume];
	for (int i = 0; i < dataVolume; i++) {
		m_SigResult[i] = 0.0;
	}
}
SignalFunction::~SignalFunction()
{
	delete m_SigResult;
}

void SignalFunction::setVolume(int dataVolume) {
	m_DataArrSize = dataVolume;
	
	delete m_SigResult;
	m_SigResult = NULL;

	m_SigResult = new double[dataVolume];
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigResult[i] = 0.0;
	}
}

int SignalFunction::convolution(double inputSig[], int InputWidth, int inputSignalStart, double TransSig[], int TransWidth, int transSignalStart, int *resultStart) {
	double resizeFactor = 0.0;

	m_DataArrSize = InputWidth + TransWidth;			// �� ����
	
	double *reverseInput = new double[InputWidth];		// input�� ������ �Լ�
	for (int i = 0; i < InputWidth; i++) {
		reverseInput[i] = 0.0;
	}
	for (int i = 0; i < InputWidth; i++) {
		reverseInput[i] = inputSig[InputWidth - 1 - i];
	}

	int reverseInputStart = -1 * (InputWidth + inputSignalStart);		// �������� �Լ��� ������

	delete m_SigResult;
	m_SigResult = NULL;

	m_SigResult = new double[m_DataArrSize];			// convolution ���� �� �����Ͱ� ����� �迭
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigResult[i] = 0.0;
	}

	int ConvSignalStart = transSignalStart + inputSignalStart;			// convolution ���� �� �������� ������
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

	for (int i = 0; i < m_DataArrSize; i++) { m_SigResult[i] /= resizeFactor; }

	*resultStart = reverseInputStart;
	return m_DataArrSize;
}



