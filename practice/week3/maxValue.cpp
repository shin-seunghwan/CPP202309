#include <iostream>
using namespace std;

int main()
{
	int a, b, c, largest;
	//���� ����

	cout << "3���� ������ �Է��Ͻÿ�: ";
	//Ư�� ������ ����Ͽ� �Է��� �޴´�
	cin >> a >> b >> c;
	//�Է¹��� ���� ������ �ִ´�

	if (a > b && a > c) //a�� b���� ũ�� a�� c���� ū��?
		largest = a;  // ���ǹ� 1�� �ش��ϸ� a�� largest
	else if (b > a && b > c) //b�� a���� ũ�� b�� c���� ū��?
		largest = b; // ���ǹ� 2�� �ش��ϸ� b�� largest
	else
		largest = c; // ���ǹ� 1,2�� �ش����� ������ c�� largest
	
	cout << "���� ū ������" << largest << endl;
	// ����ϱ�
	return 0;
}