#include "standard.h"

typedef enum COLORSET {};

// 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
class Point {
	int x, y; //한 점 (x,y) 좌표값
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point { 
	// 2차원 평면에서 컬러 점을 표현하는 클래스 ColorPoint.Point를 상속받음
	string color;// 점의 색 표현
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
	//void showParent();		
	// 형식지정자 생략시 pribate 적용. 따라서 자식클래스에서 사용불가
};
void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint(); // Point class showPoint() 호출
}

//void ColorPoint::showParent() {
//	cout << "(" << x << "," << y << ")" << endl;
}