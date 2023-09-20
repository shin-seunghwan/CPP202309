#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL)); //random함수 관련 설정

	int answer = rand() % 100; //정답
	int tries = 0; //시도 횟수 저장하는 변수

	int guess; //사용자 입력 저장하기 위한 변수

	//hint : While / do-while 문
	do {
		cout << "정답을 추측하여 보시오: "; // 무조건 한번 출력하고 시작
		cin >> guess; //입력값을 guess에 저장
		tries++; //tries 의 횟수가 1씩 증가

		if (guess > answer)
			cout << "제시한 정수가 높습니다" << endl;
		if (guess < answer)
			cout << "제시한 정수가 낮습니다" << endl;
		//조건 1을 만족하면 높다고 출력 조건 1이 아니고 2를 만족하면 낮다고 출력

	} while (guess != answer);
	//guess 와 answer이 다르면 처음으로 돌아가기, 같다면 반복문에서 탈출

	cout << "축하합니다. 시도 횟수 = " << tries << endl;
	return 0;
}