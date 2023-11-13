#include <iostream>
using namespace std;

//상수 및 변수 선언
const int NUM_USERS = 3;
const int NUM_ITEMS = 3;
int userPreferences[NUM_USERS][NUM_ITEMS];


//이중 반복문과 2차 배열을 이용해 함수 선언
void initializePreferences(int userPreferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해): ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreferences[i][j];
		}
	}

}

//2차배열 이중 반복문 2중 조건문을 이용해 함수 선언
void  findRecommendedItems(const int userPreferences[NUM_USERS][NUM_ITEMS]) {
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreferenceIndex = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreferences[i][j] > userPreferences[i][maxPreferenceIndex]) {
				maxPreferenceIndex = j;
			}
			if (userPreferences[i][j]) {

			}
		}

		//사용자에게 추천하는 항목을 출력해준다.
		cout << "사용자" << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreferenceIndex + 1) << std::endl;
	}

}

int main() {

	// 함수 출력
	initializePreferences(userPreferences);
	findRecommendedItems(userPreferences);

	return 0;
}