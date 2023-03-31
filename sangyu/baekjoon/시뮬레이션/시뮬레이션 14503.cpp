#include<iostream>


using namespace std;

int n, m, dir;
int board[51][51];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n >> m;

	int y, x, dir;
	cin >> y >> x >> dir;

	for (int i = 0; i < n; i++)  
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	//ó������ �湮�� ǥ���մϴ�.
	int ans = 1;
	board[y][x] = 2;

	//��,��,��,��
	int dy[4] = { -1,0,1,0 };
	int dx[4] = { 0,1,0,-1 };
	int getNextDir[4] = { 3,0,1,2 };
	int nx, ny, nd;

	while (true)
	{
		int canNotCleanCnt=0;
		bool visit = false;
		int tempDir=dir;
		//4���� ���⿡ ���� Ž���ϰ� ������ �������� Ȯ���մϴ�.
		for (int i = 0; i < 4; i++)
		{
			nd = getNextDir[dir];
			ny = y + dy[nd];
			nx = x + dx[nd];
		
			//�湮�� ���� �ʾҴٸ� �湮�� �������� ǥ���մϴ�.
			if (board[ny][nx] == 0)
			{
				visit = true;
				break;
			}
			//4���⿡ ���� ������ ���������� �����ؾ��մϴ�.
			else if (board[ny][nx] == 1 || board[ny][nx] == 2 || (nx < 0 || ny < 0 || nx >= m || ny >= n))
			{
				dir = nd;
				canNotCleanCnt++;
			}
		}


		//�湮ó���� �ϰ�, ǥ�ø� �ٲٰ� ������ �ٲߴϴ�.
		if (visit)
		{
			board[ny][nx] = 2;
			ans++;
			dir = nd;
		}
		//�湮�� �Ұ����ϸ� �������մϴ�. �̶� �ڿ� ���� �ִٸ� break�մϴ�.
		if (canNotCleanCnt == 4)
		{
			ny = y - dy[tempDir];
			nx = x - dx[tempDir];
			dir = tempDir;

			if (board[ny][nx] == 1 || (nx < 0 || ny < 0 || nx >= m || ny >= n))
				break;
		}
		x = nx;
		y = ny;
	}
	cout << ans;
}
