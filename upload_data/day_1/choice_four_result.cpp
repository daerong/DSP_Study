#include <iostream>
#include <string>
#include <Windows.h>        // system()
#include <conio.h>            // _getch()

using namespace std;

int list_view(void);
void list_view2(void);
string tryTest(double);

//int main() {
//
//	int select = 0;
//	double num1, num2;
//	double result;
//
//	cout << "ù��° ���ڸ� �Է��ϼ��� : ";
//	cin >> num1;
//	cout << "�ι�° ���ڸ� �Է��ϼ��� : ";
//	cin >> num2;
//
//	while ((select = list_view()) != 6)                // 8. Exit
//	{
//		while (getchar() != '\n');                    // ���� ����, fflush ������ �� ���
//		system("cls");
//
//		if (select == 1) {                            // 1. ����
//			result = num1 + num2;
//			cout << tryTest(result) << endl;
//		}
//		else if (select == 2) {                        // 2. ����
//			result = num1 - num2;
//			cout << tryTest(result) << endl;
//		}
//		else if (select == 3) {                        // 3. ����
//			result = num1 * num2;
//			cout << tryTest(result) << endl;
//		}
//		else if (select == 4) {                        // 4. ������
//			result = num1 / num2;
//			cout << tryTest(result) << endl;
//		}
//		else if (select == 5) {							// 5. ���� �Է�
//			cout << "ù��° ���ڸ� �Է��ϼ��� : ";
//			cin >> num1;
//			cout << "�ι�° ���ڸ� �Է��ϼ��� : ";
//			cin >> num2;
//		}
//		else {                                        // ���� ó��
//
//		}
//	}
//
//	return 0;
//}

int main() {

	char select = '\n';
	double num1, num2;
	double result;

	cout << "ù��° ���ڸ� �Է��ϼ��� : ";
	cin >> num1;
	cout << "�ι�° ���ڸ� �Է��ϼ��� : ";
	cin >> num2;

	while (select != '2')                // 8. Exit
	{
		list_view2();
		cin >> select;

		system("cls");

		if (select == '+') {                            // 1. ����
			result = num1 + num2;
			cout << tryTest(result) << endl;
		}
		else if (select == '-') {                        // 2. ����
			result = num1 - num2;
			cout << tryTest(result) << endl;
		}
		else if (select == '*') {                        // 3. ����
			result = num1 * num2;
			cout << tryTest(result) << endl;
		}
		else if (select == '/') {                        // 4. ������
			result = num1 / num2;
			cout << tryTest(result) << endl;
		}
		else if (select == '1') {							// 5. ���� �Է�
			cout << "ù��° ���ڸ� �Է��ϼ��� : ";
			cin >> num1;
			cout << "�ι�° ���ڸ� �Է��ϼ��� : ";
			cin >> num2;
		}
		else if (select == '2') {
			cout << "���α׷��� �����մϴ�.." << endl;
		}
		else {                                        // ���� ó��
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}

		char exit = 0;
		printf("Enter");

		do {
			exit = _getch();
		} while (exit != 13);

		system("cls");
	}
	
	return 0;
}

void list_view2(void) {
	int choice = 0;

	cout << "Select Menu" << endl;
	cout << "---------------------------" << endl;
	cout << "+. ����" << endl;
	cout << "-. ����" << endl;
	cout << "*. ����" << endl;
	cout << "/. ������" << endl;
	cout << "1. ���� �Է�" << endl;
	cout << "2. ����" << endl;
	cout << "---------------------------" << endl;
	cout << "select : ";
}

int list_view(void) {
	int choice = 0;

	cout << "Select Menu" << endl;
	cout << "---------------------------" << endl;
	cout << "1. ����" << endl;
	cout << "2. ����" << endl;
	cout << "3. ����" << endl;
	cout << "4. ������" << endl;
	cout << "5. ���� �Է�" << endl;
	cout << "6. ����" << endl;
	cout << "---------------------------" << endl;

	cin >> choice;

	return choice;
}

string tryTest(double Result) {

	double answer;

	cout << "������ �Է��ϼ��� : ";
	cin >> answer;

	if (Result == answer) {
		return "�����Դϴ�.";
	}
	else {
		return "�����Դϴ�.";
	}
}