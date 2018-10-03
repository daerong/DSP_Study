#include "calc.h"

int main() {

	SHAPE shape;

	while (shape.insert_shapetype() != 5) {
		system("cls");
		shape.set_length();
		shape.calc_are();
		while (shape.try_anwser());
	}

	return 0;
}