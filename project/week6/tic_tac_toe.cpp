#include <iostream>
using namespace std;

int main() {
	// 3-3 ���� ���� ��� ���� �� �迭 �� ���� ����
	const int numCell = 3;
	char board[numCell][numCell]{};
	int x, y;

	//�ݺ����� �̿��� ���� �� ĭ���� ��, �ʱ�ȭ ����
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	//���� �������� Ȯ���� ���� ���� ���� �� �ش� ������ ���� �����ϱ� ���� ���� ����
	int k = 0;
	char currentUser = 'X';

	//�ݺ����� �ݺ��� ���� switch �Լ��� ���� ���ʸ� ����
	while (true) {
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "�� ����(X)�� �����Դϴ� -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "�� ����(O)�� �����Դϴ� -> ";
			currentUser = 'O';
			break;
		}
		
		//��ǥ�� �Է� �޾� x,y�� ����
		cout << "(x,y) ��ǥ�� �Է��ϼ���:";
		cin >> x >> y;
		
		//���� ���� ����ų� �ߺ��Ǵ� ���� ����
		if (x >= numCell || y >= numCell) {
			cout << x << "," << y << ": ";
			cout << "x�� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": �̹� ���� ���ֽ��ϴ�." << endl;
			continue;
		}

		//�Էµ� ��ǥ�� ǥ��
		board[x][y] = currentUser;

		//��ǥ�� ǥ�õ� �͵��� ������ ���� ���
		for (int i = 0; i < numCell; i++) {
			cout << "---|---|---" << endl;
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j == numCell - 1){
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
		cout << "---|---|---" << endl;
		k++;

		//������ ���� �ϰ� ���� ��� ĭ�� �ݺ������� ���� �������� ������ ������ +1�� �ϰ� 
		//�������� ������ �ƴҽ� ���ǹ� ������ ���� �ٸ� ���ǹ� full==0�� ���� �����ϸ� ��� ĭ�� �� �������� �Ǵ�
		int full = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					full++;
				}
			}
		}
		if (full == 0) {
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�" << endl;
			break;
		}
		// ���� üũ
		bool isWin = false;
		
		//���� ������ ���� ���� ĭ�� ���� or ���ΰ� ���� ��츦 ã�� ���
		//���� ������ ���� ���� ĭ�� �밢���� ���� ��츦 ���ǹ��� ���� ã�� ���
		//���� �ΰ��� ��츦 �����ϸ� ����� � ��쿡 ���� �¸����� ����Ѵ�.
		for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "���ο� ��� ���� �������ϴ�!: ";
				isWin = true;
			}
			if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
				cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
				isWin = true;
			}
			if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
				cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!: ";
				isWin = true;
			}
			if (isWin == true) {
				cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
				cout << "�����մϴ�" << endl;
				break;
			}
		}
	}
	return 0;
}