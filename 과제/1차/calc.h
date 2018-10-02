#include "standard.h"

int menu_choice() {
	int choice = 0;

	do {
		cout << "---------------------------" << endl;
		cout << "�޴��� �����ϼ���." << endl;
		cout << "1. ���ϱ�" << endl;
		cout << "2. ����" << endl;
		cout << "3. ���ϱ�" << endl;
		cout << "4. ������" << endl;
		cout << "5. ����" << endl;
		cout << "---------------------------" << endl;
		cout << "���� �Է� : ";

		cin >> choice;

		system("cls");

	} while (choice < 1 || choice > 5);

	return choice;
}

void insert_target(int *x, int *y) {
	cout << "ù��° ���ڸ� �Է��ϼ��� : ";
	cin >> *x;
	cout << "�ι�° ���ڸ� �Է��ϼ��� : ";
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
		cout << "���� �Է� : ";
		cin >> answer;
		if (target == answer) {
			cout << "�����Դϴ�." << endl;
			status = 0;

			Sleep(1000);
		}
		else {
			cout << "�����Դϴ�." << endl;
			cout << "����Ű�� ���� �ٽ�Ǯ��" << endl;
			cout << "Esc Ű�� ���� ���亸��" << endl;
			char key;
			do {
				key = _getch();
			} while (key != ENTER && key != ESC);
			if (key == ESC) {
				status = 0;
				cout << "���� : " << target << endl;
				cout << "����Ű�� ������" << endl;

				do {
					key = _getch();
				} while (key != ENTER);
			}
		}
		system("cls");
	} while (status);
}