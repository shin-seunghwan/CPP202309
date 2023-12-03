#include "user.h"

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