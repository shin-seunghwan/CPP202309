#include <iostream>
#include <string>
using namespace std;

class User {
private:
    int hp; // ������� HP

public:

    User() : hp(20) {} // �⺻ ������
    void DecreaseHP(int dec_hp); // HP ����
    void IncreaseHP(int inc_hp);
    int GetHP(); // ���� HP ��ȯ
};
