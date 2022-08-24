#include<iostream>
#include<queue>

using namespace std;

int dist[100001];

int main()
{
	int n, k;
	cin >> n >> k;


	//�����غ��̴� visit�� ���ְ� -1�� , !-1�� ���� �湮����Ȯ��
	fill(dist, dist + 100001, -1);
	//ù�湮
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