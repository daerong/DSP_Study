#include <iostream>
#include <string>

using namespace std;

int main() {

	int array[10] = { 1,2,3,4,5,6 };
	int *pt = &array[3];

	//int *pt = array;	// &array[0];
	cout << "pt林家" << pt << "pt郴侩" << *pt << endl;

	cout << "&array[3]林家" << &array[3] << "array[3]郴侩" << array[3] << endl;
	pt++;
	cout << "pt林家" << pt << "pt郴侩" << *pt << endl;


	return 0;
}