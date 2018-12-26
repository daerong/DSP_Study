#include "stdafx.h"
#include "DrawMatrix.h"

DrawMatrix::DrawMatrix() : m_StartX(10), m_StartY(10), m_EndX(110), m_EndY(110), m_Col(1), m_Row(1)
{
}
DrawMatrix::DrawMatrix(int startX, int startY, int endX, int endY) : m_StartX(startX), m_StartY(startY), m_EndX(endX), m_EndY(endY), m_Col(1), m_Row(1)
{
}
DrawMatrix::DrawMatrix(CPoint start, CPoint end) : m_StartX(start.x), m_StartY(start.y), m_EndX(end.x), m_EndY(end.y), m_Col(1), m_Row(1)
{
}
DrawMatrix::~DrawMatrix()
{
}

void DrawMatrix::SetOutline(int startX, int startY, int endX, int endY) {
	m_StartX = startX;
	m_StartY = startY;
	m_EndX = endX;
	m_EndY = endY;
}
void DrawMatrix::SetOutline(CPoint start, CPoint end) {
	m_StartX = start.x;
	m_StartY = start.y;
	m_EndX = end.x;
	m_EndY = end.y;
}
void DrawMatrix::SetDivide(int col, int row) {
	m_Col = col;
	m_Row = row;
}

void DrawMatrix::StartDraw(CDC *pDC) {
	if (m_Row < 0) return;
	else if (m_Col < 0) return;
	int width_Div = (m_EndX - m_StartX) / m_Row;
	int height_DIv = (m_EndY - m_StartY) / m_Col;

	pDC->Rectangle(m_StartX, m_StartY, m_EndX, m_EndY);

	for (int i = m_StartX + width_Div; i < m_EndX; i += width_Div) {		// 열 나누기(그리기)
		pDC->MoveTo(i, m_StartY);
		pDC->LineTo(i, m_EndY);
	}

	for (int i = m_StartY + height_DIv; i < m_EndY; i += height_DIv) {		// 행 나누기(그리기)
		pDC->MoveTo(m_StartX, i);
		pDC->LineTo(m_EndX, i);
	}
}