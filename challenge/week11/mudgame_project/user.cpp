#include "user.h"

// HP�� ���ҽ�Ű�� ��� �Լ�
void User::DecreaseHP(int dec_hp) {
    hp -= dec_hp;
    if (hp < 0) hp = 0; // HP�� ������ ���� �ʵ��� ó��
}
void User::IncreaseHP(int inc_hp) {
    hp += inc_hp;
    
}

// ���� HP�� ��ȯ�ϴ� ��� �Լ�
int User::GetHP() {
    return hp;
}