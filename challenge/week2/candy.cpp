#include <iostream>
using namespace std;

int main()
{
	int money;
	int candy_price;

	//특정 문장 출력후 입력값을 각 변수에 저장
	cout << "현재 가지고 잇는 돈: ";
	cin >> money;
	cout << "캔디의 가격: ";
	cin >> candy_price;

	//나눗셈을 이용해 개수 카운트
	int n_candies = money / candy_price;
	cout << "최대로 살 수 있는 캔디의 개수= " << n_candies << endl;

	//%를 이용해 나누고 나머지 값을 계산
	int change = money % candy_price;
	cout << "캔디 구입 후 남은 돈= " << change << endl;
	return 0;
}