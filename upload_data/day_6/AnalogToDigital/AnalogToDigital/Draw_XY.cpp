#include "stdafx.h"
#include "Draw_XY.h"


Draw_XY::Draw_XY() {
}

Draw_XY::Draw_XY(int xStart, int yStart, int xEnd, int yEnd) : x_Start(xStart), x_End(xEnd), y_Start(yStart), y_End(yEnd) {
}

Draw_XY::Draw_XY(CPoint start, CPoint end) : x_Start(start.x), x_End(end.x), y_Start(start.y), y_End(end.y) {
}

Draw_XY::~Draw_XY() {
}

void Draw_XY::setMatrix(int col, int row) {
	if (row != 0) { x_Raise = (x_End - x_Start) / row; }
	else { x_Raise = 99999; }
	if (col != 0) { y_Raise = (y_End - y_Start) / col; }
	else { y_Raise = 99999; }
}

void Draw_XY::setRaise(int xRaise, int yRaise) {
	if (xRaise != 0) { x_Raise = xRaise; }
	else { x_Raise = 99999; }
	if (yRaise != 0) { y_Raise = yRaise; }
	else { y_Raise = 99999; }
}

void Draw_XY::setTitle(CString title) {
	m_Title = title;
}

void Draw_XY::Disp_Coor(CDC* pDC) {
	// TODO: 여기에 구현 코드 추가.

	pDC->Rectangle(x_Start, y_Start, x_End, y_End);
	
	// 표 타이틀 출력
	if (!m_Title.IsEmpty()) { pDC->TextOut(x_Start + 5, y_Start + 5, m_Title); }

	// 그래프 그리기

	for (int i = x_Start + x_Raise; i < x_End; i += x_Raise) {
		pDC->MoveTo(i, y_Start);
		pDC->LineTo(i, y_End);
	}

	for (int i = y_Start + y_Raise; i < y_End; i += y_Raise) {
		pDC->MoveTo(x_Start, i);
		pDC->LineTo(x_End, i);
	}
}
