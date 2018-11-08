#pragma once
class DrawMatrix
{
private:
	int m_StartX, m_StartY, m_EndX, m_EndY;
	int m_Col, m_Row;

public:
	DrawMatrix();
	DrawMatrix(int startX, int startY, int endX, int endY);
	DrawMatrix(CPoint start, CPoint end);
	~DrawMatrix();
	
	// ������� �� ����
	void SetOutline(int startX, int startY, int endX, int endY);
	void SetOutline(CPoint start, CPoint end);
	void SetDivide(int col, int row);

	// �ֿ� �Լ�
	void StartDraw(CDC *pDC);
};

