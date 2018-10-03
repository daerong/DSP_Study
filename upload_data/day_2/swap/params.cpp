#include "functions.h"

int main() {

	int data1 = 5, data2 = 10;

	int &data3 = data1;

	cout << "초기 데이터 data1 = " << data1 << ", data2 = " << data2 << endl;

	swap(data1, data2);

	cout << "변수 값 전달 data3 = " << data3 << ", data2 = " << data2 << endl;

	swap(&data1, &data2);

	cout << "주소 전달 data3 = " << data1 << ", data2 = " << data2 << endl;
	

	return 0;
}