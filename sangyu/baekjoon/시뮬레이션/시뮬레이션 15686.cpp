#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;

int board[51][51];
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;

int main()
{
	cin >> n>>m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				houses.push_back({ i,j });
			else if (board[i][j] == 2)
				chickens.push_back({ i,j });
		}
	}

	//��ü ġŲ����, m���� ġŲ���� ���� �����ϸ��. 5���� ġŲ�� 2���� �̴´ٸ� {0,0,0,1,1} �� 1�� ġŲ���� �Ÿ��� ���մϴ�.
	vector<int> combine(chickens.size(), 1);
	for (int i = 0; i < chickens.size() - m; i++)
	{
		combine[i] = 0;
	}

	int minCityDist = 123456789;
	do
	{
		int cityDist = 0;
		for (pair<int, int> house : houses)
		{
			int dist = 123456789;
			//������ �����ϴ� ġŲ�� �Ÿ��� �������� ã���ϴ�.
			for (int i = 0; i < chickens.size(); i++)
			{
				if (combine[i] == 0)
				{
					continue;
				}
				else
				{
					dist = min(dist, abs(chickens[i].first - house.first) + abs(chickens[i].second - house.second));
				}
			}
			cityDist += dist;
		}
		minCityDist = min(minCityDist, cityDist);
	} while (next_permutation(combine.begin(), combine.end()));

	cout << minCityDist;
}