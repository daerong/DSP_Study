#include <iostream>
#include <string>

using namespace std;

int main() {

	int array[10] = { 1,2,3,4,5,6 };
	int *pt = &array[3];

	//int *pt = array;	// &array[0];
	cout << "pt�ּ�" << pt << "pt����" << *pt << endl;

	cout << "&array[3]�ּ�" << &array[3] << "array[3]����" << array[3] << endl;
	pt++;
	cout << "pt�ּ�" << pt << "pt����" << *pt << endl;


	return 0;
}