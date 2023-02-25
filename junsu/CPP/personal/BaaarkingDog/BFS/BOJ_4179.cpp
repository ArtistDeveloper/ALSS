#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

char maze[1002][1002];
int jdist[1002][1002];
int fdist[1002][1002];
int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

int main()
{
	int r, c;
	queue<pair<int, int>> jq;
	queue<pair<int, int>> fq;

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		fill(jdist[i], jdist[i] + c, -1);
		fill(fdist[i], fdist[i] + c, -1);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'J')
			{
				jq.push({ i, j });
				jdist[i][j] = 0;
			}
			if (maze[i][j] == 'F')
			{
				fq.push({ i, j });
				fdist[i][j] = 0;
			}
		}
	}

	while (!fq.empty())
	{
		 auto curPos = fq.front(); fq.pop();

		 for (int dir = 0; dir < 4; dir++)
		 {
			 int nx = curPos.X + dx[dir];
			 int ny = curPos.Y + dy[dir];

			 if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
			 if (fdist[nx][ny] >= 0 || fdist[nx][ny] != -1) continue;
			 if (maze[nx][ny] == '#') continue;
			 fq.push({nx, ny});
			 fdist[nx][ny] = fdist[curPos.X][curPos.Y] + 1;
		 }
	}

	while (!jq.empty())
	{
		auto curPos = jq.front(); jq.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curPos.X + dx[dir];
			int ny = curPos.Y + dy[dir];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			{
				cout << jdist[curPos.X][curPos.Y] + 1;
				return 0;
			}
			if (jdist[nx][ny] >= 0 || maze[nx][ny] == '#') continue;
			if (fdist[nx][ny] != -1 && fdist[nx][ny] <= jdist[curPos.X][curPos.Y] + 1) continue;
			jdist[nx][ny] = jdist[curPos.X][curPos.Y] + 1;
			jq.push({ nx, ny });
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}
