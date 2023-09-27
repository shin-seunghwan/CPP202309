#include <iostream>
using namespace std;

int main()
{
	int a, b, c, largest;
	//변수 선언

	cout << "3개의 정수를 입력하시오: ";
	//특정 문장을 출력하여 입력을 받는다
	cin >> a >> b >> c;
	//입력받은 수를 변수에 넣는다

	if (a > b && a > c) //a가 b보다 크고 a가 c보다 큰가?
		largest = a;  // 조건문 1에 해당하면 a가 largest
	else if (b > a && b > c) //b가 a보다 크고 b가 c보다 큰가?
		largest = b; // 조건문 2에 해당하면 b가 largest
	else
		largest = c; // 조건문 1,2에 해당하지 않으니 c가 largest
	
	cout << "가장 큰 정수는" << largest << endl;
	// 출력하기
	return 0;
}