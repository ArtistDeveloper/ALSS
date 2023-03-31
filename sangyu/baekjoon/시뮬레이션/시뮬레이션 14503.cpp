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

	//처음지점 방문을 표기합니다.
	int ans = 1;
	board[y][x] = 2;

	//북,동,남,서
	int dy[4] = { -1,0,1,0 };
	int dx[4] = { 0,1,0,-1 };
	int getNextDir[4] = { 3,0,1,2 };
	int nx, ny, nd;

	while (true)
	{
		int canNotCleanCnt=0;
		bool visit = false;
		int tempDir=dir;
		//4가지 방향에 대해 탐색하고 후진이 가능한지 확인합니다.
		for (int i = 0; i < 4; i++)
		{
			nd = getNextDir[dir];
			ny = y + dy[nd];
			nx = x + dx[nd];
		
			//방문을 하지 않았다면 방문이 가능함을 표기합니다.
			if (board[ny][nx] == 0)
			{
				visit = true;
				break;
			}
			//4방향에 대해 후진이 가능할지를 구분해야합니다.
			else if (board[ny][nx] == 1 || board[ny][nx] == 2 || (nx < 0 || ny < 0 || nx >= m || ny >= n))
			{
				dir = nd;
				canNotCleanCnt++;
			}
		}


		//방문처리를 하고, 표시를 바꾸고 방향을 바꿉니다.
		if (visit)
		{
			board[ny][nx] = 2;
			ans++;
			dir = nd;
		}
		//방문이 불가능하면 후진을합니다. 이때 뒤에 벽이 있다면 break합니다.
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
