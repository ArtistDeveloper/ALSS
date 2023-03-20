#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int n;
int m = 5;
int ans = 0;
bool visit[5];

vector<vector<int>> up(vector<vector<int>> grid)
{
	bool isSum[21][21] = { false, };
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (grid[j][i] == 0)
				continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (grid[k][i] == grid[k + 1][i] && !isSum[k][i])
				{
					grid[k][i] *= 2;
					grid[k + 1][i] = 0;
					isSum[k][i] = true;
					break;
				}
				else if (grid[k][i] == 0)
				{
					grid[k][i] = grid[k + 1][i];
					grid[k + 1][i] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return grid;

}

vector<vector<int>> down(vector<vector<int>> grid)
{
	bool isSum[21][21] = { false, };
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			if (grid[j][i] == 0)
				continue;
			for (int k = j + 1; k < n; k++)
			{
				if (grid[k][i] == grid[k - 1][i] && !isSum[k][i])
				{
					grid[k][i] *= 2;
					grid[k - 1][i] = 0;
					isSum[k][i] = true;
					break;
				}
				else if (grid[k][i] == 0)
				{
					grid[k][i] = grid[k - 1][i];
					grid[k - 1][i] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return grid;

}

vector<vector<int>> right(vector<vector<int>> grid)
{
	bool isSum[21][21] = { false, };
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			if (grid[i][j] == 0)
				continue;
			for (int k = j + 1; k < n; k++)
			{
				if (grid[i][k] == grid[i][k - 1] && !isSum[i][k])
				{
					grid[i][k] *= 2;
					grid[i][k - 1] = 0;
					isSum[i][k] = true;
					break;
				}
				else if (grid[i][k] == 0)
				{
					grid[i][k] = grid[i][k - 1];
					grid[i][k - 1] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return grid;
}

vector<vector<int>> left(vector<vector<int>> grid)
{
	bool isSum[21][21]={false,};

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (grid[i][j] == 0)
				continue;
			for (int k = j - 1; k >= 0; k--)
			{
				if (grid[i][k] == grid[i][k + 1] && !isSum[i][k])
				{
					grid[i][k] *= 2;
					grid[i][k + 1] = 0;
					isSum[i][k] = true;
					break;
				}
				else if (grid[i][k] == 0)
				{
					grid[i][k] = grid[i][k + 1];
					grid[i][k + 1] = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return grid;

}

void BackTracking(int cur, vector<vector<int>> grid)
{
	
	if (cur == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ans = std::max(grid[i][j], ans);
			}
		}
		return;
	}

	BackTracking(cur + 1, up(grid));
	BackTracking(cur + 1, down(grid));
	BackTracking(cur + 1, right(grid));

	BackTracking(cur + 1,left(grid));

}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n;

	vector<vector<int>> grid(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	BackTracking(0,grid);
	cout << ans;
}