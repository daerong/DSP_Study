#include "colorPoint.h"


int main() {
	// Point p; // �⺻ Ŭ������ ��ü ����
	//p.x; //Compile error
	ColorPoint cp; // �Ļ� Ŭ������ ��ü ����
	cp.set(3, 4); // �⺻ Ŭ������ ��� ȣ��
	cp.setColor("Red"); // �Ļ� Ŭ������ ��� ȣ��
	cp.showColorPoint(); // �Ļ� Ŭ������ ��� ȣ��
}