#include <iostream>
#include <string>
using namespace std;

//��� ���� �� �ʱ�ȭ
const int mapX = 5;
const int mapY = 5;

// ��ȹ�� 3���� �Լ� ����(������� ��ġ üũ �Լ�, ������ ���� ��ġ ��� �Լ�, �������� ���� üũ �Լ�)
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);

int userHP = 20;

// ����  �Լ�
int main() {
	// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������ ���� �迭 ����
	int map[mapY][mapX] = { {0, 1, 2, 0, 4},
					{1, 0, 0, 2, 0},
					{0, 0, 0, 0, 0},
					{0, 2, 3, 0, 0},
					{3, 0, 0, 0, 2} };

	// ������ ��ġ�� ������ ���� ���� �� �ʱ�ȭ
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ���� ����
		string user_input = "";
		cout << "��ɾ �Է��ϼ��� (��,��,��,��,����,����): ";
		cin >> user_input;

		if (user_input == "��") {
			// ���� �� ĭ �ö󰡱�
			user_y -= 1;
			//���� ��ĭ �ö� ���� ������� �ƴ��� üũ
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y += 1;
			}
			//����� �ʾҴٸ� ���
			else {
				cout << "���� �� ĭ �ö󰩴ϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "��") {
			// TODO: �Ʒ��� �� ĭ ��������
			user_y += 1;
			//�Ʒ��� �� ĭ ������ ���� ������� �ƴ��� üũ�ϰ� ����ٸ� ���
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_y -= 1;
			}
			//����� �ʾҴٸ� ���
			else {
				cout << "�Ʒ��� �� ĭ �������ϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "��") {
			// TODO: �������� �̵��ϱ�
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			//�������� ��ĭ �� ���� ������� �ƴ��� üũ�ϰ� ����ٸ� ���
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x += 1;
			}
			//����� �ʾҴٸ� ���
			else {
				cout << "�������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "��") {
			// TODO: ���������� �̵��ϱ�
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			//���������� ��ĭ �� ���� ������� �ƴ��� üũ�ϰ� ����ٸ� ���
			if (inMap == false) {
				cout << "���� ������ϴ�. �ٽ� ���ư��ϴ�." << endl;
				user_x -= 1;
			}
			//����� �ʾҴٸ� ���
			else {
				cout << "���������� �̵��մϴ�." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "����") {
			// TODO: ���� �����ֱ� �Լ� ȣ��
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "����") {
			cout << "�����մϴ�.";
			break;
		}
		else {
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}

		// �������� �����ߴ��� üũ
		//finish�� �������� ����, checkGoal �� true �̸� �Ʒ� ���� ���
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

	}
	return 0;
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	for (int i = 0; i < mapY; i++) {
		for (int j = 0; j < mapX; j++) {
			if (i == user_y && j == user_x) {
				cout << " USER |"; // �� �� 1ĭ ����
			}
			else {
				int posState = map[i][j];
				switch (posState) {
				case 0:
					cout << "      |"; // 6ĭ ����
					break;
				case 1:
					cout << "������|";
					break;
				case 2:
					cout << "  ��  |"; // �� �� 2ĭ ����
					break;
				case 3:
					cout << " ���� |"; // �� �� 1ĭ ����
					break;
				case 4:
					cout << "������|";
					break;
				}
			}
		}
		cout << endl;
		cout << " -------------------------------- " << endl;
	}
}

// �̵��Ϸ��� ���� ��ȿ�� ��ǥ���� üũ�ϴ� �Լ�
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	//�Ʒ��� ������ �´ٸ� true ��
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// ������ ��ġ�� ���������� üũ�ϴ� �Լ�
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// ������ �����ϸ� true �� ��ȯ
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}


int user_x = 0;
int user_y = 0;

int now_HP() {
	if (user_x += 1) {
		userHP = userHP - 1;
	}
	else if (user_x -= 1) {
		userHP = userHP - 1;
	}
	else if (user_y += 1) {
		userHP = userHP - 1;
	}
	else if (user_y -= 1) {
		userHP = userHP - 1;
	}
	else
		userHP;
	
return userHP;
}
