#include <iostream>

using namespace std;


void disp_menu();
void calculate();
void disp_result();

int in_data1, in_data2, result;

int menu_sort;

int main() {
	disp_menu();
	calculate();
	disp_result();

	return 0;
}

void disp_menu() {
	cout << "====================================" << endl;
	cout << "=======  ������ �����ϼ���  =======" << endl;
	cout << "=======  1:+, 2:-, 3:*, 4:/  =======" << endl;
	cin >> menu_sort;
	cout << endl << endl;
	cout << "" << endl;
	cout << "=======  �� ���� �Է��ϼ���  =======" << endl;
	cin >> in_data1 >> in_data2;
}

void disp_result() {
	cout << "====================================" << endl;
	cout << "===========  ��������  ===========" << endl;
	cout << "����� : " << result << "�Դϴ�." << endl;
}

void calculate() {
	switch (menu_sort) {
	case 1: 
		result = in_data1 + in_data2;
		break;
	case 2:
		result = in_data1 - in_data2;
		break;
	case 3:
		result = in_data1 * in_data2;
		break;
	case 4:
		result = in_data1 / in_data2;
		break;
	}
}