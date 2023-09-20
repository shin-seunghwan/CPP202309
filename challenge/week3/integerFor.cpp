#include <iostream>
using namespace std;

int main()
{
	int userInput; // 함수 선언

	cout << "정수를 10번 입력하세요 (0을 입력하면 종료) : "; //문장을 출력

	for (int i = 1; i < 10; i++) 
		// for(초기식; 조건식; 증감식)의 형식에 따라 입력횟수는 1부터 시작하고 9번까지 입력 받고 횟수는 1씩증가  
	{
		cin >> userInput; //입력 받은 내용을 저장
		if (userInput == 0) // 만약 0을 입력받으면 바로 종료
		{
			break;
		}

		cout << "입력값: " << userInput << "횟수 : " << i << endl;
		//위의 내용에 따라 출력 그 이후 처음으로 돌아감
	}

	cout << "종료 되었습니다.";

	return 0;
}


	
	
	
	
	
	
	
	
