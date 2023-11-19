#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int hp; // 사용자의 HP

public:

    User() : hp(20) {} // 기본 생성자
    void DecreaseHP(int dec_hp); // HP 감소
    void IncreaseHP(int inc_hp);
    int GetHP(); // 현재 HP 반환
};
