#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3;
	//cout << "�� ���� ���� �Է��϶�: ";
	//cin >> maxPeople;
	//������ �Է� �ް� �� ���� �־�� ������ ��ǻ�Ͱ� �Է� �ޱ� ���� 
	//��Ȯ�� ���� �𸥴ٰ� ���� �߻��ϹǷ� �׳� ���ó�� �� ����
	string names[maxPeople];
	int ages[maxPeople];

	for (int i = 0; i < maxPeople; ++i) {
		cout << "���" << i + 1 << "�� �̸�: ";
		cin >> names[i];
		cout << "���" << i + 1 << "�� ����: ";
		cin >> ages[i];
	}// �Է¹��� �� ��ŭ �ݺ��ϸ鼭 �̸��� ���̸� �Է¹޴´�.

	int ageThreshold;
	cout << "Ư�� ���� �̻��� ����� ã������ ���̸� �Է��ϼ���: ";
	cin >> ageThreshold;
	// �Է� �ް� ����

	cout << ageThreshold << "�� �̻��� ����:\n";
	// � �̻���  ���� ã���� �Է� �ޱ�
	int detectedPeople = 0; // ���� ���� �� �ʱ�ȭ
	for (int i = 0; i < maxPeople; ++i) {
		if (ages[i] >= ageThreshold) {
			cout << names[i] << " (" << ages[i] << "��)\n";
			detectedPeople ++;
		// �Է¹��� �� �̻��̶�� ���, detectedPeope 1 ����
		}
	}//maxPeolple �� �� ��ŭ �ݺ��Ͽ� ���� = ��� ����� ���� Ȯ�� ����
	if (detectedPeople == 0) {
		cout << ageThreshold << "�̻��� ���̸� ���� ���� �����ϴ�";
	}// ��� �� ��ŭ Ȯ�� �� detectedPeople �� 0 (�̻��� ���ٸ�)�̸� ���
	return 0;
}