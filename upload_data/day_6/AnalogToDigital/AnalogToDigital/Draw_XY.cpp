#include "stdafx.h"
#include "Draw_XY.h"


Draw_XY::Draw_XY()
{
}


Draw_XY::~Draw_XY()
{
}

void Draw_XY::Disp_Coor(CDC* pDC) {
	// TODO: ���⿡ ���� �ڵ� �߰�.

	pDC->Rectangle(X_Start, Y_Start, X_End, Y_End);
	//�������
	CString Text;
	Text = "Generate Signal";
	pDC->TextOut(30, 30, Text);
	//x ��y��׸���

	for (int i = Y_Raise; i < Y_End; i += Y_Raise) {
		pDC->MoveTo(X_Start, Y_Start + i);
		pDC->LineTo(X_End, Y_Start + i);
	}
}
