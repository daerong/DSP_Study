#include <iostream>
#include <string>

using namespace std;

class objectData {
public :
	string object;
	string data;
	void insertNewData();
	void printData();
};

void objectData::insertNewData() {
	cout << "object : ";
	cin >> object;
	cout << "data : ";
	cin >> data;
}

void objectData::printData() {
	cout << "��" << object << " : " << data << endl;
}


int main() {

	int status = 0;

	objectData arr[5];

	for (int i = 0; i < 5; i++) {
		arr[i].insertNewData();
	}

	cout << "��������������������������������������������������������������������" << endl;

	for (int i = 0; i < 5; i++) {
		arr[i].printData();
	}
	
	cout << "��������������������������������������������������������������������" << endl;
	

	return 0;
}