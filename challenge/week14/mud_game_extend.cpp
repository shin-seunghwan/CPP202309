#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
private:
    int hp; // 사용자의 HP

public:

    User() : hp(20) {} // 기본 생성자
    void DecreaseHP(int dec_hp); // HP 감소
    void IncreaseHP(int inc_hp); // HP 증가
    int GetHP(); // 현재 HP 반환
    virtual void doAttack(); //가상 함수 생성
};

//User 클래스를 상속받는 마법사 클래스
class Magician : public User {
public:

    Magician();
    void doAttack() override;//User 클래스의 메서드를 재정의
};

//User 클래스를 상속받는 전사 클래스
class Warrior : public User {
public:
    Warrior();
    void doAttack() override;//User 클래스의 메서드를 재정의
};

// HP를 감소시키는 멤버 함수
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0; // HP가 음수가 되지 않도록 처리
}
void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;

}

// 현재 HP를 반환하는 멤버 함수
int User::GetHP() {
    return hp;
}

//공격 함수
void User::doAttack() {
    cout << "공격합니다" << endl;
}

//Magician 클래스의 생성자 
Magician::Magician() : User() {}

//Magician 클래스의 공격 함수
void Magician::doAttack() {
    std::cout << "마법 공격" << std::endl;
}

//Warrior 클래스의 생성자
Warrior::Warrior() : User() {}

//Warrior 클래스의 공격 함수
void Warrior::doAttack() {
    std::cout << "무기 공격" << std::endl;
}
const int mapX = 5;
const int mapY = 5;

// 계획한 3개의 함수 선언(사용자의 위치 체크 함수, 지도와 현재 위치 출력 함수, 목적지에 도착 체크 함수)
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, User& user);
bool CheckUser(User& user);

int main() {
	User my_user;

	// 마법사와 전사 객체 생성
	Magician magician;
	Warrior warrior;

	ifstream mapFile;
	mapFile.open("map.txt");

	// map.txt 파일이 제대로 열렸는지 확인
	if (!mapFile.is_open()) {
		cerr << "map.txt 파일을 열 수 없습니다." << endl;
		return 1;
	}

	int map[mapY][mapX];

	// 파일로부터 맵 데이터를 읽어 배열에 저장
	for (int i = 0; i < mapY; ++i) {
		for (int j = 0; j < mapX; ++j) {
			if (!(mapFile >> map[i][j])) {
				cerr << "map.txt 파일에서 데이터를 읽는 중 오류가 발생했습니다." << endl;
				return 1;
			}
		}
	}

	// 파일 닫기
	mapFile.close();

	// 맵 데이터 출력하여 확인
	for (int i = 0; i < mapY; ++i) {
		for (int j = 0; j < mapX; ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	// 유저의 위치를 저장할 변수 선언 및 초기화
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 게임 시작 
	while (1) { // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수 선언
		string user_input;
		cout << "마법사의 턴입니다. 명령어를 입력하세요 (상, 하, 좌, 우, 공격, 지도, 종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			//위로 한칸 올라간 것이 벗어났는지 아닌지 체크
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;
			}
			//벗어나지 않았다면 출력
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1;
			//아래로 한 칸 내려간 것이 벗어났는지 아닌지 체크하고 벗어났다면 출력
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
			}
			//벗어나지 않았다면 출력
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			//왼쪽으로 한칸 간 것이 벗어났는지 아닌지 체크하고 벗어났다면 출력
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
			}
			//벗어나지 않았다면 출력
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			//오른쪽으로 한칸 간 것이 벗어났는지 아닌지 체크하고 벗어났다면 출력
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
			}
			//벗어나지 않았다면 출력
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "공격") {
			magician.doAttack(); // 마법사 공격 실행
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}


		cout << "전사의 턴입니다. 명령어를 입력하세요 (상, 하, 좌, 우, 공격, 지도, 종료): ";
		cin >> user_input;

		if (user_input == "상") {
			// 위로 한 칸 올라가기
			user_y -= 1;
			//위로 한칸 올라간 것이 벗어났는지 아닌지 체크
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;
			}
			//벗어나지 않았다면 출력
			else {
				cout << "위로 한 칸 올라갑니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "하") {
			// TODO: 아래로 한 칸 내려가기
			user_y += 1;
			//아래로 한 칸 내려간 것이 벗어났는지 아닌지 체크하고 벗어났다면 출력
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
			}
			//벗어나지 않았다면 출력
			else {
				cout << "아래로 한 칸 내려갑니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "좌") {
			// TODO: 왼쪽으로 이동하기
			user_x -= 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			//왼쪽으로 한칸 간 것이 벗어났는지 아닌지 체크하고 벗어났다면 출력
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
			}
			//벗어나지 않았다면 출력
			else {
				cout << "왼쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "우") {
			// TODO: 오른쪽으로 이동하기
			user_x += 1;
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			//오른쪽으로 한칸 간 것이 벗어났는지 아닌지 체크하고 벗어났다면 출력
			if (inMap == false) {
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
			}
			//벗어나지 않았다면 출력
			else {
				cout << "오른쪽으로 이동합니다." << endl;
				displayMap(map, user_x, user_y);
			}
		}
		else if (user_input == "공격") {
			warrior.doAttack(); // 전사 공격 실행
		}
		else if (user_input == "지도") {
			// TODO: 지도 보여주기 함수 호출
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료") {
			cout << "종료합니다.";
			break;
		}
		else {
			cout << "잘못된 입력입니다." << endl;
			continue;
		}


		// 사용자의 위치 정보 체크
		checkState(map, user_x, user_y, my_user);



		// 목적지에 도달했는지 체크
		//finish를 논리형으로 선언, checkGoal 가 true 이면 아랫 문장 출력
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true) {
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}

		// 사용자의 HP 체크
		if (!CheckUser(my_user)) {
			cout << "HP가 0 이하가 되었습니다. 실패했습니다. " << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}


		return 0;
	}
}


// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
	try {
		// 사용자 위치가 맵 범위를 벗어나는지 확인
		if (user_x < 0 || user_x >= mapX || user_y < 0 || user_y >= mapY) {
			throw out_of_range("사용자 위치가 맵 범위를 벗어났습니다.");
		}

		for (int i = 0; i < mapY; i++) {
			for (int j = 0; j < mapX; j++) {
				if (i == user_y && j == user_x) {
					cout << " USER |"; // 양 옆 1칸 공백
				}
				else {
					int posState = map[i][j];
					switch (posState) {
					case 0:
						cout << "      |"; // 6칸 공백
						break;
					case 1:
						cout << "아이템|";
						break;
					case 2:
						cout << "  적  |"; // 양 옆 2칸 공백
						break;
					case 3:
						cout << " 포션 |"; // 양 옆 1칸 공백
						break;
					case 4:
						cout << "목적지|";
						break;
					}
				}
			}
			cout << endl;
		}
		cout << " -------------------------------- " << endl;
	}
	// 추가적인 오류 처리 로직
	catch (const out_of_range& e) {
		cerr << "예외 발생: " << e.what() << endl;
	}
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY) {
	bool checkFlag = false;
	//아래의 조건이 맞다면 true 값
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
	// 목적지 도착하면 true 값 반환
	if (map[user_y][user_x] == 4) {
		return true;
	}
	return false;
}

// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
void checkState(int map[][mapX], int user_x, int user_y, User& my_user) {

	switch (map[user_y][user_x]) {
	case 1:
		cout << "아이템이 있습니다" << endl;
		break;
	case 2:
		cout << "적이 있습니다. HP가 2 줄어듭니다." << endl;
		my_user.DecreaseHP(2);
		break;
	case 3:
		cout << "포션이 있습니다. HP가 2 늘어납니다." << endl;
		my_user.IncreaseHP(2);
		break;
	}
}

bool CheckUser(User& user) {
	return user.GetHP() > 0;
}
