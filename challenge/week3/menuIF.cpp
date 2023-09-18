#include <iostream>
using namespace std;

int main() {
	int choice;

	cout << "1.파일 저장" << endl;
	cout << "2.저장 없이 닫기" << endl;
	cout << "3.종료" << endl;
	//특정 문장을 출력
	cin >> choice;
	//입력 받은 것을 choice에 넣는다

	if (choice == 1)
		cout << "파일 저장을 선택했습니다." << endl;
	else if (choice == 2)
		cout << "파일 닫기를 선택했습니다." << endl;
	else if (choice == 3)
		cout << "프로그램을 종료합니다." << endl;
	else
		cout << "잘못된 선택입니다." << endl;

	return 0;
}