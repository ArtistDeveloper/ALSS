#include<iostream>
using namespace std;

int n;
int arr[2500][2500];
//9 -> 3x3이 9개.  27-> 3x3x3
int ans[3]; // -1,0,1;

bool check(int size, int x, int y)
{
	//칸을 전부 검사한후 다른지 확인합니다.
	int s = arr[y][x];
	for (int i = y; i < y+size; i++)
	{
		for (int j = x; j < x+size; j++)
		{
			if (s != arr[i][j])
				return false;
		}
	}
	return true;
}

void recusion(int size, int x, int y)
{
	//
	if (check(size, x, y))
	{
		if (arr[y][x] == -1)
			ans[0]++;
		else if (arr[y][x] == 0)
			ans[1]++;
		else
			ans[2]++;
	}
	//9등분
	else
	{
		int newSize = size / 3;
	
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				recusion(newSize, x + newSize * i, y + newSize * j);
			}
		}
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
			cin >> arr[i][j];
		}
	}
	recusion(n,0,0);
	cout << ans[0] << '\n' << ans[1] << '\n' << ans[2] << '\n';
}