#include<iostream>
#include<queue>
using namespace std;

int n, m, t = 0;
int map[101][101];
bool vist[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	

	while (true)
	{
		t++;
		int cnt = 0;
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		vist[0][0] = 1;

		//0,0에서 탐색을 하여 공기와 접촉된 부분을 구합니다.
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
				if (vist[nx][ny])
					continue;
				if (map[nx][ny] == 1)
				{
					vist[nx][ny] = 1;
					map[nx][ny] = 0;
					cnt++;
					continue;
				}

				q.push({ nx,ny });
				vist[nx][ny] = 1;
			}
		}

		bool check = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1)
				{
					check = true;
				}
			}
		}

		if (!check)
		{
			cout << t << '\n' << cnt << '\n';
			break;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				vist[i][j] = false;
			}
		}
	}
}