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
//	cout << "첫번째 숫자를 입력하세요 : ";
//	cin >> num1;
//	cout << "두번째 숫자를 입력하세요 : ";
//	cin >> num2;
//
//	while ((select = list_view()) != 6)                // 8. Exit
//	{
//		while (getchar() != '\n');                    // 버퍼 비우기, fflush 먹통일 때 사용
//		system("cls");
//
//		if (select == 1) {                            // 1. 덧셈
//			result = num1 + num2;
//			cout << tryTest(result) << endl;
//		}
//		else if (select == 2) {                        // 2. 뺄셈
//			result = num1 - num2;
//			cout << tryTest(result) << endl;
//		}
//		else if (select == 3) {                        // 3. 곱셈
//			result = num1 * num2;
//			cout << tryTest(result) << endl;
//		}
//		else if (select == 4) {                        // 4. 나눗셈
//			result = num1 / num2;
//			cout << tryTest(result) << endl;
//		}
//		else if (select == 5) {							// 5. 숫자 입력
//			cout << "첫번째 숫자를 입력하세요 : ";
//			cin >> num1;
//			cout << "두번째 숫자를 입력하세요 : ";
//			cin >> num2;
//		}
//		else {                                        // 예외 처리
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

	cout << "첫번째 숫자를 입력하세요 : ";
	cin >> num1;
	cout << "두번째 숫자를 입력하세요 : ";
	cin >> num2;

	while (select != '2')                // 8. Exit
	{
		list_view2();
		cin >> select;

		system("cls");

		if (select == '+') {                            // 1. 덧셈
			result = num1 + num2;
			cout << tryTest(result) << endl;
		}
		else if (select == '-') {                        // 2. 뺄셈
			result = num1 - num2;
			cout << tryTest(result) << endl;
		}
		else if (select == '*') {                        // 3. 곱셈
			result = num1 * num2;
			cout << tryTest(result) << endl;
		}
		else if (select == '/') {                        // 4. 나눗셈
			result = num1 / num2;
			cout << tryTest(result) << endl;
		}
		else if (select == '1') {							// 5. 숫자 입력
			cout << "첫번째 숫자를 입력하세요 : ";
			cin >> num1;
			cout << "두번째 숫자를 입력하세요 : ";
			cin >> num2;
		}
		else if (select == '2') {
			cout << "프로그램을 종료합니다.." << endl;
		}
		else {                                        // 예외 처리
			cout << "잘못 입력하셨습니다." << endl;
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
	cout << "+. 덧셈" << endl;
	cout << "-. 뺄셈" << endl;
	cout << "*. 곱셈" << endl;
	cout << "/. 나눗셈" << endl;
	cout << "1. 숫자 입력" << endl;
	cout << "2. 종료" << endl;
	cout << "---------------------------" << endl;
	cout << "select : ";
}

int list_view(void) {
	int choice = 0;

	cout << "Select Menu" << endl;
	cout << "---------------------------" << endl;
	cout << "1. 덧셈" << endl;
	cout << "2. 뺄셈" << endl;
	cout << "3. 곱셈" << endl;
	cout << "4. 나눗셈" << endl;
	cout << "5. 숫자 입력" << endl;
	cout << "6. 종료" << endl;
	cout << "---------------------------" << endl;

	cin >> choice;

	return choice;
}

string tryTest(double Result) {

	double answer;

	cout << "정답을 입력하세요 : ";
	cin >> answer;

	if (Result == answer) {
		return "정답입니다.";
	}
	else {
		return "오답입니다.";
	}
}