// 모든 시작점에서 BFS하여 최소거리 구하기

#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second

using namespace std;

int tomatos[1002][1002];
int dist[1002][1002];
int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};
int m, n; // m:가로, n:세로

int main()
{
	queue<pair<int, int>> q;
	bool isAllMaturation = true;
	cin >> m >> n;

	// 1. 값 입력 및 익은 것은 queue에 넣기.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tomatos[i][j];
			if (tomatos[i][j] == 1) q.push({ i, j });
			if (tomatos[i][j] == 0) dist[i][j] = -1;
		}
	}

	while (!q.empty())
	{
		auto curPos = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = dx[dir] + curPos.X;
			int ny = dy[dir] + curPos.Y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[curPos.X][curPos.Y] + 1;
			q.push({ nx, ny });
		}
	}

	// 배열 중 -1이 남아있는 곳이 있다면 -1을 출력.(토마토가 모두 익지 못한 상황)
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dist[i][j] == -1)
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	
	cout << ans;

	return 0;
}
