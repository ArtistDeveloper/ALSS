#include<iostream>
#include<queue>
using namespace std;

int arr[100005];

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n, k;

	cin >> n >> k;

	for (int i = 0; i <= 100000; i++)
	{
		arr[i] = 100001;
	}

	queue<int> q;
	int cnt = 0;
	int ans = 100001;
	q.push(n);
	arr[n] = 0;
	
	while (!q.empty())
	{
		
		int cur = q.front();
		q.pop();

		if (cur == k)
		{
			ans = arr[cur];
			break;
		}
		
		if (cur * 2 < 100001 && arr[cur * 2] > arr[cur])
		{
			arr[cur * 2] = arr[cur];
			q.push(cur * 2);
		}
		if (cur + 1 < 100001 && arr[cur + 1] > arr[cur] + 1)
		{
			arr[cur + 1] = arr[cur]+1;
			q.push(cur + 1);
		}
		if (cur -1 >= 0 && arr[cur - 1] > arr[cur] + 1)
		{
			arr[cur - 1] = arr[cur]+1;
			q.push(cur - 1);
		}
	}

	cout << ans;

	return 0;
}