#include <iostream>
using namespace std;

int main()
{
	double f_temp;
	double c_temp;

	//Ư�� ���� ����� �Է°��� �� ������ ����
	cout << "�����µ� : ";
	cin >> c_temp;

	//��ȯ�� ���� �� �ۼ�
	f_temp = c_temp / (5.0 / 9.0) + 32;

	cout << "ȭ���µ� = " << f_temp << endl;

	return 0;
}