#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main()
{
	//����, ����
	//���� -> �켱���� ����� or ���� �� 
	//������ ��ü�� �켱������ �Ҷ� ������ �־��� .
	//������ �ִ�, �ּڰ����
	//I n -> n ����. D 1 �ִ� ���� D -1 �ּڰ� ����
	//�ִ�,�ּڰ��� �� �̻� - �ϳ��� ���� 
	
	int test_case;

	cin >> test_case;
	
	int operate_case;
	char op;
	int num;
	map<int, int> mp;
	map<int, int>::iterator iter;
	for (int i = 0; i < test_case; i++)
	{
		string empty_check;
		cin >> operate_case;
		for (int j = 0; j < operate_case; j++)
		{
			cin >> op;

			if (op == 'I')
			{
				cin >> num;
			}

			else if (op == 'D')
			{
				int D_op;
				cin >> D_op;
				if (!mp.empty())
				{
					if (D_op == 1)
					{
						
					}
					else if (D_op == -1)
					{
						
					}
				}
				else if(mp.empty())
				{
					empty_check = "EMPTY";
					continue;
				}
			}
		}
		if (!empty_check.empty())
		{
			cout << empty_check;
		}
		else
		{
		}
	}
}