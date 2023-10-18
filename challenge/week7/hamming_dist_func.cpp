#include <iostream>
#include <string>
using namespace std;

//���ڿ��� ��� ���ڸ� tolower�� �̿��ؼ� �ҹ��ڷ� ������ش�
string toLowerStr(string str) {
	string newstr = str;
	for (char& c : newstr){
		c = tolower(c);
	}
	return newstr;
}
//���ڿ��� ��� ���ڸ� toupper�� �̿��ؼ� �빮�ڷ� ������ش�.
string toUpperStr(string str){
	string newstr = str;
	for (char& c : newstr) {
		c = toupper(c);
	}
	return newstr;
}

//�Է� ���� s1,s2�� �ҹ��ڷ� ������༭ �عְŸ� ���� ���Ѵ�.
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
		cout << "����: ���̰� �ٸ�" << endl;
	//�켱 �� ���ڿ��� ���̰� ������ Ȯ���ϱ� ���� ���̰� �ٸ��� ���

	else {
		int count = calcHammingDist(s1, s2);
		cout << "�ع� �Ÿ��� " << count << endl;
	}
	return 0;
}