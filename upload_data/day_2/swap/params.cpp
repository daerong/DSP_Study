#include "functions.h"

int main() {

	int data1 = 5, data2 = 10;

	int &data3 = data1;

	cout << "�ʱ� ������ data1 = " << data1 << ", data2 = " << data2 << endl;

	swap(data1, data2);

	cout << "���� �� ���� data3 = " << data3 << ", data2 = " << data2 << endl;

	swap(&data1, &data2);

	cout << "�ּ� ���� data3 = " << data1 << ", data2 = " << data2 << endl;
	

	return 0;
}