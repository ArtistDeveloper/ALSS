#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, ans= 987654321;
int map[51][51];
int dist[51][51];
int vist[11];
vector<pair<int,int>> v;
vector<pair<int, int>> selected;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void backtrack(int idx,int cnt)
{
	//3개를 선택했다면 바이러스의 퍼짐 수행 후, 최저시간을 구한다.
	if (cnt == m)
	{
		//초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dist[i][j] = -1;
			}
		}

		queue<pair<int, int>> q;
		
		for (int i = 0; i < selected.size(); i++)
		{
			q.push({ selected[i].first,selected[i].second });
			dist[selected[i].first][selected[i].second] = 0;
		}

		int t = 0;
		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = dx[dir] + cur.first;
				int ny = dy[dir] + cur.second;

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;
				if (dist[nx][ny] != -1)
					continue;
				if (map[nx][ny] == 1)
					continue;

				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				t = max(dist[nx][ny], t);
				q.push({ nx,ny });
			}
		}
		
		//바이러스가 퍼지지 못한곳이 있다면 답을 구하지 않습니다.
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == 0 && dist[i][j] == -1)
					flag = false;
			}
		}
		if(flag)
			ans = min(ans, t);

	}

	for (int i = idx; i < v.size(); i++)
	{
		if (vist[i])
			continue;

		vist[i] = true;
		selected.push_back(v[i]);
		backtrack(i, cnt + 1);
		selected.pop_back();
		vist[i] = false;
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
				map[i][j] = 0;
			}
		}
	}

	//바이러스 m개를 선택해서, bfs를 돌린다. 
	backtrack(0,0);
	
	if (ans == 987654321)
		cout << "-1";
	else
		cout << ans;
}