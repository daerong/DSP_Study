#pragma once
class SignalFunction
{
private:
	int m_DataArrSize;				// ������ ����

public:
	SignalFunction();
	SignalFunction(int dataVolume);
	~SignalFunction();

	void setVolume(int dataVolume);

	int convolution(double inputSig[], int InputWidth, double TransSig[], int TransWidth);

public:
	double *m_SigResult;				// ���� ��ȣ�� ����Ǵ� �迭
};

