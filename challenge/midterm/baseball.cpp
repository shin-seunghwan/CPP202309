#include <iostream>
#include <string>
using namespace std;


//3�ڸ��̻��̰� �ߺ��̾��� �� ������� BOOL�� �̿��� ó���ϴ� ���� ����� �ذ����� ����

int main() {
    int randomNum; // ����� �ϴ� 3�ڸ����� ���� ���� ����
    int firstNum; // ������ ù��° �ڸ���
    int secondNum; // ������ �ι�° �ڸ���
    int thirdNum; // ������ ����° �ڸ���

    while (1) {
        randomNum = rand() % 900 + 100; // ������ 3�ڸ��� ����

        bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����

        // TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
        firstNum = randomNum / 100; // ���� �ڸ� ����
        secondNum = (randomNum / 10) % 10; // ���� �ڸ� ����
        thirdNum = randomNum % 10; // ���� �ڸ� ����

        // ù��°, �ι�°, ����° �ڸ����� ��� �ٸ��� üũ
        if (firstNum != secondNum && secondNum != thirdNum && firstNum != thirdNum) {
            break;
        }
        else {
            cout << "�Է��� ���ڿ� �ߺ��� ���ڰ� �ֽ��ϴ�. �ٽ� �Է����ּ���." << endl;
        }

        if (same == true) {
            break;
        }
    }

    int turn = 0;
    while (1) {
        cout << turn + 1 << "��° �õ��Դϴ�. " << endl;

        int userNumber; // ����ڰ� �Է��� ���ڸ��� ���� ����
        int guessFirst; // ������ ������ ù��° �ڸ���
        int guessSecond; // ������ ������ �ι�° �ڸ���
        int guessThird; // ������ ������ ����° �ڸ���


        // ����ڿ��� ���ڸ� ���� �Է¹޴� �ڵ� ���
        while (1) {
            cout << "���ڸ� ���� �Է����ּ���: ";
            cin >> userNumber;

            bool same = false; // ��� ���� �ٸ� ��� true�� ���� ����
            // TODO 1: 3�ڸ� ������ �ڸ����� �����ϰ�, ��� ���� �ٸ��� üũ�ϴ� �ڵ��� �ۼ�
            guessFirst = userNumber / 100; // ���� �ڸ� ����
            guessSecond = (userNumber / 10) % 10; // ���� �ڸ� ����
            guessThird = userNumber % 10; // ���� �ڸ� ����

            // ù��°, �ι�°, ����° �ڸ����� ��� �ٸ��� üũ
            if (guessFirst != guessSecond && guessSecond != guessThird && guessFirst != guessThird) {
                break; // ��� ���ڰ� �ٸ��� while ���� Ż��
            }


            if (to_string(userNumber).length() != 3) {
                cout << "�Էµ� ���ڰ� 3�ڸ� ���� �ƴմϴ�. �ٽ� �Է��ϼ���." << endl;
                continue;
            }

            if (same == true) {
                break;
            }
        }


        int strike = 0; // ��Ʈ����ũ ������ �����ϴ� ����
        int ball = 0; // �� ������ �����ϴ� ����

        // TODO 2: ����� ������ ������ �ڸ����� ���ڸ� ���ϸ� ��Ʈ�� �ֱ� ���� �ڵ��� �ۼ�
        if (guessFirst == firstNum) {
            strike++;
        }
        if (guessSecond == secondNum) {
            strike++; 
        }
        if (guessThird == thirdNum) {
            strike++;
        }

        // �� ���: ���ڴ� ������ ��ġ�� �ٸ� ��츸 ī��Ʈ
        if (guessFirst == secondNum || guessFirst == thirdNum) {
            if (guessFirst != firstNum) ball++; // ù ��° ���ڰ� ��Ʈ����ũ�� �ƴϸ� ���� ī��Ʈ
        }
        if (guessSecond == firstNum || guessSecond == thirdNum) {
            if (guessSecond != secondNum) ball++; // �� ��° ���ڰ� ��Ʈ����ũ�� �ƴϸ� ���� ī��Ʈ
        }
        if (guessThird == firstNum || guessThird == secondNum) {
            if (guessThird != thirdNum) ball++; // �� ��° ���ڰ� ��Ʈ����ũ�� �ƴϸ� ���� ī��Ʈ
        }



        cout << userNumber << "�� ��� : " << strike << " ��Ʈ����ũ, " << ball << "�� �Դϴ�." << endl;

        if (strike == 3) {
            cout << "������ ������ϴ�. �����մϴ�.";
            break;
        }

        turn += 1;
    }

    return 0;
}



//�� ������ ���� ������ ���ߴ°� ������ �ڸ��� �ߺ��� 3��