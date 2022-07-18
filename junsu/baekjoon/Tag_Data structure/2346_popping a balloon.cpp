#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<pair<int,int>> dq; // first: ǳ���� ����, second: ������ ����
	int n, message_num; 
	bool isInverse = false;

	cin >> n;
	
	// 1. �� �ֱ�
	for (int balloon_num = 1; balloon_num < n + 1; balloon_num++)
	{
		cin >> message_num;
		dq.push_back(pair<int, int>(balloon_num, message_num));
	}
	
	// 2. ���� ����
	// ���� ����:
	// # 1. ������ �� �� pop_front()
	// # 2. �������� -1 Ƚ����ŭ �̵�(���)
	// # 2.1 �������� Ƚ����ŭ �̵�(����)
	// # 1�� 2�� �ݺ��Ѵ�.
	for (int i = 0; i < n; i++)
	{
		message_num = dq.front().second;
		cout << dq.front().first << ' ';

		dq.pop_front();

		// ������ ���� ���� �ϳ��� ����ϸ� break
		if (dq.empty())
			break;

		if (message_num < 0) // ������ ���ڰ� ������ ��
		{
			message_num = -message_num;	

			for (int j = 0; j < message_num; j++) // ������ ���ڰ� ������ ���� ���� front�� ������ ���� ������ ����ŭ �ݺ��ؾ� �Ѵ�.
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}			
		}
		else if (message_num > 0) // ������ ���ڰ� ����� ��
		{
			for (int j = 0; j < message_num - 1; j++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
	}

	return 0;
}