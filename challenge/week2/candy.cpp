#include <iostream>
using namespace std;

int main()
{
	int money;
	int candy_price;

	//Ư�� ���� ����� �Է°��� �� ������ ����
	cout << "���� ������ �մ� ��: ";
	cin >> money;
	cout << "ĵ���� ����: ";
	cin >> candy_price;

	//�������� �̿��� ���� ī��Ʈ
	int n_candies = money / candy_price;
	cout << "�ִ�� �� �� �ִ� ĵ���� ����= " << n_candies << endl;

	//%�� �̿��� ������ ������ ���� ���
	int change = money % candy_price;
	cout << "ĵ�� ���� �� ���� ��= " << change << endl;
	return 0;
}