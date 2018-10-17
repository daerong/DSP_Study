#include "stdafx.h"
#include "Draw_XY.h"


Draw_XY::Draw_XY()
{
}


Draw_XY::~Draw_XY()
{
}

void Draw_XY::Disp_Coor(CDC* pDC) {
	// TODO: 여기에 구현 코드 추가.

	pDC->Rectangle(X_Start, Y_Start, X_End, Y_End);
	//문자출력
	CString Text;
	Text = "Generate Signal";
	pDC->TextOut(30, 30, Text);
	//x 축y축그리기

	for (int i = Y_Raise; i < Y_End; i += Y_Raise) {
		pDC->MoveTo(X_Start, Y_Start + i);
		pDC->LineTo(X_End, Y_Start + i);
	}
}
