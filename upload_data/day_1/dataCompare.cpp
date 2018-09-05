#include <iostream>		// h를 붙이지 않는 이유는 클래스라서
#include <string>
#include <Windows.h>	// system() 함수를 사용하기 위해서 include

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


	cout << "두 수중 큰 수는 ";
	if (int1 > int2) {
		cout << int1;
	}
	else {
		cout << int2;
	}
	cout << "입니다." << endl;

	sum = int1 + int2;

	cout << "덧셈 결과는 ? : ";
	cin >> tryNum;

	system("cls");

	if (tryNum == sum) {
		cout << "정답입니다." << endl;
	}
	else {
		cout << "오답입니다." << endl;
	}
	

	cout << "두 수의 합은 " << sum << "입니다." << endl;


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