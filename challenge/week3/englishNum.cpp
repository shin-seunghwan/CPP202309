#include <iostream>
using namespace std;

int main() {

	int number; // 변수 선언
	cout << "숫자를 입력하시오: "; // 사용자에게 입력을 받는다
	cin >> number; // 입력은 받은 수를 number에 넣는다

	if (number == 0)
		cout << "Zero\n" << endl;
	// 사용자가 0을 입력했다면 Zero를 출력
	else if (number == 1)
		cout << "One\n" << endl;
	// 사용자가 0이 아닌 1을 입력했다면 One 출력
	else
		cout << "Many\n" << endl;
	// 사용자가 0도 1도 아닌 다른 수를 입력했다면 Many 출력

	return 0;
}