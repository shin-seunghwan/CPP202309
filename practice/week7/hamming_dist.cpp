#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int count = 0;
	//문자열 및 변수 선언

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;
	//입력 받고 저장

	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl;
	//우선 두 문자열이 길이가 같은지 확인하기 위해 길이가 다르면 출력
	
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << "해밍 거리는 " << count << endl;
	}
	// 처음부터 확인하면서 문자열이 다른 위치부터 같아질때까지 카운트 해서 해밍 거리를 계산한다.
	return 0;
}