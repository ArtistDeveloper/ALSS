#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int n, l, r, ans;
int map[51][51];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[51][51];

int main()
{
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	bool b = true;
	vector<pair<int, int>> pos;
	int sum = 0;

	while (b)
	{
		b = false;


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				queue<pair<int, int>> q;

				//방문여부를 확인하고 bfs를 수행합니다.
				if (!vis[i][j])
				{
					q.push({ i,j });
					pos.clear();
					pos.push_back({ i,j });
					sum = map[i][j];

					vis[i][j] = true;
					while (!q.empty())
					{
						auto cur = q.front();
						
						q.pop();

						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];

							if (nx >= n || ny >= n || nx < 0 || ny < 0)
								continue;
							if (vis[nx][ny])
								continue;
							if (abs(map[cur.first][cur.second] - map[nx][ny]) >= l && abs(map[cur.first][cur.second] - map[nx][ny]) <= r)
							{
								vis[nx][ny] = true;
								q.push({ nx,ny });
								sum += map[nx][ny];
								pos.push_back({ nx,ny });
							}
						}
					}
				}

				//연합이 있었다면 갱신합니다.
				if (pos.size() >= 2)
				{
					b = true;
					for (auto p : pos)
					{
						map[p.first][p.second] = sum / pos.size();
					}
				}
			}
		}
		
		//초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				vis[i][j] = false;
			}
		}
		
		if (b)
			ans++;

	}

	cout << ans;
}