#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1, s2;
	int count = 0;
	//���ڿ� �� ���� ����

	cout << "DNA1: ";
	cin >> s1;
	cout << "DNA2: ";
	cin >> s2;
	//�Է� �ް� ����

	if (s1.length() != s2.length())
		cout << "����: ���̰� �ٸ�" << endl;
	//�켱 �� ���ڿ��� ���̰� ������ Ȯ���ϱ� ���� ���̰� �ٸ��� ���
	
	else {
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] != s2[i])
				count += 1;
		}
		cout << "�ع� �Ÿ��� " << count << endl;
	}
	// ó������ Ȯ���ϸ鼭 ���ڿ��� �ٸ� ��ġ���� ������������ ī��Ʈ �ؼ� �ع� �Ÿ��� ����Ѵ�.
	return 0;
}