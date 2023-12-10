#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
private:
    int hp; // ������� HP

public:

    User() : hp(20) {} // �⺻ ������
    void DecreaseHP(int dec_hp); // HP ����
    void IncreaseHP(int inc_hp); // HP ����
    int GetHP(); // ���� HP ��ȯ
    virtual void doAttack(); //���� �Լ� ����
};

//User Ŭ������ ��ӹ޴� ������ Ŭ����
class Magician : public User {
public:

    Magician();
    void doAttack() override;//User Ŭ������ �޼��带 ������
};

//User Ŭ������ ��ӹ޴� ���� Ŭ����
class Warrior : public User {
public:
    Warrior();
    void doAttack() override;//User Ŭ������ �޼��带 ������
};

// HP�� ���ҽ�Ű�� ��� �Լ�
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0; // HP�� ������ ���� �ʵ��� ó��
}
void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;

}

// ���� HP�� ��ȯ�ϴ� ��� �Լ�
int User::GetHP() {
    return hp;
}

//���� �Լ�
void User::doAttack() {
    cout << "�����մϴ�" << endl;
}

//Magician Ŭ������ ������ 
Magician::Magician() : User() {}

//Magician Ŭ������ ���� �Լ�
void Magician::doAttack() {
    std::cout << "���� ����" << std::endl;
}

//Warrior Ŭ������ ������
Warrior::Warrior() : User() {}

//Warrior Ŭ������ ���� �Լ�
void Warrior::doAttack() {
    std::cout << "���� ����" << std::endl;
}
const int mapX = 5;
const int mapY = 5;

// ��ȹ�� 3���� �Լ� ����(������� ��ġ üũ �Լ�, ������ ���� ��ġ ��� �Լ�, �������� ���� üũ �Լ�)
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, User& user);
bool CheckUser(User& user);

int main() {
	User my_user;

	// ������� ���� ��ü ����
	Magician magician;
	Warrior warrior;

	ifstream mapFile;
	mapFile.open("map.txt");

	// map.txt ������ ����� ���ȴ��� Ȯ��
	if (!mapFile.is_open()) {
		cerr << "map.txt ������ �� �� �����ϴ�." << endl;
		return 1;
	}

	int map[mapY][mapX];

	// ���Ϸκ��� �� �����͸� �о� �迭�� ����
	for (int i = 0; i < mapY; ++i) {
		for (int j = 0; j < mapX; ++j) {
			if (!(mapFile >> map[i][j])) {
				cerr << "map.txt ���Ͽ��� �����͸� �д� �� ������ �߻��߽��ϴ�." << endl;
				return 1;
			}
		}
	}

	// ���� �ݱ�
	mapFile.close();

	// �� ������ ����Ͽ� Ȯ��
	for (int i = 0; i < mapY; ++i) {
		for (int j = 0; j < mapX; ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	// ������ ��ġ�� ������ ���� ���� �� �ʱ�ȭ
	int user_x = 0; // ���� ��ȣ
	int user_y = 0; // ���� ��ȣ

	// ���� ���� 
	while (1) { // ����ڿ��� ��� �Է¹ޱ� ���� ���� ����

		// ������� �Է��� ������ ���� ����
		string user_input;
		cout << "�������� ���Դϴ�. ��ɾ �Է��ϼ��� (��, ��, ��, ��, ����, ����, ����): ";
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
			magician.doAttack(); // ������ ���� ����
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


		cout << "������ ���Դϴ�. ��ɾ �Է��ϼ��� (��, ��, ��, ��, ����, ����, ����): ";
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
			warrior.doAttack(); // ���� ���� ����
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


		// ������� ��ġ ���� üũ
		checkState(map, user_x, user_y, my_user);



		// �������� �����ߴ��� üũ
		//finish�� �������� ����, checkGoal �� true �̸� �Ʒ� ���� ���
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "�������� �����߽��ϴ�! �����մϴ�!" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}

		// ������� HP üũ
		if (!CheckUser(my_user)) {
			cout << "HP�� 0 ���ϰ� �Ǿ����ϴ�. �����߽��ϴ�. " << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}


		return 0;
	}
}


// ������ ����� ��ġ ����ϴ� �Լ�
void displayMap(int map[][mapX], int user_x, int user_y) {
	try {
		// ����� ��ġ�� �� ������ ������� Ȯ��
		if (user_x < 0 || user_x >= mapX || user_y < 0 || user_y >= mapY) {
			throw out_of_range("����� ��ġ�� �� ������ ������ϴ�.");
		}

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
		}
		cout << " -------------------------------- " << endl;
	}
	// �߰����� ���� ó�� ����
	catch (const out_of_range& e) {
		cerr << "���� �߻�: " << e.what() << endl;
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

// 0�� �� ����, 1�� ������, 2�� ��, 3�� ����, 4�� ������
void checkState(int map[][mapX], int user_x, int user_y, User& my_user) {

	switch (map[user_y][user_x]) {
	case 1:
		cout << "�������� �ֽ��ϴ�" << endl;
		break;
	case 2:
		cout << "���� �ֽ��ϴ�. HP�� 2 �پ��ϴ�." << endl;
		my_user.DecreaseHP(2);
		break;
	case 3:
		cout << "������ �ֽ��ϴ�. HP�� 2 �þ�ϴ�." << endl;
		my_user.IncreaseHP(2);
		break;
	}
}

bool CheckUser(User& user) {
	return user.GetHP() > 0;
}
