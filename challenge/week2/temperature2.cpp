#include <iostream>
using namespace std;

int main()
{
	double f_temp;
	double c_temp;

	//특정 문장 출력후 입력값을 각 변수에 저장
	cout << "섭씨온도 : ";
	cin >> c_temp;

	//변환을 위한 식 작성
	f_temp = c_temp / (5.0 / 9.0) + 32;

	cout << "화씨온도 = " << f_temp << endl;

	return 0;
}