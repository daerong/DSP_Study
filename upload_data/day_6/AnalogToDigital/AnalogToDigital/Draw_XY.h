#pragma once

class Draw_XY
{
private :
	int x_Start, x_End, y_Start, y_End;
	int x_Raise, y_Raise;
	CString m_Title;

public :
	Draw_XY(void);
	Draw_XY(int xStart, int yStart, int xEnd, int yEnd);
	Draw_XY(CPoint start, CPoint end);
	~Draw_XY(void);

	void setMatrix(int col, int row);	// (N, M) N�� M�� ����
	void setRaise(int xRaise, int yRaise);
	void setTitle(CString title);			// ǥ ���� �Է�
	void Disp_Coor(CDC* pDC);			// ǥ �׸���
};