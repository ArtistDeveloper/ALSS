#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int l, r, c;

int sz, sx, sy;
int gz, gx, gy;
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	while (true)
	{
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0)
			break;

		char map[31][31][31];
		int dist[31][31][31];
		queue<tuple<int, int, int>> q;
		bool isEscape = false;

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					dist[i][j][k] = -1;
				}
			}
		}

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S')
					{
						dist[i][j][k] = 0;
						q.push({ i,j,k });
					}
				}
			}
		}



		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			int curz, curx, cury;
			tie(curz, curx, cury) = cur;


			for (int i = 0; i < 6; i++)
			{
				int nz = curz + dz[i];
				int nx = curx + dx[i];
				int ny = cury + dy[i];

				if (nz < 0 || nx < 0 || ny < 0 || nz >= l || nx >= r || ny >= c)
					continue;
				if (dist[nz][nx][ny] > 0 || map[nz][nx][ny] == '#')
					continue;

				dist[nz][nx][ny] = dist[curz][curx][cury] + 1;

				if (map[nz][nx][ny] == 'E')
				{
					cout << "Escaped in " << dist[nz][nx][ny] << " minute(s)." << '\n';
					isEscape = true;
					break;
				}

				q.push({ nz,nx,ny });
			}
		}
		while (!q.empty())
			q.pop();

		if (!isEscape)
			cout << "Trapped!" << '\n';
	}
}