#include <iostream>
using namespace std;

int main()
{
	const int NUM_USERS = 3;
	const int NUM_ITEMS = 3;
	int userPreference[NUM_USERS][NUM_ITEMS];

	//입력을 받아서 2차원 배열 채우기
	for (int i = 0; i < NUM_USERS; ++i) {
		cout << "사용자" << (i + 1) << "의 선호도를 입력하세요 (";
		cout << NUM_ITEMS << "개의 항목에 대해): ";
		for (int j = 0; j < NUM_ITEMS; ++j) {
			cin >> userPreference[i][j];
		}
	}

	//각 사용자에 대해서 추천하는 항목 찾기
	for (int i = 0; i < NUM_USERS; ++i) {
		int maxPreference = 0;
		for (int j = 1; j < NUM_ITEMS; ++j) {
			if (userPreference[i][j] > userPreference[i][maxPreference]) {
				maxPreference = j;
			}
		}


		//사용자에게 추천하는 항목을 출력한다.
		cout << "사용자" << (i + 1) << "에게 추천하는 항목: ";
		cout << (maxPreference + 1) << std::endl;
	}
	return 0;
}