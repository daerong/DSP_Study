#include "colorPoint.h"


int main() {
	// Point p; // 기본 클래스의 객체 생성
	//p.x; //Compile error
	ColorPoint cp; // 파생 클래스의 객체 생성
	cp.set(3, 4); // 기본 클래스의 멤버 호출
	cp.setColor("Red"); // 파생 클래스의 멤버 호출
	cp.showColorPoint(); // 파생 클래스의 멤버 호출
}