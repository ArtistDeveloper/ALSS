#include<iostream>
using namespace std;
int n,m;
int arr[10];

void func(int cur)
{
	if (cur == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i]<<' ';
		}
		cout << '\n';
		return;
	}

	//같은 수를 써서 수열을 구성하고, 중복된 수열을 만들지 않으려면, 자기보다 작은 수로 수열을 이루는 경우는 없어야함.
	for (int i = 1; i <= n; i++)
	{
		if (cur == 0)
		{
			arr[cur] = i;
			func(cur + 1);
		}
		else if (cur>=1)
		{
			if (i >= arr[cur - 1])
			{
				arr[cur] = i;
				func(cur + 1);
			}
		}
	}
	
}
int main()
{
	cin >> n >> m;
	func(0);

}