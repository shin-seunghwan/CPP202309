#include <iostream>
using namespace std;

int main()
{
	int a, b, c, smallest;
	//���� ����

	cout << "3���� ������ �Է��Ͻÿ�: ";
	//Ư�� ������ ����Ͽ� �Է��� �޴´�
	cin >> a >> b >> c;
	//�Է¹��� ���� ������ �ִ´�

	if (a < b && a < c) //a�� b���� �۰� a�� c���� ������?
		smallest = a;  // ���ǹ� 1�� �ش��ϸ� a�� smallest
	else if (b < a && b < c) //b�� a���� �۰� b�� c���� ������?
		smallest = b; // ���ǹ� 2�� �ش��ϸ� b�� smallest
	else
		smallest = c; // ���ǹ� 1,2�� �ش����� ������ c�� smallest

	cout << "���� ���� ������" << smallest << endl;
	// ����ϱ�
	return 0;
}