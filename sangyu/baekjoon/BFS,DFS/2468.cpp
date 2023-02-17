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
int SafeArea = 1;  //아무지역도 안잠길때

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

	//1이 잠겼을때, 2가잠겼을때 ... n이 잠겼을때. 를 생각해서 안전영역이 제일 많을때를 출력.
	//깊이가 2일때, 3,4,5,6,7,8 ...이 안전한 영역임.
	//깊이가 3일때. 4,5,6,7,8 ... 이 안전한영역.
	
	for (int k = minDepth; k <= maxDepth; k++)
	{
		//깊이마다 초기화해줘야함.
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = false;
			}
		}

		//깊이마다 낮으면 안전한 영역아님 
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
				//안전하다면 bfs를 돌림.
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

							//범위밖이면
							if (nx < 0 || ny < 0 || nx >= n || ny >= n)
								continue;
						
							//방문했었으면
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