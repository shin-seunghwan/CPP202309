#include <iostream>
using namespace std;

int main()
{
	int vowel = 0;
	int consonant = 0;
	cout << "�����ڸ� �Է��ϰ� ctrl+z�� ġ����." << endl;
	// ���� ���� �� �ʱ�ȭ ���� �� Ư�� ���� ���

	char ch; //����� �Է��� �����ϱ� ���� ���� ����

	//HINT : while + switch �� Ȱ��

	while (cin >> ch) //�Է� ���� ���� ch�� �����Ѵ�
	{
		switch (ch)
		{
		case 'a':
			vowel += 1;
			break;
		case 'e':
			vowel += 1;
			break;
		case 'i':
			vowel += 1;
			break;
		case 'o':
			vowel += 1;
			break;
		case 'u':
			vowel += 1;
			break;
		default:
			consonant += 1;
			break;
		}
	// ���ǽ� ch �� a,e,i,o,u�� ���ٸ� vowel + 1 ���ְ� �� �ܿ��� consonant +1�� ���ش� 
	// �׸��� ����ڰ� ��Ʈ�� z�� ���������� �Է��� �� ��� ���� ó�����ش�
	}

	cout << "����: " << vowel << endl;
	cout << "����: " << consonant << endl;
	// ������ Ƚ���� ������ ���� ����Ѵ�.
	
	return 0;
}