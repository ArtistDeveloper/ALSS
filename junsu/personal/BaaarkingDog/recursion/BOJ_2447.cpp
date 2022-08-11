#include <iostream>

using namespace std;

char board[2188][2188];

void solve(int row, int col, int n)
{
	if (n == 1)
	{
		board[row][col] = '*';
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1) // 공백은 건너 뜀
				continue;
			
			solve(row + n / 3 * i, col + n / 3 * j, n / 3);
		}
	}
}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		fill(board[i], board[i] + n, ' ');
	}

	solve(0, 0, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}
