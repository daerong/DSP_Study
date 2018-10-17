#include "stdafx.h"
#include "Draw_XY.h"


Draw_XY::Draw_XY()
{
}


Draw_XY::~Draw_XY()
{
}

void Draw_XY::Disp_Coor(CDC* pDC) {
	pDC->Rectangle(X_Start, Y_Start, X_End, Y_End); 
	CString Text; Text = "Signal "; 
	pDC->TextOut(30, 30, Text);

	pDC->MoveTo(X_Start,Y_Start+200); 
	pDC->LineTo(X_End, Y_Start+200); 
	pDC->MoveTo(X_Start,Y_Start+400); 
	pDC->LineTo(X_End, Y_Start+400); 
	pDC->MoveTo(X_Start,Y_Start+600); 
	pDC->LineTo(X_End, Y_Start+600); 
}
