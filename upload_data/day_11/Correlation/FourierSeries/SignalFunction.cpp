#include "stdafx.h"
#include "SignalFunction.h"

#define PI 3.14

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

	delete reverseInput;

	for (int i = 0; i < m_DataArrSize; i++) { m_SigResult[i] /= resizeFactor; }

	*resultStart = ConvSignalStart;
	return m_DataArrSize;
}

void SignalFunction::fourierSeries(char *type, double inputSig[], int InputWidth, int resultWidth, int m_FS_Freq) {
	m_DataArrSize = resultWidth;

	delete m_SigResult;
	m_SigResult = NULL;
	
	m_SigResult = new double[m_DataArrSize];			// fourierTransform ���� �� �����Ͱ� ����� �迭

	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigResult[i] = 0.0;
	}

	if (type == "sin" || type == "Sin") {
		for (int n = 0; n < m_DataArrSize; n++) {
			m_SigResult[n] = 0.0;

			for (int i = 1; i < InputWidth; i += 1) {
				m_SigResult[n] += inputSig[i] * sin(2 * PI*i*n / m_FS_Freq);
			}
		}
	}
	else if (type == "cos" || type == "Cos") {
		for (int n = 0; n < m_DataArrSize; n++) {
			m_SigResult[n] = 0.0;

			for (int i = 1; i < InputWidth; i += 1) {
				m_SigResult[n] += inputSig[i] * cos(2 * PI*i*n / m_FS_Freq);
			}
		}
	}
	else {
		for (int n = 0; n < m_DataArrSize; n++) {
			m_SigResult[n] = 0.5;
		}
	}
}

void SignalFunction::correlation(double inputSig1[], int InputWidth1, double inputSig2[], int InputWidth2) {
	for (int k = 0; k < InputWidth1; k++) {
		m_SigResult[k] = 0;
		for (int n = k; n < InputWidth2; n++) {
			m_SigResult[k] += inputSig1[n] * inputSig2[n - k];
		}
	}
}

void SignalFunction::fourierTranseform(double inputSig[], int InputWidth){
	double m_Real, m_Image;
	double T_Real, T_Image;
	for (int fre = 0; fre < InputWidth; fre++) {		// m_FTOut�� ����Ǵ� ���� Ư�� freq���� �Ǽ�&��� ���� ũ��
		T_Real = T_Image = 0;
		for (int n = 0; n < InputWidth; n++) {
			m_Real = inputSig[n] * cos(2 * PI*fre*n / InputWidth);			// Ư�� n������ �Ǽ���
			m_Image = inputSig[n] * sin(2 * PI*fre*n / InputWidth);			// Ư�� n������ �����
			T_Real += m_Real;												// Ư�� freq���� �Ǽ� ���� ��
			T_Image += m_Image;												// Ư�� freq���� ��� ���� ��
		}

		m_SigResult[fre] = sqrt(T_Real*T_Real + T_Image * T_Image);				// �Ǽ�, ����� ũ�⸦ ����
	}
}


