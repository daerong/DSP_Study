#pragma once
#define X_Start 20
#define Y_Start 20
#define X_End X_Start+1024
#define Y_End Y_Start+800
#define Y_Depth 3
class Draw_XY
{
public:
	Draw_XY(void);
	~Draw_XY(void);
	void Disp_Coor(CDC* pDC);
};