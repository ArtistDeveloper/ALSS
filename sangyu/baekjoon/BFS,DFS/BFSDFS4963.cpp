#include<iostream>
#include<memory.h>
#include<queue>

using namespace std;
int tc,n,m;
int map[51][51];
bool visit[51][51];

int dx[8] = { 1,0,-1,0,-1,-1,1,1 };
int dy[8] = { 0,1,0,-1,-1,1,-1,1 };

void bfs(int x,int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = 1;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = cur.first+dx[i];
			int ny = cur.second+dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (visit[nx][ny] || map[nx][ny] == 0)
				continue;

			visit[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

	return;
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	while (true)
	{
		cin >> m >> n;

		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}

		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (visit[i][j] == 0 && map[i][j] == 1)
				{
					bfs(i, j);
					ans++;
				}
			}
		}
	
		cout << ans<<'\n';
		memset(visit, 0, sizeof(visit));
	}

}