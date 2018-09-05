#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;


// 과목명 학생 번호 이름 중간 기말 성적 분류
class student {
public :
	string name;
	string index;
	double midTerm;
	double endTerm;
	double average;
	
	void insertInfo();
	void insertAvr();
	void printInfo();
	string returnResult();
};

void student::insertInfo() {
	cout << "insert name : ";
	cin >> name;
	cout << "insert index : ";
	cin >> index;
	cout << "insert mid point : ";
	cin >> midTerm;
	cout << "insert end point : ";
	cin >> endTerm;
}

void student::insertAvr() {
	average = (midTerm + endTerm) / 2;
}

void student::printInfo() {
	cout << "name : " << name << endl << "index : " << index << endl << "mid point : " << midTerm << endl << "end point : " << endTerm << endl << "average point : " << average << endl;

}

string student::returnResult() {
	if (average > 90) {
		return "학점은 A입니다.";
	}
	else if (average > 80) {
		return "학점은 B입니다.";
	}
	else if (average > 70) {
		return "학점은 C입니다.";
	}
	else if (average > 60) {
		return "학점은 D입니다.";
	}
	else {
		return "학점은 F입니다.";
	}
}



int main() {

	student first;

	first.insertInfo();
	first.insertAvr();
	
	system("cls");

	first.printInfo();
	cout << first.returnResult() << endl;
	

	return 0;
}

