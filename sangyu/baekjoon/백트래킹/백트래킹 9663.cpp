#include<iostream>

//같은 행에는 놓을 수가 없다.
//같은 열에도 놓을 수 가 없다.
//대각선은 x+y, x+y-n-1로 지정할수있다.
using namespace std;
int n;
int cnt = 0;

bool i1[30]; // y축에 대해 선택을 했는지
bool i2[30]; // 왼쪽 아래에서 오른쪽 위로 향하는 대각선에 대해 선택을 했는지
bool i3[30]; // 오른쪽 위에서 왼쪽 아래로 향하는 대각선에 대해 선택을 했는지

void back(int cur)
{
	//판에 올라간 퀸의 개수가 n개라면 경우의 수를 증가시킵니다.
	if (cur == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (i1[i] || i2[cur+i] || i3[cur - i + n - 1])
			continue;
		i1[i] = true;
		i2[cur + i] = true;
		i3[cur - i + n - 1] = true;

		back(cur+1);

		//i에 대한 경우를 다른 경우에도 사용하기 위해 false로 바꿔줍니다.
		i1[i] = false;
		i2[cur + i] = false;
		i3[cur - i + n - 1] = false;

	}
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n;
	back(0);

	cout << cnt;
}