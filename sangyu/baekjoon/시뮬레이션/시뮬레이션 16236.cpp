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

//��ü Ž���� ���� ���ǿ� ������ ����⸦ ã�ƾ���.
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

			//������ ����ų�, �ڱ⺸�� ū ����� , �湮 ������ 
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (map[nx][ny] > sharkSize || check[nx][ny] != -1)
				continue;

			check[nx][ny] = check[cur.first][cur.second] + 1;

			//���� �� �ִ� ����Ⱑ �ִٸ�
			if (map[nx][ny] < sharkSize && map[nx][ny] != 0)
			{

				//���� ����� �Ÿ����� ���ؾ���
				if (check[nx][ny] < minDist)
				{
					minDist = check[nx][ny];
					newX = nx;
					newY = ny;
				}
				//���� ����� �Ÿ��� �������� ��,�� �� �ΰ�����.
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

//���� �� �ִ� ��
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
		//�Ź� �Ÿ�(�ð�)�� �ٽ������
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
		//����⸦ ���ھ���
		bfs(sharkPos.first, sharkPos.second);


		//���� �����ϰ� �����ġ�� ����
		//����⸦ ã�Ҵٸ� �ð��� ���ϰ� ���������� ������Ŵ.
		//���� ������ ������� ������ ��������ؾ���
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