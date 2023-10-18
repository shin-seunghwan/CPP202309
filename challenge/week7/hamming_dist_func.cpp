#include <iostream>
#include <string>
using namespace std;

//문자열의 모든 문자를 tolower을 이용해서 소문자로 만들어준다
string toLowerStr(string str) {
	string newstr = str;
	for (char& c : newstr){
		c = tolower(c);
	}
	return newstr;
}
//문자열의 모든 문자를 toupper를 이용해서 대문자로 만들어준다.
string toUpperStr(string str){
	string newstr = str;
	for (char& c : newstr) {
		c = toupper(c);
	}
	return newstr;
}

//입력 받은 s1,s2를 소문자로 만들어줘서 해밍거리 값을 구한다.
int calcHammingDist(string s1, string s2) {
	s1 = toLowerStr(s1);
	s2 = toLowerStr(s2);
	int count = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i])
			count += 1;
	}
	return count;
}

int main() {
	string s1, s2;

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;

	if (s1.length() != s2.length())
		cout << "오류: 길이가 다름" << endl;
	//우선 두 문자열이 길이가 같은지 확인하기 위해 길이가 다르면 출력

	else {
		int count = calcHammingDist(s1, s2);
		cout << "해밍 거리는 " << count << endl;
	}
	return 0;
}