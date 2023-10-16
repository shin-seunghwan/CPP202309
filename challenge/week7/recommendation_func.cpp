#include <iostream>
using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPreferences[NUM_USERS][NUM_ITEMS];



void initializePreferences(int userPreferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "����� " << (i + 1) << "�� ��ȣ���� �Է��ϼ��� (";
		cout << NUM_ITEMS << "���� �׸� ����): ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
		}
	}
	
}

void  findRecommendedItems(const int userPreferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
			if (userPreferences[i][j]) {

			}
		}

		//����ڿ��� ��õ�ϴ� �׸��� ������ش�.
		cout << "�����" << (i + 1) << "���� ��õ�ϴ� �׸�: ";
		cout << (maxPreferenceIndex + 1) << std::endl;
	}

}

int main() {

	initializePreferences(userPreferences);
	findRecommendedItems(userPreferences);

	return 0;
}

