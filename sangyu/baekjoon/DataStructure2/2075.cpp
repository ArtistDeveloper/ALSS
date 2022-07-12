#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int main()
{
	
	//�޸��ʰ� -> ū�͸� pq�� �ִ´�? 
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	int num;

	for (int i = 0; i < n * n; i++)
	{
		cin >> num;
		

		if (pq.size() < n)
		{
			pq.push(num);
		}
		else
		{
			if (num > pq.top())
			{
				pq.pop();
				pq.push(num);
			}
		}
	}
	cout << pq.top() << '\n';
}