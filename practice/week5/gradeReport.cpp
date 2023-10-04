#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int STUDENT = 5; //변수에 5를 넣고 상수 선언
	const int SUBJECT = 3; //변수에 3을 넣고 상수 선언
	int scores[STUDENT][SUBJECT];
	string studentNames[STUDENT] = {"영수", "영희", "철수", "미미", "쥬쥬" };
	string subjectNames[SUBJECT] = { "수학", "영어", "CPP" };
	//상수 선언된 수에 맞게 항목별로 배열 내용 설정

	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 성적을 하나씩 입력하세요." << endl;
		//i 변수 선언 및 초기화 진행후 0에 해당하는 배열(사람)의 성적을 입력하라고 출력한다. 
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			//j 변수 선언 및 초기화 진행후 0,1,2에 해당하는 배열(성적)을 입력하라 출력
			cin >> scores[i][j];
			// 위 과정을 반복 하면서 모든 학생의 3과목의 성적을 순서대로 반복하여 입력받는다.
		}
	}
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "의 평균 점수는 ";
		//i 변수 선언 및 초기화 진행후 "0에 해당하는 배열의 평균 점수는" 출력
		double sum = 0;
		double average = 0;
		//sum 과 average 실수로 선언 및 초기화
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}
		//j 변수 선언 및 초기화 진행후 i=0일 때 해당하는 j(점수)를 반복하여 더한다.
		average = sum / SUBJECT;
		cout << average << "입니다" << endl;
		// average 계산 후 출력
	}
	return 0;
}
