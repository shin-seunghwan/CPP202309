#include <iostream>
using namespace std;

int main() {
	int choice; // choice ��� ���� ����

	cout << "1.���� ����" << endl;
	cout << "2.���� ���� �ݱ�" << endl;
	cout << "3.����" << endl;
	//Ư�� ������ ���
	cin >> choice;
	//�Է� ���� ���� choice�� �ִ´�

	switch (choice) {
		case 1:
			cout << "���� ������ �����߽��ϴ�." << endl;
			break;
			// �Է� ���� 1�� ��� ���� ���� ��� �� ����
		case 2:
			cout << "���� �ݱ⸦ �����߽��ϴ�." << endl;
			break;
			// �Է� ���� 2�� ��� ���� ���� ��� �� ����
		case 3:
			cout << "���α׷��� �����մϴ�." << endl;
			break;
			// �Է� ���� 3�� ��� ���� ���� ��� �� ����
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
			// �Է� ���� 1,2,3�� �ƴ� ��� ���� ���� ��� �� ����

	}

	return 0;
}