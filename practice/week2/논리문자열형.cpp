#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1 = "good";
	string s2 = "bad";
	bool b = (s1 == s2);
	//문자열로 선언된 s1과 s2가 같은지에 대해 논리형으로 물어봄
	cout << b << endl;
	//s1과 s2가 다르기에 0으로 출력

	s2 = "good";
	b = (s1 == s2);
	//같기에 0으로 출력
	cout << b << endl;
}