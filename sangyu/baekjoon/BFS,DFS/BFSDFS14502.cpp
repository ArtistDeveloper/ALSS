#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int emptyNum = 0;
int virusNum = 0;
int ans = 0;

int map[10][10];

int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };

vector<pair<int,int>> emptyPos;

//bfs를 통해 얼마나 퍼졌는지 구해야함.
int bfs()
{
	queue<pair<int, int>> q;
	bool vis[8][8] = {};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 2)
			{
				q.push({ i, j });
			}
		}
	}
	int spread = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		spread++;

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (map[nx][ny] != 0 || vis[nx][ny])
				continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	return spread;
}


//벽 3개를 세우기 위한 모든 경우를 찾아야함.
void dfs(int cur,int idx)
{
	//bfs를 통해 순회시 ,퍼진 공간에 대해 알아야하고 , 큰값을 ans에 담아야함.
	//기존 빈칸에 추가적으로 확산되고, 추가적으로 벽을 세운것이기 때문에 빼서 계산함.
	if (cur == 3)
	{
		int spread = bfs();
		ans = max(emptyNum - spread - 3 + virusNum, ans);
		return;
	}

	for (int i = idx; i < emptyPos.size(); i++)
	{
		map[emptyPos[i].first][emptyPos[i].second] = 1;
		dfs(cur + 1, i + 1);
		map[emptyPos[i].first][emptyPos[i].second] = 0;
	}
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 0)
			{
				emptyPos.push_back({ i,j });
				emptyNum++;
			}
			else if (map[i][j] == 2)
			{
				virusNum++;
			}
		}
	}

	dfs(0, 0);
	cout << ans;
}
