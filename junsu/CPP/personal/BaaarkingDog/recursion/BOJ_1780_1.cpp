#include <iostream>

using namespace std;

// 최대 4,782,969 번의 데이터 접근이 이루어짐
int map[2187][2187]; // n은 최대 3^7이 올 수 있으므로 이 정도의 값을 넣을 수 있는 배열 선언
int result[3];


void func(int row, int col, int n)
{
	for (int i = row; i < row + n; i++)
	{
		for (int j = col; j < col + n; j++)
		{
			if (map[row][col] != map[i][j])
			{
				func(row, col, n / 3);
				func(row, col + (n * 1 / 3), n / 3);
				func(row, col + (n * 2 / 3), n / 3);

				func(row + (n * 1 / 3), col, n / 3);
				func(row + (n * 1 / 3), col + (n * 1 / 3), n / 3);
				func(row + (n * 1 / 3), col + (n * 2 / 3), n / 3);

				func(row + (n * 2 / 3), col, n / 3);
				func(row + (n * 2 / 3), col + (n * 1 / 3), n / 3);
				func(row + (n * 2 / 3), col + (n * 2 / 3), n / 3);

				return;
			}
		}
	}

	result[map[row][col] + 1]++;

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
			int temp;
			cin >> temp;
			
			map[i][j] = temp;
		}
	}

	func(0, 0, n);

	cout << result[0] << "\n" << result[1] << "\n" << result[2];

	return 0;
}
