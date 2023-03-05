#include<iostream>

using namespace std;

int n,m;
int ans[10];
void func(int cur)
{
	//선택한 개수가 m개 라면 출력을 합니다.
	if (cur == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << "\n";
		return;
	}


	//m개가 아니라면 선택지를 늘리게됩니다.
	//수가 중복됨으로 중복체크는 하지 않습니다.
	for (int i = 1; i <= n; i++)
	{
		ans[cur] = i;
		func(cur + 1);
	}
}

int main()
{
	cin >> n >> m;
	func(0);
}