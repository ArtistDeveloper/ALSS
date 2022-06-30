// 문제틀린 이유 
// n값이 1이 주어지면 출력형식이 이상함.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	const int FIRST = 0;
	int LAST;
	
	queue<int> josephusQ;

	cin >> n >> k;

	LAST = n-1;

	// 1. queue값 초기화
	for (int i = 0; i < n; i++)
	{
		josephusQ.push(i + 1);
	}

	// 2. 알고리즘 수행
	for (int i = 0; i < n; i++)
	{
		// !! 틀린 이유 : 경계값 반례 체크 제대로 안했음.
		if (n == 1)
		{
			cout << "<1>";
			break;
		}

		// 2.1 K-1의 횟수만큼 dequeue() 및 enqueue()수행
		for (int j = 0; j < k-1; j++)
		{
			josephusQ.push(josephusQ.front());
			josephusQ.pop();
		}

		// 2.2 k-1의 횟수만큼 반복이 끝나면 출력 후 dequeue()만 수행
		if (i == FIRST)
		{
			cout << "<" << josephusQ.front() << ", ";
		}
		else if (i == LAST)
		{
			cout << josephusQ.front() << ">";
		}
		else
		{
			cout << josephusQ.front() << ", ";
		}

		josephusQ.pop();
	}

	return 0;
}