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