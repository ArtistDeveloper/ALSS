#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n;

int maxDepth=1;
int minDepth=200;
int area[101][101];
int check[101][101];
bool visited[101][101];
int SafeArea = 1;  //�ƹ������� ����涧

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> area[i][j];
			maxDepth = max(maxDepth, area[i][j]);
			minDepth = min(minDepth, area[i][j]);
		}
	}

	//1�� �������, 2��������� ... n�� �������. �� �����ؼ� ���������� ���� �������� ���.
	//���̰� 2�϶�, 3,4,5,6,7,8 ...�� ������ ������.
	//���̰� 3�϶�. 4,5,6,7,8 ... �� �����ѿ���.
	
	for (int k = minDepth; k <= maxDepth; k++)
	{
		//���̸��� �ʱ�ȭ�������.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = false;
			}
		}

		//���̸��� ������ ������ �����ƴ� 
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				if (area[y][x] <= k)
					visited[y][x] = true;
			}
		}

		int cnt = 0;

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				//�����ϴٸ� bfs�� ����.
				if (visited[y][x] != true)
				{
					queue<pair<int, int>> q;
					q.push({ y,x });
					visited[y][x] = true;

					while (!q.empty())
					{
						int curx = q.front().second;
						int cury = q.front().first;
						q.pop();
						for (int i = 0; i < 4; i++)
						{
							int nx = dx[i] + curx;
							int ny = dy[i] + cury;

							//�������̸�
							if (nx < 0 || ny < 0 || nx >= n || ny >= n)
								continue;
						
							//�湮�߾�����
							if (visited[ny][nx])
								continue;
							
							q.push({ ny,nx });
							visited[ny][nx] = true;
						}
					}
					cnt++;
				}
			}
		}

		if (SafeArea < cnt)
			SafeArea = cnt;
	}

	cout << SafeArea;
}