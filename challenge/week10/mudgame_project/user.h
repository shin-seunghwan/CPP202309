#include <iostream>
#include <string>
using namespace std;

class User {
public:
    int hp; // ������� HP

    User() : hp() {} // �⺻ ������
    void DecreaseHP(int dec_hp); // HP ����
    int GetHP(); // ���� HP ��ȯ
};