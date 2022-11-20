#include <iostream>

using namespace std;

int map[128][128];
int result[2];

void func(int row, int col, int n)
{
	for (int i = row; i < row + n; i++)
	{
		for (int j = col; j < col + n; j++)
		{
			if (map[row][col] != map[i][j])
			{
				func(row, col, n / 2);
				func(row, col + (n * 1/2), n / 2);

				func(row + (n * 1 / 2), col, n / 2);
				func(row + (n * 1 / 2), col + (n * 1 / 2), n / 2);

				return;
			}
		}
	}

	result[map[row][col]]++;

	return;
}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	func(0, 0, n);
	cout << result[0] << '\n' << result[1];

	return 0;
}
