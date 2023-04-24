#include<iostream>
#include<vector>
using namespace std;

int n;
int map[101][101];

int main()
{
	cin >> n;
	int ans = 0;

	while (n--)
	{
		int x, y, d, g;

		cin >> x >> y >> d >> g;

		vector<int> v;
		v.push_back(d);

		//시작점을 체크합니다.
		map[y][x] = 1;

		//세대에 맞춰 방향을 확인하고, 역순으로 맵에 체크합니다.
		while (g--)
		{
			//드래곤커브의 규칙은 역순빼면서 +1해줍니다.
			//2세대 : 0121 -> 3세대는 0121 2321
			for (int i = v.size() - 1; i >= 0; i--)
			{
				v.push_back((v[i] + 1) % 4);
			}
		}

		//방향에 따라 맵에 체크합니다.
		for (int i : v)
		{
			if (i == 0)
				map[y][++x] = 1;
			else if (i == 1)
				map[--y][x] = 1;
			else if (i == 2)
				map[y][--x] = 1;
			else if (i == 3)
				map[++y][x] = 1;
		}
	}

	//맵을 순회하며 네 꼭짓점이 모두 체크되었으면 개수를 올립니다.
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
			{
				ans++;
			}
		}
	}
	cout << ans;
}