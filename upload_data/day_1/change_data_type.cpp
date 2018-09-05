#include <iostream>
#include <string>

using namespace std;

int main() {

	//char ch = 'K';
	int numInt = 3;
	int *ptrInt;
	ptrInt = &numInt;
	//float numFloat = 1.43;

	cout << "정수내용 : " << numInt << ",\t\t정수주소 : " << &numInt << endl;
	cout << "ptr내용 : " << *ptrInt << ",\t\t정수주소 : " << ptrInt << endl;



	//cout << "문자내용 : " << ch << ",\t\t문자변수주소 : " << (int *)&ch << endl;
	///* [(int*)&ch]는 주소를 정수(int)값으로 변환 */
	//cout << "정수내용 : " << numInt << ",\t\t정수변수주소 : " << &numInt << endl;
	//cout << "실수내용 : " << numFloat << ",\t실수변수주소 : " << &numFloat << endl;

	return 0;
}