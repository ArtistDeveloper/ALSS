#include<iostream>
#include<queue>

using namespace std;

#define x first
#define y second
int board[502][502] =
{ {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };

bool visit[502][502] = { 0 };


int main()
{
	int n = 7, m = 10;

	//상하좌우 방향
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };

	 
	queue<pair<int, int>> q;
	pair<int, int> cur;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visit[i][j]  || board[i][j] == 0)
				continue;
			q.push({ 0,0 });
			visit[i][j] = 1;

			while (!q.empty())
			{
				cur = q.front();
				q.pop();

				cout << cur.x << ' ' << cur.y << '\n';

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					
					if (nx < 0 || nx > n || ny <0 || ny >m)
						continue;
					if (visit[nx][ny] || board[nx][ny] != 1) continue;

					visit[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}

		}
	}
}