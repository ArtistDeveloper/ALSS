// BFS의 특성상 모든 구역을 다 훝으면서 가는 것이라 목적지의 값을 출력했을 때는 가장 먼저 도착한 경로가 나오게되고,
// 이것이 즉 최소거리가 되어 최소거리가 출력되는 것은 자명하다.

#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

string board[102];
int vis[102][102];
int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

int main()
{
	pair<int, int> startPoint = { 1, 1 };
	int n, m, boardNum, minimum = 0;
	queue<pair<int, int>> q;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	for (int i = 0; i < n; i++)
	{
		fill(vis[i], vis[i] + m, -1);
	}

	q.push({ 0, 0 });
	vis[0][0] = 0;

	while (!q.empty())
	{
		pair<int, int> curPos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curPos.X + dx[i];
			int ny = curPos.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] >= 0 || board[nx][ny] != '1') continue;
			q.push({ nx, ny });
			vis[nx][ny] = vis[curPos.X][curPos.Y] + 1;
		}
	}

	cout << vis[n - 1][m - 1] + 1;

	return 0;
}
