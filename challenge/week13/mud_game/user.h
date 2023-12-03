#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int hp; // 사용자의 HP

public:

    User() : hp(20) {} // 기본 생성자
    void DecreaseHP(int dec_hp); // HP 감소
    void IncreaseHP(int inc_hp); // HP 증가
    int GetHP(); // 현재 HP 반환
    virtual void doAttack(); //가상 함수 생성
};

//User 클래스를 상속받는 마법사 클래스
class Magician : public User {
public:

    Magician();
    void doAttack() override;//User 클래스의 메서드를 재정의
};

//User 클래스를 상속받는 전사 클래스
class Warrior : public User {
public:
    Warrior();
    void doAttack() override;//User 클래스의 메서드를 재정의
};
