#include <iostream>
using namespace std;

int main() {
	//상수 선언, 배열 선언
	const int NUM_USERS = 3;
	const int NUM_ITEMS = 3;
	int userPreferences[NUM_USERS][NUM_ITEMS];

	//반복문을 통해 선호도를 입력 받고 2차원 배열에 값을 넣어놓는다.
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해): ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
		}
	}

	//두 반복문을 통해 사용자 별로 반복을 하며 선호도가 가장 높을 값을 조건문을 통해 찾는다
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
		}
		
		//사용자에게 추천하는 항목을 출력해준다.
		cout << "사용자" << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << std::endl;
	}

	return 0;
}