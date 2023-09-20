#include <iostream>
using namespace std;

int main()
{
	int vowel = 0;
	int consonant = 0;
	cout << "영문자를 입력하고 ctrl+z를 치세요." << endl;
	// 변수 선언 및 초기화 진행 및 특정 문장 출력

	char ch; //사용자 입력을 저장하기 위한 변수 선언

	//HINT : while + switch 문 활용

	while (cin >> ch) //입력 받은 값을 ch에 저장한다
	{
		switch (ch)
		{
		case 'a':
			vowel += 1;
			break;
		case 'e':
			vowel += 1;
			break;
		case 'i':
			vowel += 1;
			break;
		case 'o':
			vowel += 1;
			break;
		case 'u':
			vowel += 1;
			break;
		default:
			consonant += 1;
			break;
		}
	// 조건식 ch 가 a,e,i,o,u와 같다면 vowel + 1 해주고 그 외에는 consonant +1을 해준다 
	// 그리고 사용자가 컨트롤 z를 누를때까지 입력을 한 모든 값을 처리해준다
	}

	cout << "모음: " << vowel << endl;
	cout << "자음: " << consonant << endl;
	// 위에서 횟수가 더해진 값을 출력한다.
	
	return 0;
}