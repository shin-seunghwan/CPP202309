#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	int i;
	int ans;
	cout << "산수 문제를 자동으로 출제합니다. " << endl;
	for (int i = 0; i < 5; i++) 
	{
		while (true)
		{
			int firstNum = rand() % 100;
			int secondNum = rand() % 100;

			//hint : 문제출력 > 답 입력 받기 > 평가가
			cout << firstNum << "+" << secondNum << "=";
			cin >> ans; //입력값 저장

			if (firstNum + secondNum == ans)
			{
				cout << "맞았습니다." << endl;
				break;
			}
			else {
				cout << "틀렸습니다." << endl;
			}
			// 문제 답이 입력값과 일치하면 맞았습니다, 일치하징않으면 틀렸습니다.

		}
	}
	return 0;
}