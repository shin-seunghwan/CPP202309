#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL)); //random�Լ� ���� ����

	int answer = rand() % 100; //����
	int tries = 0; //�õ� Ƚ�� �����ϴ� ����

	int guess; //����� �Է� �����ϱ� ���� ����

	//hint : While / do-while ��
	do {
		cout << "������ �����Ͽ� ���ÿ�: "; // ������ �ѹ� ����ϰ� ����
		cin >> guess; //�Է°��� guess�� ����
		tries++; //tries �� Ƚ���� 1�� ����

		if (guess > answer)
			cout << "������ ������ �����ϴ�" << endl;
		if (guess < answer)
			cout << "������ ������ �����ϴ�" << endl;
		//���� 1�� �����ϸ� ���ٰ� ��� ���� 1�� �ƴϰ� 2�� �����ϸ� ���ٰ� ���

	} while (guess != answer);
	//guess �� answer�� �ٸ��� ó������ ���ư���, ���ٸ� �ݺ������� Ż��

	cout << "�����մϴ�. �õ� Ƚ�� = " << tries << endl;
	return 0;
}