# DSP_Study

## DAY_1
### C언어 기초
###### 조카가 문제를 풀며 수학공부를 할 수 있는 프로그램을 만들어보기
###### 반복문, 함수 등 기초 문법
###### 포인터 접근, 변수형 등

## DAY_2
### 도형 넓이 계산 프로그램(과제 2차)
###### 삼각형, 사각형, 원, 사다리꼴의 넓이를 계산해주는 계산기, 문제를 풀고 답을 확인할 수 있다.
![5](https://user-images.githubusercontent.com/26676087/47061536-d16fb680-d20c-11e8-9b17-8c4efe3a41c8.PNG)
![9](https://user-images.githubusercontent.com/26676087/47061543-d6cd0100-d20c-11e8-9d81-9a5ed5179c56.PNG)
### 그 외
###### 헤더파일 별도 관리

## DAY_4
### Calculator
###### 문제를 풀고 정답을 맞출 수 있는 계산기(과제 1차)
![1](https://user-images.githubusercontent.com/26676087/47060593-36c1a880-d209-11e8-817c-9e5aee28c203.PNG)
![7](https://user-images.githubusercontent.com/26676087/47060617-49d47880-d209-11e8-9bc5-134f58419334.PNG)
### 그 외
###### 클래스 다중 상속, 여러 클래스를 상속받아 클래스를 만들 수 있음
###### 상속 범위, 접근 제한자
###### 클래스의 인자로 포인터나 참조형을 사용하는 이유, 생성자와 소멸자를 통해 알아보자. 
###### -> 생성자는 두번 생성되지만 소멸자는 한번 : delete 시에 이미 해제된 메모리를 해제하게 되면 프로그램에 문제가 발생할 수 있음
###### this 접근 방법 -> 클래스 형태로 가져올 때 멤버함수에 대한 메모리 부하는 없음
###### C에서의 malloc, calloc, realloc, free와 C++의 new, delete를 알아보기
###### 배열과 포인터를 사용해 클래스배열에 각각 접근하는 프로그램
###### 클래스, 헤더파일 분할, 생성자 오버로딩을 통한 계산 프로그램 만들기

## DAY_5
### Menu bar
###### 리소스 뷰의 Menu에서 편집기를 통해 메뉴를 생성하고 ID를 할당한 뒤 해당하는 기능을 작성하여 신호의 합성을 확인해보았다.
![default](https://user-images.githubusercontent.com/26676087/47059856-104e3e00-d206-11e8-862d-52c8387c7f09.PNG)
### What is signal
###### 신호의 파형에 영향을 주는 각 파라미터를 변경해보며 신호를 이해해본다. 또한 합성된 신호에 대한 해석을 해보자.
1. 각 파라미터가 신호의 파형에 미치는 영향
![_1](https://user-images.githubusercontent.com/26676087/47060182-8acb8d80-d207-11e8-828b-d9d390f1dc2f.PNG)
2. 서로 다른 주파수가 섞인 신호
![_2_](https://user-images.githubusercontent.com/26676087/47060076-07aa3780-d207-11e8-93d6-d3229e432fe0.PNG)
3. 샘플링 주파수의 이해
![_1](https://user-images.githubusercontent.com/26676087/47060296-0f1e1080-d208-11e8-94dc-9694f67a7254.PNG)
4. 여러 주기 신호가 합성되었을 때
![_3_](https://user-images.githubusercontent.com/26676087/47060078-0973fb00-d207-11e8-8398-3cad2ed95c79.PNG)

## DAY_6
### Analog to Digtal
###### MFC 내에 사용자 Class를 생성하여 박스 생성 및 그래프를 그리는 함수를 만들고 이를 View클래스의 OnDraw함수를 통해 그려보자.
![default](https://user-images.githubusercontent.com/26676087/47059725-8900ca80-d205-11e8-8d52-42b9b76f4562.PNG)

## DAY_7
### Convolution
###### 신호와 전달함수간의 연산인 Convolution에 대해 이해하고 이를 수행하는 프로그램을 작성해보자.
![1](https://user-images.githubusercontent.com/26676087/47537972-b59e9b80-d903-11e8-9a0c-056b657796a2.PNG)

## DAY_8
### Convolution(Using New Dialog)
###### 입력신호와 전달함수의 생성부를 새로운 Dialog에서 한번에 실행할 수 있도록 함
![2](https://user-images.githubusercontent.com/26676087/47763296-70afa600-dd03-11e8-94be-f26047915f3b.PNG)
### Convolution(좌표평면 사용)
###### 기존 Matrix 상에서 Rect 및 Tri, Impulse 함수의 테스트가 어려워 음수 영역으로 확장
![tri_rect](https://user-images.githubusercontent.com/26676087/47830081-ae790100-ddcd-11e8-8398-162a5b909d1e.PNG)
![uniform_sin](https://user-images.githubusercontent.com/26676087/47830083-afaa2e00-ddcd-11e8-9030-d32d87106e9a.PNG)
