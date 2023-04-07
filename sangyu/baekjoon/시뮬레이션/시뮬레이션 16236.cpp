#include<iostream>
#include<queue>
#include<cstdio>


using namespace std;

const int MAX = 123456789;
int n;
int newX= MAX,newY= MAX,minDist= MAX,sharkSize=2;
pair<int, int> sharkPos;
int map[21][21],check[21][21];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

//전체 탐색을 통해 조건에 적합한 물고기를 찾아야함.
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	check[x][y] = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			//범위를 벗어나거나, 자기보다 큰 물고기 , 방문 했으면 
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (map[nx][ny] > sharkSize || check[nx][ny] != -1)
				continue;

			check[nx][ny] = check[cur.first][cur.second] + 1;

			//먹을 수 있는 물고기가 있다면
			if (map[nx][ny] < sharkSize && map[nx][ny] != 0)
			{

				//가장 가까운 거리인지 비교해야함
				if (check[nx][ny] < minDist)
				{
					minDist = check[nx][ny];
					newX = nx;
					newY = ny;
				}
				//가장 가까운 거리가 또있으면 위,왼 쪽 인곳부터.
				else if (check[nx][ny] == minDist)
				{
					if (nx == newX)
					{
						if (ny < newY)
						{
							newX = nx;
							newY = ny;
						}
					}
					else if (nx < newX)
					{
						newX = nx;
						newY = ny;
					}
				}
			}
			q.push({ nx,ny });

		}
	}
}

//먹을 수 있는 물
int main()
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%1d", &map[i][j]);
			if (map[i][j] == 9)
			{
				sharkPos = { i,j };
				map[i][j] = 0;
			}
		}
	}

	int ans = 0;
	int eatCnt = 0;
	
	while (true)
	{
		//매번 거리(시간)를 다시재야함
		newX = MAX;
		newY = MAX;
		minDist = MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				check[i][j] = -1;
			}
		}
		//물고기를 차자야함
		bfs(sharkPos.first, sharkPos.second);


		//맵을 갱신하고 상어위치도 갱신
		//물고기를 찾았다면 시간을 더하고 먹은개수를 증가시킴.
		//먹은 개수랑 사이즈랑 같으면 사이즈업해야함
		if (newX != MAX && newY != MAX)
		{
			ans += check[newX][newY];
			eatCnt++;

			if (eatCnt == sharkSize)
			{
				sharkSize++;
				eatCnt = 0;
			}

			map[newX][newY] = 0;
			sharkPos = { newX,newY };
		}
		else
			break;
	}

	std::cout << ans;
}