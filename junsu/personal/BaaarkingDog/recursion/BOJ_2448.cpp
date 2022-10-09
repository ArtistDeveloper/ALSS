//#include <iostream>
//
//using namespace std;
//
//char board[3072][6143]; // 3072: 2^10 * 3, 6143: n x (n*2) - 1
//
//void solve(int row, int col, int n)
//{
//	if (n == 3)
//	{
//		board[row][col] = '*';
//		board[row + 1][col - 1] = '*';
//		board[row + 1][col + 1] = '*';
//		for (int i = 0; i < 5; i++)
//		{
//			board[row + 2][col - 2 + i] = '*';
//		}
//	}
//	else
//	{
//		solve(row, col, n / 2);
//		solve(row + (n / 2), col - (n / 2), n / 2);
//		solve(row + (n / 2), col + (n / 2), n / 2);
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		fill(board[i], board[i] + n, ' ');
//	}
//
//	solve(0, n - 1, n);
//
//	// 출력
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n * 2 - 1; j++)
//		{
//			cout << board[i][j];
//		}
//		cout << '\n';
//	}
//
//	return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>>board;

void solve(int n, int row, int col)
{
	if (n == 3)
	{
		board[row][col] = '*';
		board[row + 1][col - 1] = '*';
		board[row + 1][col + 1] = '*';
		for (int i = 0; i < 5; i++)
		{
			board[row + 2][col - 2 + i] = '*';
		}
	}
	else
	{
		solve(n / 2, row, col);
		solve(n / 2, row + n / 2, col - n / 2);
		solve(n / 2, row + n / 2, col + n / 2);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// 아니 배열에서 벡터로 바꾸니까 됐네. 실화여?
	board = vector<vector<char>>(n, vector<char>(n * 2 - 1, ' '));

	solve(n, 0, n - 1);

	// 출력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2 - 1; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}

	return 0;
}
