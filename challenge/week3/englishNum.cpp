#include <iostream>
using namespace std;

int main() {

	int number; // ���� ����
	cout << "���ڸ� �Է��Ͻÿ�: "; // ����ڿ��� �Է��� �޴´�
	cin >> number; // �Է��� ���� ���� number�� �ִ´�

	if (number == 0)
		cout << "Zero\n" << endl;
	// ����ڰ� 0�� �Է��ߴٸ� Zero�� ���
	else if (number == 1)
		cout << "One\n" << endl;
	// ����ڰ� 0�� �ƴ� 1�� �Է��ߴٸ� One ���
	else
		cout << "Many\n" << endl;
	// ����ڰ� 0�� 1�� �ƴ� �ٸ� ���� �Է��ߴٸ� Many ���

	return 0;
}