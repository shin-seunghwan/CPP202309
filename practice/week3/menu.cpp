#include <iostream>
using namespace std;

int main() {
	int choice; // choice 라는 변수 선언

	cout << "1.파일 저장" << endl;
	cout << "2.저장 없이 닫기" << endl;
	cout << "3.종료" << endl;
	//특정 문장을 출력
	cin >> choice;
	//입력 받은 것을 choice에 넣는다

	switch (choice) {
		case 1:
			cout << "파일 저장을 선택했습니다." << endl;
			break;
			// 입력 값이 1일 경우 위의 문장 출력 후 종료
		case 2:
			cout << "파일 닫기를 선택했습니다." << endl;
			break;
			// 입력 값이 2일 경우 위의 문장 출력 후 종료
		case 3:
			cout << "프로그램을 종료합니다." << endl;
			break;
			// 입력 값이 3일 경우 위의 문장 출력 후 종료
		default:
			cout << "잘못된 선택입니다." << endl;
			break;
			// 입력 값이 1,2,3이 아닐 경우 위의 문장 출력 후 종료

	}

	return 0;
}