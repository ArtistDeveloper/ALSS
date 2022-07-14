#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main()
{
	//삽입, 삭제
	//삭제 -> 우선순위 가장높 or 가장 낮 
	//정수값 자체를 우선순위라 할때 연산이 주어짐 .
	//최종적 최댓값, 최솟값출력
	//I n -> n 삽입. D 1 최댓값 삭제 D -1 최솟값 삭제
	//최댓값,최솟값이 둘 이상 - 하나만 삭제 
	
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