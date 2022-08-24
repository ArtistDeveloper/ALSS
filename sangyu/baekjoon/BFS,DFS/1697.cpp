#include<iostream>
#include<queue>

using namespace std;

int dist[100001];

int main()
{
	int n, k;
	cin >> n >> k;


	//간단해보이니 visit을 없애고 -1을 , !-1을 통해 방문여부확인
	fill(dist, dist + 100001, -1);
	//첫방문
	dist[n] = 0;
	
	queue<int> q;
	q.push(n);

	//bfs
	while (dist[k]==-1)
	{
		int cur = q.front();
		q.pop();

		for (int i : {cur - 1, cur + 1, cur * 2})
		{
			if (i < 0 || i>100000)
				continue;
			if (dist[i] != -1)
				continue;

			dist[i] = dist[cur] + 1;
			q.push(i);
		}

	}
	
	cout << dist[k];
}