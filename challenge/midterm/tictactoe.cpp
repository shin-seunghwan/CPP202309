#include <iostream>
using namespace std;

const int numCell = 3; // �������� ���� ���� ����
bool isValid(int x, int y, char board[][numCell]) {
	// ��ǥ�� ���� ������ ������� üũ
	if (x < 0 || x >= numCell || y < 0 || y >= numCell) {
		cout << x << "," << y << ": x�� y �� �� �ϳ��� ĭ�� ����ϴ�." << endl;
		return false;
	}
	// ��ǥ�� �̹� ���� �ִ��� üũ
	if (board[x][y] != ' ') {
		cout << x << "," << y << ": �̹� ���� �� �ֽ��ϴ�." << endl;
		return false;
	}
	return true; // ��ǥ�� ��ȿ��
}

int checkWin(char board[][3], int numCell) {
	int checked = 0;
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			if (board[i][j] == ' ') {
				checked++;
			}
		}
	}
	return checked;
}


int main() {
	// ������ �����ϴ� �� �ʿ��� ���� ����

	const int numCell = 3; // �������� ���� ���� ����
	int k = 0; // ���� �������� üũ�ϱ� ���� ����
	char currentUser = 'X'; // ���� ������ ���� �����ϱ� ���� ����
	char board[numCell][numCell]{}; // �������� ��Ÿ���� 2���� �迭
	int x, y = 0; // ����ڿ��� xy��ǥ���� �Է¹ޱ� ���� ����

	// ������ �ʱ�ȭ
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// ������ ���� �ݺ�
	while (true) {
		// 1. ���� �������� ���
		// TODO 1.1: 3�ο� �������� ����
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:
			currentUser = 'O';
			break;
		case 2:
			currentUser = 'H';
		}
		cout << k % 3 + 1 << "�� ����(" << currentUser << ")�� �����Դϴ�. -> ";

		// 2. ��ǥ �Է� �ޱ�
		cout << "(x, y) ��ǥ�� �Է��ϼ���: ";
		int x, y;
		cin >> x >> y;

		// 3. �Է¹��� ��ǥ�� ��ȿ�� üũ
		// TODO FUNC 1: isValid �Լ� ���� �� ȣ��
		if (!isValid(x, y, board)) {
			continue; // ��ȿ���� ���� ���, �Է��� �ٽ� ����
		}

		// 4. �Է¹��� ��ǥ�� ���� ������ �� ����
		board[x][y] = currentUser;

		// 5. ���� ���� �� ���
		// TODO 1.2: numCell ���ڿ� ���� ������ ���
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				cout << board[i][j];
				if (j < numCell - 1) {
					cout << "  |";
				}
			}
			cout << endl;
			if (i < numCell - 1) {
				for (int j = 0; j < numCell; j++) {
					cout << "---";
					if (j < numCell - 1) {
						cout << "|";
					}
				}
				cout << endl;
			}
		}
		cout << endl;
		k++;


		bool isWin = false; // �¸� ����
		// TODO FUNC2: 6.1���� 6.2���� checkWin �Լ� ���� �� ȣ��
		// 6.1. ����/���� �� üũ�ϱ�
		int checked = checkWin(board, numCell);
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�. �����մϴ�" << endl;
			break;
		}



		// 6.2. �밢���� üũ�ϱ�
		// TODO 1.3: numCell�� ���� �밢�� ���� üũ �ڵ�� Ȯ��
		// HINT: for ��
		for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "���� ������ ������ �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
				isWin = true;
			}
			if (board[0][numCell - 1 - i] == currentUser && board[1][numCell - i] == currentUser && board[2][i] == currentUser) {
				cout << "������ ������ ���� �Ʒ� �밢������ ��� ���� �������ϴ�!" << endl;
				isWin = true;
			}
		}

		// �¸��ڰ� �����Ǿ����� �ش� �÷��̾ ����ϰ� ������ �����Ѵ�.
		if (isWin == true) {
			cout << k % 2 + 1 << "�� ����(" << currentUser << ")�� �¸��Դϴ�!" << endl;
			break;
		}

		// 7. ��� ĭ �� á���� üũ�ϱ�

		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "��� ĭ�� �� á���ϴ�.  �����մϴ�. " << endl;
			break;
		}

		k++;
	}

	return 0;
}