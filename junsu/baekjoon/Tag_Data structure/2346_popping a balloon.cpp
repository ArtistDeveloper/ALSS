#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<pair<int,int>> dq; // first: 풍선의 순서, second: 쪽지의 숫자
	int n, message_num; 
	bool isInverse = false;

	cin >> n;
	
	// 1. 값 넣기
	for (int balloon_num = 1; balloon_num < n + 1; balloon_num++)
	{
		cin >> message_num;
		dq.push_back(pair<int, int>(balloon_num, message_num));
	}
	
	// 2. 로직 수행
	// 로직 설명:
	// # 1. 쪽지값 뺀 후 pop_front()
	// # 2. 쪽지값의 -1 횟수만큼 이동(양수)
	// # 2.1 쪽지값의 횟수만큼 이동(음수)
	// # 1과 2를 반복한다.
	for (int i = 0; i < n; i++)
	{
		message_num = dq.front().second;
		cout << dq.front().first << ' ';

		dq.pop_front();

		// 마지막 남은 숫자 하나를 출력하면 break
		if (dq.empty())
			break;

		if (message_num < 0) // 쪽지의 숫자가 음수일 때
		{
			message_num = -message_num;	

			for (int j = 0; j < message_num; j++) // 쪽지의 숫자가 음수일 때는 값을 front로 보내기 위해 쪽지의 수만큼 반복해야 한다.
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}			
		}
		else if (message_num > 0) // 쪽지의 숫자가 양수일 때
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