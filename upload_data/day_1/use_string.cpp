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
	cout << "弛" << object << " : " << data << endl;
}


int main() {

	int status = 0;

	objectData arr[5];

	for (int i = 0; i < 5; i++) {
		arr[i].insertNewData();
	}

	cout << "忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖" << endl;

	for (int i = 0; i < 5; i++) {
		arr[i].printData();
	}
	
	cout << "戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎" << endl;
	

	return 0;
}