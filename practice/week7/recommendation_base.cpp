#include <iostream>
using namespace std;

int main()
{
	const int NUM_USERS = 3;
	const int NUM_ITEMS = 3;
	int userPreference[NUM_USERS][NUM_ITEMS];

	//�Է��� �޾Ƽ� 2���� �迭 ä���
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "�����" << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����): ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreference[i][j];
		}
	}

	//�� ����ڿ� ���ؼ� ��õ�ϴ� �׸� ã��
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreference = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreference[i][j] > userPreference[i][maxPreference]) {
				maxPreference = j;
			}
		}


		//����ڿ��� ��õ�ϴ� �׸��� ����Ѵ�.
		cout << "�����" << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreference + 1) << std::endl;
	}
	return 0;
}