#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> cardQ;
	int n;

	cin >> n;
	
	// 1. 큐 초기화
	for (int i = 0; i < n; i++)
	{
		cardQ.push(i + 1);
	}

	// 2. 로직 수행
	// 반복문의 조건 
	// == 1. while(ture)걸고 while반복문 안에서 cardQ.size()를 사용한 조건으로 반복문 break하기. (while조건 자체에 q.size()를 통한 조건을 걸어도 됨.)
	// == 2. for문 사용: n개의 데이터가 큐에 있고, 한 반복당 하나의 데이터가 pop()되어 사라지니 n-1번 반복하면 데이터가 1개가 남을 것이란 걸 예측할 수 있다.

	for (int i = 0; i < n - 1; i++)
	{
		cardQ.pop();
		cardQ.push(cardQ.front());
		cardQ.pop();
	}

	cout << cardQ.front();

	return 0;
}