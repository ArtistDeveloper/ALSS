#include<iostream>
#include<queue>

using namespace std;

int n, m;
int map[101][101];
bool vis[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	int ans = 0;
	while (true)
	{
		ans++;

		//가장자리에는 치즈가 놓여있지 않을것.
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		vis[0][0] = true;


		//0인부분을 bfs를 통해 찾습니다.
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int ny = dy[dir] + cur.first;
				int nx = dx[dir] + cur.second;

				if (nx < 0 || ny < 0 || nx >= m || ny >= n)
					continue;
				if (vis[ny][nx])
					continue;
				if (map[ny][nx] > 0)
				{
					map[ny][nx]++;
					continue;
				}

				vis[ny][nx] = true;
				q.push({ ny,nx });

			}
		}

		//종료하기 위해 체크합니다, 2변과 닿은 치즈를 지웁니다, 초기화합니다.
		bool endCheck = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				vis[i][j] = false;

				if (map[i][j] >= 3)
					map[i][j] = 0;
				if (map[i][j] == 2)
					map[i][j] = 1;
				if (map[i][j] == 1)
					endCheck = false;

			}
		}


		if (endCheck == true)
			break;
	}

	cout << ans;
}