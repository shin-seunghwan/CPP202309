#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int hp; // ������� HP

public:

    User() : hp(20) {} // �⺻ ������
    void DecreaseHP(int dec_hp); // HP ����
    void IncreaseHP(int inc_hp); // HP ����
    int GetHP(); // ���� HP ��ȯ
    virtual void doAttack(); //���� �Լ� ����
};

//User Ŭ������ ��ӹ޴� ������ Ŭ����
class Magician : public User {
public:

    Magician();
    void doAttack() override;//User Ŭ������ �޼��带 ������
};

//User Ŭ������ ��ӹ޴� ���� Ŭ����
class Warrior : public User {
public:
    Warrior();
    void doAttack() override;//User Ŭ������ �޼��带 ������
};
