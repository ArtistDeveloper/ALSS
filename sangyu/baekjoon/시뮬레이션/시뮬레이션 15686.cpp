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

	//전체 치킨집중, m개의 치킨집을 고르는 조합하면됨. 5개의 치킨중 2개를 뽑는다면 {0,0,0,1,1} 중 1인 치킨집의 거리만 비교합니다.
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
			//집에서 골라야하는 치킨집 거리중 작은값을 찾습니다.
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