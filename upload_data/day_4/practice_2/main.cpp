#include "circleClass.h"

int main() {

	Circle circleArray[3];

	Circle *circleMalloc = (Circle *)malloc(sizeof(Circle) * 3);

	for (int i = 0; i < 3; i++) {
		circleArray[i].setRadius((i + 1) * 10);
		cout << "Circle " << i << "�� ������ " << circleArray[i].getArea() << endl;
		(circleMalloc + i)->setRadius(circleArray[i].returnRadius());
	}

	Circle *p;
	p = circleArray;

	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i << "�� ������ " << (p++)->getArea() << endl;
		cout << "Malloc " << i << "�� ������ " << (circleMalloc + i)->getArea() << endl;
	}





	return 0;
}