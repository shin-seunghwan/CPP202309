#include <iostream>
using namespace std;

int main()
{
	double f_temp;
	double c_temp;

	//Ư�� ���� ����� �Է°��� �� ������ ����
	cout << "ȭ���µ� : ";
	cin >> f_temp;

	//��ȯ�� ���� �� �ۼ�
	c_temp = (5.0 / 9.0) * (f_temp - 32);

	cout << "�����µ� = " << c_temp << endl;

	return 0;
}