#include <iostream>
#include <string>

using namespace std;

int main() {

	//char ch = 'K';
	int numInt = 3;
	int *ptrInt;
	ptrInt = &numInt;
	//float numFloat = 1.43;

	cout << "�������� : " << numInt << ",\t\t�����ּ� : " << &numInt << endl;
	cout << "ptr���� : " << *ptrInt << ",\t\t�����ּ� : " << ptrInt << endl;



	//cout << "���ڳ��� : " << ch << ",\t\t���ں����ּ� : " << (int *)&ch << endl;
	///* [(int*)&ch]�� �ּҸ� ����(int)������ ��ȯ */
	//cout << "�������� : " << numInt << ",\t\t���������ּ� : " << &numInt << endl;
	//cout << "�Ǽ����� : " << numFloat << ",\t�Ǽ������ּ� : " << &numFloat << endl;

	return 0;
}