#include <iostream>
using namespace std;

int main() {
	// 3-3 판을 위해 상수 선언 및 배열 과 변수 선언
	const int numCell = 3;
	char board[numCell][numCell]{};
	int x, y;

	//반복문을 이용해 판을 빈 칸으로 즉, 초기화 진행
	for (x = 0; x < numCell; x++) {
		for (y = 0; y < numCell; y++) {
			board[x][y] = ' ';
		}
	}

	//누구 차례인지 확인을 위한 변수 선언 및 해당 유저의 돌을 저장하기 위한 변수 선언
	int k = 0;
	char currentUser = 'X';

	//반복문이 반복는 동안 switch 함수를 통해 차례를 구별
	while (true) {
		switch (k % 2) {
		case 0:
			cout << k % 2 + 1 << "번 유저(X)의 차례입니다 -> ";
			currentUser = 'X';
			break;
		case 1:
			cout << k % 2 + 1 << "번 유저(O)의 차례입니다 -> ";
			currentUser = 'O';
			break;
		}
		
		//좌표를 입력 받아 x,y에 저장
		cout << "(x,y) 좌표를 입력하세요:";
		cin >> x >> y;
		
		//돌이 판을 벗어나거나 중복되는 것을 방지
		if (x >= numCell || y >= numCell) {
			cout << x << "," << y << ": ";
			cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
			continue;
		}
		if (board[x][y] != ' ') {
			cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
			continue;
		}

		//입력된 좌표에 표시
		board[x][y] = currentUser;

		//좌표에 표시된 것들을 포함해 판을 출력
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

		//변수를 선언 하고 판의 모든 칸을 반복문으로 통해 지나가며 공백일 때마다 +1을 하고 
		//지나가다 공백이 아닐시 조건문 밖으로 나와 다른 조건문 full==0일 때를 만족하면 모든 칸이 다 찬것으로 판단
		int full = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					full++;
				}
			}
		}
		if (full == 0) {
			cout << "모든 칸이 다 찼습니다. 종료합니다" << endl;
			break;
		}
		// 승자 체크
		bool isWin = false;
		
		//현재 유저의 돌을 놓은 칸이 가로 or 세로가 같을 경우를 찾을 경우
		//현재 유저의 돌을 놓은 칸이 대각으로 같은 경우를 조건문을 통해 찾을 경우
		//위의 두가지 경우를 만족하면 빙고로 어떤 경우에 누가 승리인지 출력한다.
		for (int i = 0; i < numCell; i++) {
			if (board[i][0] == currentUser && board[i][1] == currentUser && board[i][2] == currentUser) {
				cout << "가로에 모두 돌이 놓였습니다!: ";
				isWin = true;
			}
			if (board[0][i] == currentUser && board[1][i] == currentUser && board[2][i] == currentUser) {
				cout << "세로에 모두 돌이 놓였습니다!: ";
				isWin = true;
			}
			if (board[0][0] == currentUser && board[1][1] == currentUser && board[2][2] == currentUser) {
				cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
				isWin = true;
			}
			if (board[0][2] == currentUser && board[1][1] == currentUser && board[2][0] == currentUser) {
				cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!: ";
				isWin = true;
			}
			if (isWin == true) {
				cout << k % 2 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
				cout << "종료합니다" << endl;
				break;
			}
		}
	}
	return 0;
}