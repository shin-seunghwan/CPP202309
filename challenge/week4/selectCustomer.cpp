#include <iostream>
#include <string>
using namespace std;

int main() {
	const int maxPeople = 3;
	//cout << "총 고객의 수를 입력하라: ";
	//cin >> maxPeople;
	//원래는 입력 받고 그 값을 넣어야 하지만 컴퓨터가 입력 받기 전에 
	//정확한 값을 모른다고 오류 발생하므로 그냥 상수처리 후 진행
	string names[maxPeople];
	int ages[maxPeople];

	for (int i = 0; i < maxPeople; ++i) {
		cout << "사람" << i + 1 << "의 이름: ";
		cin >> names[i];
		cout << "사람" << i + 1 << "의 나이: ";
		cin >> ages[i];
	}// 입력받은 수 만큼 반복하면서 이름과 나이를 입력받는다.

	int ageThreshold;
	cout << "특정 나이 이상인 사람을 찾으려면 나이를 입력하세요: ";
	cin >> ageThreshold;
	// 입력 받고 대입

	cout << ageThreshold << "세 이상인 고객들:\n";
	// 몇세 이상인  고객을 찾는지 입력 받기
	int detectedPeople = 0; // 변수 선언 및 초기화
	for (int i = 0; i < maxPeople; ++i) {
		if (ages[i] >= ageThreshold) {
			cout << names[i] << " (" << ages[i] << "세)\n";
			detectedPeople ++;
		// 입력받은 수 이상이라면 출력, detectedPeope 1 증가
		}
	}//maxPeolple 의 수 만큼 반복하여 진행 = 모든 사람의 나이 확인 진행
	if (detectedPeople == 0) {
		cout << ageThreshold << "이상의 나이를 가진 고객이 없습니다";
	}// 모든 수 만큼 확인 후 detectedPeople 이 0 (이상이 없다면)이면 출력
	return 0;
}