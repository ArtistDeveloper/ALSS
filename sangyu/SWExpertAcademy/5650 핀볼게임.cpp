#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int tc, n;
int map[101][101];

//아래,오른,위,왼
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int rotDirbyBlock[5][4] = {

	{1,3,0,2},
	{2,3,1,0},
	{2,0,3,1},
	{3,2,0,1},
	{2,3,0,1},

};
int rotDirbyWall[4] = { 2,3,0,1 };
int main()
{
	cin >> tc;

	for (int testCase = 0; testCase < tc; testCase++)
	{
		cin >> n;
		vector<pair<int, int>> ballPos;

		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				//핀볼의 시작위치를 구합니다.
				if (map[i][j] == 0)
					ballPos.push_back({ i,j });
			}
		}

		//위치의 수만큼 순회를 통해 최대값을 구합니다.
		for (auto cur : ballPos)
		{
			//4가지 방향에 대해 수행합니다.(아래, 오른쪽, 위, 왼쪽)
			for (int k = 0; k < 4; k++)
			{
				int score = 0;
				int dir = k;
				//벽이나, 블록을 만날때까지 계속 전진합니다.
				int nx = cur.first;
				int ny = cur.second;
				while (true)
				{
					nx += dx[dir];
					ny += dy[dir];

					//다시 출발지점으로 돌아온다면 끝나게됩니다.

					if (nx == cur.first && ny == cur.second)
					{
						ans = max(ans, score);
						break;
					}
					//블랙홀에 빠지면 끝나게됩니다.
					else if (map[nx][ny] == -1)
					{

						ans = max(ans, score);
						break;
					}
					//벽인 경우 방향을 회전시킵니다.
					else if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					{
						score++;
						dir = rotDirbyWall[dir];
					}
					//블록일 경우 방향을 회전시킵니다.
					else if (map[nx][ny] >= 1 && map[nx][ny] <= 5)
					{
						score++;
						dir = rotDirbyBlock[map[nx][ny] - 1][dir];
					}

					//웜홀일 경우 다른 웜홀을 찾고, 위치를 교환합니다.
					else if (map[nx][ny] >= 6 && map[nx][ny] <= 10)
					{
						for (int col = 0; col < n; col++)
						{
							bool flag = false;
							for (int row = 0; row < n; row++)
							{
								//같은 웜홀이지만 위치가 다르면
								if (map[nx][ny] == map[col][row] && (nx != col && ny != row))
								{
									flag = true;

									nx = col;
									ny = row;
									break;
								}
							}
							if (flag)
								break;
						}
					}
				}
			}
		}
		cout << "#" << testCase + 1 << ' ' << ans << endl;

	}

}
