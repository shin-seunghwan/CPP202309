#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10;
	int numlist[numCell][numCell];

	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			int elem = rand() % 1000; //1000���� ���� ������, �� 0 ~ 999�� �������� ����
			numlist[i][j] = elem;
			cout << i << "," << j << ":" << elem << endl;
		}
		//i�� ���� ���� �� �ʱ�ȭ ���� �� 0�� �� j�� 0���� 9���� �ݺ��Ǹ鼭 0,1  0,2 .... �ݺ� �ǰ� 
		//�׿� �ش��ϴ� numlist ���� elem ���� �־��ִ� �� elem�� �������� ����
		//���� ������ i�� 0���� 9���� �ݺ�
	}
	cout << endl;

	int max = 0;
	int maxI = 0;
	int maxJ = 0;
	// ���� ���� �� �ʱ�ȭ
	for (int i = 0; i < numCell; i++) {
		int j = 0; // ���� ���� �� for ���� �ۼ�
		for (auto value: numlist[i]){ //���� ��� �迭 �غ� $$
			// numlist[i]�� �ش��ϴ� �迭�� ��ĭ�� value�� �־��ش�
			if (max < value);
			max = value;
			maxI = i;
			maxJ = j;
		}
		j++; //j�� ��ĭ��ĭ�� �����ϵ��� ����
		
	}// �� ������ 0,0 ~ 9,9���� �ݺ��Ͽ� max�� ã�´�.

	cout << "���� ū ���� " << max << "�̰�,";
	cout << "i�� j�� ����" << maxI << "," << maxJ << "�Դϴ�." << endl;
	cout << "���� ��� :" << numlist[maxI][maxJ] << endl;
	//�ش� ������ �־��� ������ �Էµ� ����� �Բ� ���
	return 0;
}