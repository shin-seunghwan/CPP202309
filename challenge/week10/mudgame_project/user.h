#include <iostream>
#include <string>
using namespace std;

class User {
public:
    int hp; // 사용자의 HP

    User() : hp() {} // 기본 생성자
    void DecreaseHP(int dec_hp); // HP 감소
    int GetHP(); // 현재 HP 반환
};