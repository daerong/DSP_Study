#include <iostream>		// h�� ������ �ʴ� ������ Ŭ������
#include <string>
#include <Windows.h>	// system() �Լ��� ����ϱ� ���ؼ� include

using namespace std;

int main() {

	int int1, int2;

	double result[4];		// +, -, *, /

	cout << "insert int1 : ";
	cin >> int1;

	cout << "insert int2 : ";
	cin >> int2;


	result[0] = int1 + int2;
	result[1] = int1 - int2;
	result[2] = int1 * int2;
	result[3] = int1 / int2;
	cout << "�� ���� ������ ����� " << result[3] << "�Դϴ�." << endl;
	result[3] = (double)int1 / (double)int2;
	cout << "�� ���� ������ ����� " << result[3] << "�Դϴ�." << endl;
	result[3] = (double)(int1 / int2);
	cout << "�� ���� ������ ����� " << result[3] << "�Դϴ�." << endl;
	result[3] = (double)int1 / int2;
	cout << "�� ���� ������ ����� " << result[3] << "�Դϴ�." << endl;

	

	cout << "�� ���� ���� ����� " << result[0] << "�Դϴ�." << endl;
	cout << "�� ���� ���� ����� " << result[1] << "�Դϴ�." << endl;
	cout << "�� ���� ���� ����� " << result[2] << "�Դϴ�." << endl;
	cout << "�� ���� ������ ����� " << result[3] << "�Դϴ�." << endl;


	return 0;
}