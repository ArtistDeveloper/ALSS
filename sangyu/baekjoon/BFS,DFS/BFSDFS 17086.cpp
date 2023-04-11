#include<iostream>
#include<queue>
using namespace std;

int n, m, ans;
int map[51][51];
queue<pair<int, int>> q;
bool vist[51][51];

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
void bfs()
{
	while (!q.empty())
	{
		
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (ny < 0 || nx < 0 || nx >= n || ny >= m)
				continue;
			if (map[nx][ny]==0)
			{
				q.push({ nx,ny });
				map[nx][ny] = map[cur.first][cur.second]+1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
			{
				q.push({ i,j });
			}
		}
	}

	bfs();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] > ans)
				ans = map[i][j];
		}
	}

	cout << ans-1;
}