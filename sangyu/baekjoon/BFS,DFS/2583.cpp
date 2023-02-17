#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int board[101][101];
bool check[101][101];

int n, m, k;
int dirX[4] = { 1,-1,0,0 };
int dirY[4] = { 0,0,1,-1 };

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++)
		{
			for (int z = x1; z < x2; z++)
			{
				board[j][z] = 1;
				check[j][z] = true;
			}
		}
	}

	vector<int> area;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			
			if (check[i][j] == false)
			{
				int areacnt = 1;
				queue<pair<int, int>> q;
				check[i][j] = true;
				q.push({ i,j });
				
				//bfs Ω√¿€
				while (!q.empty())
				{
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					
					for (int z = 0; z < 4; z++)
					{
						int nx = x + dirX[z];
						int ny = y + dirY[z];
						if (ny >= n || nx >= m || nx < 0 || ny < 0) continue;
						if (check[ny][nx]==true) continue;

						q.push({ ny,nx });
						check[ny][nx] = true;
						areacnt++;	
					}
				}
				area.push_back(areacnt);
			}
		}
	}

	std::cout << area.size() << '\n';
	std::sort(area.begin(), area.end());
	for (auto i : area)
	{
		std::cout << i << ' ';
	}

}