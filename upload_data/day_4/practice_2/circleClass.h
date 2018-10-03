#include "standard.h"

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
	int returnRadius();
};

double Circle::getArea() {
	return 3.14*radius*radius;
}

int Circle::returnRadius() {
	return radius;
}
