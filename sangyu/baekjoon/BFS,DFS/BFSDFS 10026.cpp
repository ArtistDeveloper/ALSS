#include<iostream>
#include<queue>

using namespace std;

int n;
char board[101][101];
bool vis[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cntColorWeakness;
int cntColor;

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	vis[i][j] = 1;
	q.push({ i,j });

	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (vis[nx][ny] || board[nx][ny] != board[i][j]) continue;

			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	//������ �ƴѰ�� ������ ���մϴ�.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j])
				cntColor++;
			bfs(i, j);
		}
	}

	//������ ��� G,R�� ������ ������ݴϴ�.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}
	
	//��ȸ�ϱ� �� �湮�迭�� �ʱ�ȭ�մϴ�.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vis[i][j] = false;
		}
	}

	//������ ��� ������ ���մϴ�.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!vis[i][j])
			{
				cout << '(' << i << ',' << j << ')' << endl;
				cntColorWeakness++;
			}
			bfs(i, j);
		}
	}

	cout << cntColor << ' ' << cntColorWeakness;
}