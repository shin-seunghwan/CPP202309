#include <iostream>

using namespace std;

int main()
{
	const int GREATE_VICTORY_SALSU = 612;
	//GREATE_VICTORY_SALSUF를 const를 이용해 상수 선언
	const int GREATE_VICTORY_GWIJU = 1019;
	//GREATE_VICTORY_GWIJU를 const를 이용해 상수 선언

	cout << "고구려 살수대첩 연도 : " << GREATE_VICTORY_SALSU << "년" << endl;
	cout << "고려 귀주대첩 연도 : " << GREATE_VICTORY_GWIJU << "년" << endl;
	//변수 출력방법과 동일하게 상수 출력
	return 0;
}