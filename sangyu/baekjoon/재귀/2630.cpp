#include<iostream>

using namespace std;

int n;
int p[130][130];
int check[2];
void re(int y, int x, int n)
{
	if (n == 1 && p[y][x] == 0)
	{
		check[p[y][x]]++;
		return;
	}
	else if (n == 1 && p[y][x] == 1)
	{
		check[p[y][x]]++;
		return;
	}
	bool isSame = true;
	//같은 종이인지 확인합니다.
	for (int i = y; i < y+n; i++)
	{
		for (int j = x; j < x+n; j++)
		{
			if (p[y][x] != p[i][j])
			{
				isSame = false;
				break;
			}
		}
	}
	if (isSame)
	{
		check[p[y][x]]++;
		return;
	}
	if (!isSame)
	{
		int newSize = n / 2;
		re(y, x, newSize);
		re(y + newSize, x, newSize);
		re(y, x + newSize, newSize);
		re(y + newSize, x + newSize, newSize);
	}
	
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> p[i][j];
		}
	}

	re(0, 0, n);

	for (auto i : check)
	{
		cout << i << '\n';
	}
}