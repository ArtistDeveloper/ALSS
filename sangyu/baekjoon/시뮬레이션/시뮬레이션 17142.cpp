#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int n, m;
int map[51][51];
int dist[51][51];
vector<pair<int,int>> v;
vector<pair<int, int>> selectedV;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[11];
int ans = 987654321;
void backtrack(int idx, int cnt)
{
	//m개를 정했다면 bfs를 수행합니다.
	if (cnt == m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dist[i][j] = -1;
			}
		}

		queue<pair<int, int>> q;
		for (int i = 0; i < selectedV.size(); i++)
		{
			q.push({ selectedV[i]});
			dist[selectedV[i].first][selectedV[i].second] = 0;
		}

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;
				if (map[nx][ny] == 1 || dist[nx][ny] >= 0)
					continue;
				
				q.push({ nx,ny });
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
			}
		}

		//0.25초라 좀더 효율적으로 구해야할거같은데.
		int t = 0;
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) 
			{
				//방문하지 않은곳이 있다면
				if (map[i][j] == 0) 
				{
					if (dist[i][j] == -1) 
					{
						flag = false;
						break;
					}

					//방문했다면
					else
						t = max(t, dist[i][j]);
				}
			}
		}
		if (flag)
			ans = min(ans, t);
	}

	for (int i = idx; i < v.size(); i++)
	{
		if (vis[i])
			continue;

		vis[i] = true;
		selectedV.push_back({ v[i].first,v[i].second });
		backtrack(i, cnt + 1);
		selectedV.pop_back();
		vis[i] = false;
	}
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				v.push_back({ i,j });
			}
		}
	}

	backtrack(0, 0);

	if (ans == 987654321)
		cout << "-1";
	else
		cout << ans;
}
