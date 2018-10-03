#include "standard.h"

void swap(int a, int b) {
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void swap(int *a, int *b) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
