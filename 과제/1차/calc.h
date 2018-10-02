#include "standard.h"

int menu_choice() {
	int choice = 0;

	do {
		cout << "---------------------------" << endl;
		cout << "메뉴를 선택하세요." << endl;
		cout << "1. 더하기" << endl;
		cout << "2. 빼기" << endl;
		cout << "3. 곱하기" << endl;
		cout << "4. 나누기" << endl;
		cout << "5. 종료" << endl;
		cout << "---------------------------" << endl;
		cout << "숫자 입력 : ";

		cin >> choice;

		system("cls");

	} while (choice < 1 || choice > 5);

	return choice;
}

void insert_target(int *x, int *y) {
	cout << "첫번째 숫자를 입력하세요 : ";
	cin >> *x;
	cout << "두번째 숫자를 입력하세요 : ";
	cin >> *y;
}

double start_calc(int x, int y, int type) {
	switch (type) {
	case 1:
		return x + y;
	case 2:
		return x - y;
	case 3:
		return x * y;
	case 4:
		return x / y;
	default :
		cout << "type select error : start_calc().type" << endl;
		exit(0);
		return 0;
	}
}

void show_result(double target) {
	int status = 1;
	float answer = 0.0;
	do {
		cout << "정답 입력 : ";
		cin >> answer;
		if (target == answer) {
			cout << "정답입니다." << endl;
			status = 0;

			Sleep(1000);
		}
		else {
			cout << "오답입니다." << endl;
			cout << "엔터키를 눌러 다시풀기" << endl;
			cout << "Esc 키를 눌러 정답보기" << endl;
			char key;
			do {
				key = _getch();
			} while (key != ENTER && key != ESC);
			if (key == ESC) {
				status = 0;
				cout << "정답 : " << target << endl;
				cout << "엔터키로 나가기" << endl;

				do {
					key = _getch();
				} while (key != ENTER);
			}
		}
		system("cls");
	} while (status);
}