#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int STUDENT = 5; //������ 5�� �ְ� ��� ����
	const int SUBJECT = 3; //������ 3�� �ְ� ��� ����
	int scores[STUDENT][SUBJECT];
	string studentNames[STUDENT] = {"����", "����", "ö��", "�̹�", "����" };
	string subjectNames[SUBJECT] = { "����", "����", "CPP" };
	//��� ����� ���� �°� �׸񺰷� �迭 ���� ����

	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ������ �ϳ��� �Է��ϼ���." << endl;
		//i ���� ���� �� �ʱ�ȭ ������ 0�� �ش��ϴ� �迭(���)�� ������ �Է��϶�� ����Ѵ�. 
		for (int j = 0; j < SUBJECT; j++) {
			cout << subjectNames[j] << ":";
			//j ���� ���� �� �ʱ�ȭ ������ 0,1,2�� �ش��ϴ� �迭(����)�� �Է��϶� ���
			cin >> scores[i][j];
			// �� ������ �ݺ� �ϸ鼭 ��� �л��� 3������ ������ ������� �ݺ��Ͽ� �Է¹޴´�.
		}
	}
	for (int i = 0; i < STUDENT; i++) {
		cout << studentNames[i] << "�� ��� ������ ";
		//i ���� ���� �� �ʱ�ȭ ������ "0�� �ش��ϴ� �迭�� ��� ������" ���
		double sum = 0;
		double average = 0;
		//sum �� average �Ǽ��� ���� �� �ʱ�ȭ
		for (int j = 0; j < SUBJECT; j++) {
			sum += scores[i][j];
		}
		//j ���� ���� �� �ʱ�ȭ ������ i=0�� �� �ش��ϴ� j(����)�� �ݺ��Ͽ� ���Ѵ�.
		average = sum / SUBJECT;
		cout << average << "�Դϴ�" << endl;
		// average ��� �� ���
	}
	return 0;
}
