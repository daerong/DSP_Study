#include "stdafx.h"
#include "SignalFunction.h"

#define PI 3.14

SignalFunction::SignalFunction() : m_DataArrSize(1024)
{
	m_SigResult = new double[1024];
	m_complexResult = new _complex[1024];
	for (int i = 0; i < 1024; i++) {
		m_SigResult[i] = 0.0;
		m_complexResult[i].x = 0.0;
		m_complexResult[i].y = 0.0;
	}
}
SignalFunction::SignalFunction(int dataVolume) : m_DataArrSize(dataVolume)
{
	m_SigResult = new double[dataVolume];
	m_complexResult = new _complex[dataVolume];
	for (int i = 0; i < dataVolume; i++) {
		m_SigResult[i] = 0.0;
		m_complexResult[i].x = 0.0;
		m_complexResult[i].y = 0.0;
	}
}
SignalFunction::~SignalFunction()
{
	delete m_SigResult;
	delete m_complexResult;
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

void SignalFunction::fourierSeries(double inputSig[], int InputWaveLength, int resultWidth, int m_FS_Freq) {
	m_DataArrSize = resultWidth;

	delete m_SigResult;
	m_SigResult = NULL;

	delete m_complexResult;
	m_complexResult = NULL;
	
	m_SigResult = new double[m_DataArrSize];			// Cn 배열
	m_complexResult = new _complex[m_DataArrSize];		// An : cos, Bn : sin 배열

	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigResult[i] = 0.0;
		m_complexResult[i].x = 0.0;
		m_complexResult[i].y = 0.0;
	}

	double real_cos = 0.0;
	double image_sin = 0.0;

	/* A0 */
	for (int n = 0; n < InputWaveLength; n++) {			// 변수명 무관, A0 성분을 구하는 과정
		real_cos += inputSig[n];
	}
	
	image_sin = real_cos / InputWaveLength;		// DC 성분

	m_SigResult[0] = image_sin;
	m_complexResult[0].x = image_sin / sqrt(2.0);
	m_complexResult[0].y = image_sin / sqrt(2.0);
	/* A0 */

	/* An, Bn, Cn */
	for (int freq = 1; freq < resultWidth; freq++) {
		real_cos = 0.0, image_sin = 0.0;

		for (int n = 0; n < InputWaveLength; n++) {			// 한 주기만 사용해야 올바른 결과
			real_cos += inputSig[n] * cos(2 * PI*freq*n / m_FS_Freq);
			image_sin += inputSig[n] * sin(2 * PI*freq*n / m_FS_Freq);
		}

		m_complexResult[freq].x = real_cos / (InputWaveLength / 2);
		m_complexResult[freq].y = image_sin / (InputWaveLength / 2);
		m_SigResult[freq] = sqrt(pow(m_complexResult[freq].x, 2.0) + pow(m_complexResult[freq].y, 2.0));
	}
	/* An, Bn, Cn */
}

void SignalFunction::inverseFourierSeries(char *type, _complex inputFS[], int InputWidth, int resultWidth, int m_FS_Freq) {
	m_DataArrSize = resultWidth;

	delete m_SigResult;
	m_SigResult = NULL;

	m_SigResult = new double[m_DataArrSize];			// fourierTransform 연산 후 데이터가 저장될 배열

	for (int i = 0; i < m_DataArrSize; i++) {
		m_SigResult[i] = 0.0;
	}

	if (type == "sin" || type == "Sin") {
		for (int n = 0; n < m_DataArrSize; n++) {
			m_SigResult[n] = inputFS[0].y;

			for (int i = 1; i < InputWidth; i += 1) {
				m_SigResult[n] += inputFS[i].y * sin(2 * PI*i*n / m_FS_Freq);
			}
		}
	}
	else if (type == "cos" || type == "Cos") {
		for (int n = 0; n < m_DataArrSize; n++) {
			m_SigResult[n] = inputFS[0].x;

			for (int i = 1; i < InputWidth; i += 1) {
				m_SigResult[n] += inputFS[i].x * cos(2 * PI*i*n / m_FS_Freq);
			}
		}
	}
	else if (type == "all" || type == "All") {
	
		for (int n = 0; n < m_DataArrSize; n++) {
			double sumX = inputFS[0].x;;
			double sumY = inputFS[0].y;;

			for (int i = 1; i < InputWidth; i += 1) {
				sumX += inputFS[i].x * cos(2 * PI*i*n / m_FS_Freq);
				sumY += inputFS[i].y * sin(2 * PI*i*n / m_FS_Freq);
			}
			if (sumX > 0) {
				m_SigResult[n] = sqrt(pow(sumX, 2.0) + pow(sumY, 2.0));
			}
			else {
				m_SigResult[n] = -1 * sqrt(pow(sumX, 2.0) + pow(sumY, 2.0));
			}

		}
	}
	else {
		for (int n = 0; n < m_DataArrSize; n++) {
			m_SigResult[n] = 0.5;
		}
	}
}



