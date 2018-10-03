#include "standard.h"

class Circle {
private:
	int radius;
public:
	int publicRadius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea() { return 3.14*radius*radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};
Circle::Circle() {
	radius = 1;
	publicRadius = 1;
	cout << "������ ���� radius = " << radius << endl;
}
Circle::Circle(int radius) {
	this->radius = radius;
	publicRadius = radius;
	cout << "������ ���� radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}

void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}

void increase2(Circle c) {
	cout << "�������� �׽�Ʈ :" << c.publicRadius << endl;
}