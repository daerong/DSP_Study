#include "standard.h"

#define PI 3.14;

typedef enum SHAPETYPE {
	TRIANGLE = 1,		// �ﰢ��
	RECTANGLE = 2,		// �簢��
	TRAPEZOID = 3,		// ��ٸ���
	CIRCLE = 4			// ��
} SHAPETYPE;

class SHAPE {
private :
	SHAPETYPE shapetype;
	int x, y, z;
	double are;
public :
	int insert_shapetype();
	void set_length();
	void calc_are();
	void show_length();
	int is_correct(int);
	void show_correct();
	int try_anwser();
};

int SHAPE::insert_shapetype() {
	int choice = 0;

	do {
		system("cls");
		cout << "---------------------------" << endl;
		cout << "������ �����ϼ���." << endl;
		cout << "1. �ﰢ��" << endl;
		cout << "2. �簢��" << endl;
		cout << "3. ��ٸ���" << endl;
		cout << "4. ��" << endl;
		cout << "5. ����" << endl;
		cout << "---------------------------" << endl;
		cout << "���� ���� : ";

		cin >> choice;

	} while (choice < 1 || choice > 5);

	switch (choice) {
	case 1: shapetype = TRIANGLE; break;
	case 2: shapetype = RECTANGLE; break;
	case 3: shapetype = TRAPEZOID; break;
	case 4: shapetype = CIRCLE; break;
	}

	return choice;
}

void SHAPE::set_length() {
	switch (shapetype) {
	case TRIANGLE : 
		cout << "�غ��� ���̸� �Է��ϼ��� : ";
		cin >> x;
		cout << "���̸� �Է��ϼ��� : ";
		cin >> y;
		break;
	case RECTANGLE:
		cout << "������ ���̸� �Է��ϼ��� : ";
		cin >> x;
		cout << "������ ���̸� �Է��ϼ��� : ";
		cin >> y;
		break;
	case TRAPEZOID:
		cout << "������ ���̸� �Է��ϼ��� : ";
		cin >> x;
		cout << "�Ʒ����� ���̸� �Է��ϼ��� : ";
		cin >> y;
		cout << "���̸� �Է��ϼ��� : ";
		cin >> z;
		break;
	case CIRCLE:
		cout << "���������� �Է��ϼ��� : ";
		cin >> x;
		break;
	default: cout << "error : undefined shapetype" << endl;
	}
	system("cls");
}

void SHAPE::calc_are() {
	switch (shapetype) {
	case TRIANGLE:
		are = (double)x * y / 2;
		break;
	case RECTANGLE:
		are = (double)x * y;
		break;
	case TRAPEZOID:
		are = (double)(x + y) * z / 2;
		break;
	case CIRCLE:
		are = (double)x * x * PI;
		break;
	}
}

int SHAPE::is_correct(int answer) {
	if (are == answer) return 1;
	else return 0;
}

void SHAPE::show_length() {
	switch (shapetype) {
	case TRIANGLE:
		cout << "�غ��� ���� : " << x << endl;
		cout << "���� : " << y << endl;
		break;
	case RECTANGLE:
		cout << "���� ���� : " << x << endl;
		cout << "���� ���� : " << y << endl;
		break;
	case TRAPEZOID:
		cout << "������ ���� : " << x << endl;
		cout << "�Ʒ����� ���� : " << y << endl;
		cout << "���� : " << z << endl;
		break;
	case CIRCLE:
		cout << "������ : " << x << endl;
		cout << "PI = 3.14" << endl;;
		break;
	}
}

void SHAPE::show_correct() {
	cout << "���̴� " << are << " �Դϴ�." << endl;
}

int SHAPE::try_anwser() {
	int answer = 0;
	show_length();
	cout << "���̸� �Է��ϼ��� : ";
	cin >> answer;
	if (is_correct(answer)) {
		cout << "�����Դϴ�.\n" << endl;
		return 0;
	}
	else {
		cout << "�����Դϴ�.\n" << endl;
		cout << "����Ű�� ���� �ٽ�Ǯ��" << endl;
		cout << "Esc Ű�� ���� ���亸��" << endl;
		char key;
		do {
			key = _getch();
		} while (key != ENTER && key != ESC);
		if (key == ESC) {
			show_correct();
			do {
				key = _getch();
			} while (key != ENTER);
			return 0;
		}
	}
	// while (getchar() != '\n');
	system("cls");
	return 1;
}