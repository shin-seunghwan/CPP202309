#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int numCell = 10;
	int numlist[numCell][numCell];

	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			int elem = rand() % 1000; //1000으로 나눈 나머지, 즉 0 ~ 999를 랜덤으로 생성
			numlist[i][j] = elem;
			cout << i << "," << j << ":" << elem << endl;
		}
	//i를 변수 선언 및 초기화 진행 후 0일 때 j가 0부터 9까지 반복되면서 0,1  0,2 .... 반복 되고 
	//그에 해당하는 numlist 값에 elem 값을 넣어주는 데 elem은 랜덤으로 생성
	//위의 과정을 i가 0부터 9가지 반복
	}
	cout << endl;

	int max = 0;
	int maxI = 0;
	int maxJ = 0;
	// 변수 선언
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			int value = numlist[i][j];
			// 배열 0,0  0,1 .... 이렇게 반복하면서 그에 해당하는 값을 value 값에 넣어준다.
			if (value > max) {
				max = value;
				maxI = i;
				maxJ = j;
			}
			// 그 값을 max 와 비교하여 크면 해당하는 값과 i,j를 위에서 선언한 변수에 대입
		}
		// 위 과정을 0,0 ~ 9,9까지 반복하여 max를 찾는다.
	}

	//안쪽 for 문을 범위기반으로도 생각해보자!

	cout << "가장 큰 값은 " << max << "이고,";
	cout << "i와 j는 각각" << maxI << "," << maxJ << "입니다." << endl;
	cout << "검증 결과 :" << numlist[maxI][maxJ] << endl;
	//해당 변수에 넣어진 값들을 입력된 말들과 함께 출력
	return 0;
}