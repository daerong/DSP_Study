#include <iostream>		// h�� ������ �ʴ� ������ Ŭ������
#include <string>
#include <Windows.h>	// system() �Լ��� ����ϱ� ���ؼ� include

using namespace std;

int main() {

	int int1,int2;
	string str1, str2;

	int sum;
	
	int tryNum;

	cout << "insert int1 : ";
	cin >> int1;

	cout << "insert int2 : ";
	cin >> int2;


	cout << "�� ���� ū ���� ";
	if (int1 > int2) {
		cout << int1;
	}
	else {
		cout << int2;
	}
	cout << "�Դϴ�." << endl;

	sum = int1 + int2;

	cout << "���� ����� ? : ";
	cin >> tryNum;

	system("cls");

	if (tryNum == sum) {
		cout << "�����Դϴ�." << endl;
	}
	else {
		cout << "�����Դϴ�." << endl;
	}
	

	cout << "�� ���� ���� " << sum << "�Դϴ�." << endl;


	//cout << "int1 = " << int1 << ", int2 = " << int2 << endl;

	//sum = int1 + int2;

	//cout << "sum = " << sum << endl;

	//cout << "insert str1 : ";
	//cin >> str1;
	//
	//cout << "insert str2 : ";
	//cin >> str2;

	//cout << str1 + str2;

	return 0;
}