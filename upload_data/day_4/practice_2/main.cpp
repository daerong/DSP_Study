#include "circleClass.h"

int main() {

	Circle circleArray[3];

	for (int i = 0; i < 3; i++) {
		circleArray[i].setRadius((i + 1) * 10);
		cout << "Circle " << i << "�� ������ " << circleArray[i].getArea() << endl;
	}

	Circle *p;
	p = circleArray;

	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i << "�� ������ " << (p++)->getArea() << endl;
	}




	return 0;
}