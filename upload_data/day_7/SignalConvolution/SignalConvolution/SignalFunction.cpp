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
	if (m_SigResult != NULL) delete m_SigResult;
}

void SignalFunction::setVolume(int dataVolume) {
	m_DataArrSize = dataVolume;
	if (m_SigResult != NULL) delete m_SigResult;
	m_SigResult = new double[dataVolume];
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigResult[i] = 0.0;
	}
}

int SignalFunction::convolution(double inputSig[], int InputWidth, double TransSig[], int TransWidth) {	
	double resizeFactor = 0.0;

	m_DataArrSize = InputWidth + TransWidth;
	if (m_SigResult != NULL) delete m_SigResult;
	m_SigResult = new double[m_DataArrSize];
	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigResult[i] = 0.0;
	}

	for (int i = 0; i < m_DataArrSize; i++) {
		double convolutionResult = 0.0;
		for (int j = 0; j <= i; j++) {
			convolutionResult += inputSig[j] * TransSig[i - j];
		}
		m_SigResult[i] = convolutionResult;
		if (resizeFactor < m_SigResult[i]) { resizeFactor = m_SigResult[i]; }
	}

	for (int i = 0; i < m_DataArrSize; i++) { m_SigResult[i] /= resizeFactor; }

	return m_DataArrSize;
}



