#include<iostream>
using namespace std;

int n, m;
char map[21][21];
bool visit[30];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 0;
//모든 경로에 대해 탐색하도록 백트래킹을 진행합니다.
void dfs(int x, int y,int cnt)
{
	ans=max(ans, cnt);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		//범위 밖, 이미 방문한 알파벳이라면 continue
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if (visit[map[nx][ny] - 'A'])
			continue;

		visit[map[nx][ny] - 'A'] = 1;
		dfs(nx, ny, cnt+1);
		visit[map[nx][ny] - 'A'] = 0;
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
		}
	}
	
	visit[map[0][0] - 'A'] = 1;
	dfs(0, 0,1);

	cout << ans;
}