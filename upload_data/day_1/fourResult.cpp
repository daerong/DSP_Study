#include <iostream>		// h를 붙이지 않는 이유는 클래스라서
#include <string>
#include <Windows.h>	// system() 함수를 사용하기 위해서 include

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
	cout << "두 수의 나눗셈 결과는 " << result[3] << "입니다." << endl;
	result[3] = (double)int1 / (double)int2;
	cout << "두 수의 나눗셈 결과는 " << result[3] << "입니다." << endl;
	result[3] = (double)(int1 / int2);
	cout << "두 수의 나눗셈 결과는 " << result[3] << "입니다." << endl;
	result[3] = (double)int1 / int2;
	cout << "두 수의 나눗셈 결과는 " << result[3] << "입니다." << endl;

	

	cout << "두 수의 덧셈 결과는 " << result[0] << "입니다." << endl;
	cout << "두 수의 뺄셈 결과는 " << result[1] << "입니다." << endl;
	cout << "두 수의 곱셈 결과는 " << result[2] << "입니다." << endl;
	cout << "두 수의 나눗셈 결과는 " << result[3] << "입니다." << endl;


	return 0;
}