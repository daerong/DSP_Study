#pragma once
#define M 50			// 배율(Magnification)

class DrawSignal
{
private:
	int m_DataArrSize;				// 저장할 갯수
	int m_Interval;

public:
	DrawSignal();
	DrawSignal(int dataVolume);
	~DrawSignal();

	void setVolume(int dataVolume);
	void setInterval(int interval);
	void setSignal(double inputData[]);		// inputData의 크기가 작을 경우, 잘못된 메모리를 복사합니다.
	void setSignal(double inputData[], int volume);

	void drawWave(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green);
	void drawDot(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green);
	void drawImpulse(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green);
	void drawStair(CDC* pDC, CPoint CP, int sigStart, BYTE red, BYTE blue, BYTE green);

public:
	double *m_SigData;				// 실제 신호가 저장되는 배열
};

