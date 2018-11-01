#pragma once
#define M 50			// ����(Magnification)

class DrawSignal
{
private:
	int m_DataArrSize;				// ������ ����
	int m_Interval;

public:
	DrawSignal();
	DrawSignal(int dataVolume);
	~DrawSignal();

	void setVolume(int dataVolume);
	void setInterval(int interval);
	void setSignal(double inputData[]);		// inputData�� ũ�Ⱑ ���� ���, �߸��� �޸𸮸� �����մϴ�.
	void setSignal(double inputData[], int volume);

	void drawWave(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green);
	void drawDot(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green);
	void drawImpulse(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green);
	void drawStair(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green);

public:
	double *m_SigData;				// ���� ��ȣ�� ����Ǵ� �迭
};

