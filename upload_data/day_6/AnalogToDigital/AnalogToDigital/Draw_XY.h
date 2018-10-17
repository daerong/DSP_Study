#pragma once

/* Disp_Coor()에서 사용 */
#define X_Start 20
#define Y_Start 20
#define X_End X_Start+1024
#define Y_End Y_Start+750
#define Y_Depth 3
#define Y_Raise 150
/* Disp_Coor()에서 사용 */

class Draw_XY
{
public:
	Draw_XY(void);
	~Draw_XY(void);
	void Disp_Coor(CDC* pDC);
};