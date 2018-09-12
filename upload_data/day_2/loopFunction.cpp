#include <iostream>
#include <Windows.h>
#include <conio.h>	// _getch

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32

using namespace std;

void insertTwoData(int *, int *);
int classifyByOperator(int, int, int);


int main() {
	//int sum = 0;

	//for (int i = 0; i <= 100; i += 2) {
	//	sum += i;
	//}
	//cout << sum << endl;

	//while (getchar() != '\n');
	//system("cls");

	//sum = 0;

	//for (int i = 0; i <= 100; i++) {
	//	switch (i % 2 == 0) {
	//	case 1 :
	//		sum += i;
	//		break;
	//	default:
	//		break;
	//	}
	//	
	//}
	//cout << sum << endl;

	//unsigned char Ch = 0;

	//for (Ch = 65; Ch <= 90; Ch++) {
	//	cout << Ch << endl;
	//}

	//Ch = 97;

	//while (getchar() != '\n');

	//system("cls");

	//while (Ch <= 122) {
	//	cout << Ch << endl;
	//	Ch++;
	//}


	int intForCompare = 0;
	unsigned char intToChar;
	int target1 = 0, target2 = 0;

	while (intForCompare != 79) {

		intForCompare = _getch();
		intToChar = (unsigned char)intForCompare;

		switch (intToChar) {
		case 49:
			cout << "���� ������ �����մϴ�." << endl;
			break;
		case 50:
			cout << "�E�� ������ �����մϴ�." << endl;
			break;
		case 51:
			cout << "���� ������ �����մϴ�." << endl;
			break;
		case 52:
			cout << "������ ������ �����մϴ�." << endl;
			break;
		default:
			continue;
		}

		insertTwoData(&target1, &target2);
		cout << classifyByOperator(target1, target2, intToChar) << endl;

		system("cls");

	}

	return 0;
}

void insertTwoData(int *data1, int *data2) {
	cout << "ù��° ���� �Է��ϼ���";
	cin >> *data1;
	cout << "�ι�° ���� �Է��ϼ���";
	cin >> *data2;
}

int classifyByOperator(int data1, int data2, int typeIndex) {
	int result = 0;
	switch (typeIndex) {
	case 49:
		result = data1 + data2;
	case 50:
		result = data1 - data2;
	case 51:
		result = data1 * data2;
	case 52:
		result = data1 / data2;
	}

	return result;
}