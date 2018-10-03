#include "standard.h"

typedef enum COLORSET {};

// 2���� ��鿡�� �� ���� ǥ���ϴ� Ŭ���� Point ����
class Point {
	int x, y; //�� �� (x,y) ��ǥ��
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point { 
	// 2���� ��鿡�� �÷� ���� ǥ���ϴ� Ŭ���� ColorPoint.Point�� ��ӹ���
	string color;// ���� �� ǥ��
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
	//void showParent();		
	// ���������� ������ pribate ����. ���� �ڽ�Ŭ�������� ���Ұ�
};
void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint(); // Point class showPoint() ȣ��
}

//void ColorPoint::showParent() {
//	cout << "(" << x << "," << y << ")" << endl;
}