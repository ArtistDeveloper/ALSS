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

		//�������� üũ�մϴ�.
		map[y][x] = 1;

		//���뿡 ���� ������ Ȯ���ϰ�, �������� �ʿ� üũ�մϴ�.
		while (g--)
		{
			//�巡��Ŀ���� ��Ģ�� �������鼭 +1���ݴϴ�.
			//2���� : 0121 -> 3����� 0121 2321
			for (int i = v.size() - 1; i >= 0; i--)
			{
				v.push_back((v[i] + 1) % 4);
			}
		}

		//���⿡ ���� �ʿ� üũ�մϴ�.
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

	//���� ��ȸ�ϸ� �� �������� ��� üũ�Ǿ����� ������ �ø��ϴ�.
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