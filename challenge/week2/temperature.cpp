#include <iostream>
using namespace std;

int main()
{
	double f_temp;
	double c_temp;

	//특정 문장 출력후 입력값을 각 변수에 저장
	cout << "화씨온도 : ";
	cin >> f_temp;

	//변환을 위한 식 작성
	c_temp = (5.0 / 9.0) * (f_temp - 32);

	cout << "섭씨온도 = " << c_temp << endl;

	return 0;
}