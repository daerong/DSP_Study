#include "standard.h"

#define PI 3.14;

typedef enum SHAPETYPE {
	TRIANGLE = 1,		// 삼각형
	RECTANGLE = 2,		// 사각형
	TRAPEZOID = 3,		// 사다리꼴
	CIRCLE = 4			// 원
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
		cout << "도형을 선택하세요." << endl;
		cout << "1. 삼각형" << endl;
		cout << "2. 사각형" << endl;
		cout << "3. 사다리꼴" << endl;
		cout << "4. 원" << endl;
		cout << "5. 종료" << endl;
		cout << "---------------------------" << endl;
		cout << "도형 선택 : ";

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
		cout << "밑변의 길이를 입력하세요 : ";
		cin >> x;
		cout << "높이를 입력하세요 : ";
		cin >> y;
		break;
	case RECTANGLE:
		cout << "가로의 길이를 입력하세요 : ";
		cin >> x;
		cout << "세로의 길이를 입력하세요 : ";
		cin >> y;
		break;
	case TRAPEZOID:
		cout << "윗변의 길이를 입력하세요 : ";
		cin >> x;
		cout << "아랫변의 길이를 입력하세요 : ";
		cin >> y;
		cout << "높이를 입력하세요 : ";
		cin >> z;
		break;
	case CIRCLE:
		cout << "반지름를을 입력하세요 : ";
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
		cout << "밑변의 길이 : " << x << endl;
		cout << "높이 : " << y << endl;
		break;
	case RECTANGLE:
		cout << "가로 길이 : " << x << endl;
		cout << "세로 길이 : " << y << endl;
		break;
	case TRAPEZOID:
		cout << "윗변의 길이 : " << x << endl;
		cout << "아랫변의 길이 : " << y << endl;
		cout << "높이 : " << z << endl;
		break;
	case CIRCLE:
		cout << "반지름 : " << x << endl;
		cout << "PI = 3.14" << endl;;
		break;
	}
}

void SHAPE::show_correct() {
	cout << "넓이는 " << are << " 입니다." << endl;
}

int SHAPE::try_anwser() {
	int answer = 0;
	show_length();
	cout << "넓이를 입력하세요 : ";
	cin >> answer;
	if (is_correct(answer)) {
		cout << "정답입니다.\n" << endl;
		return 0;
	}
	else {
		cout << "오답입니다.\n" << endl;
		cout << "엔터키를 눌러 다시풀기" << endl;
		cout << "Esc 키를 눌러 정답보기" << endl;
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