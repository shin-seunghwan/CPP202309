#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	int i;
	int ans;
	cout << "��� ������ �ڵ����� �����մϴ�. " << endl;
	for (int i = 0; i < 5; i++) 
	{
		while (true)
		{
			int firstNum = rand() % 100;
			int secondNum = rand() % 100;

			//hint : ������� > �� �Է� �ޱ� > �򰡰�
			cout << firstNum << "+" << secondNum << "=";
			cin >> ans; //�Է°� ����

			if (firstNum + secondNum == ans)
			{
				cout << "�¾ҽ��ϴ�." << endl;
				break;
			}
			else {
				cout << "Ʋ�Ƚ��ϴ�." << endl;
			}
			// ���� ���� �Է°��� ��ġ�ϸ� �¾ҽ��ϴ�, ��ġ��¡������ Ʋ�Ƚ��ϴ�.

		}
	}
	return 0;
}