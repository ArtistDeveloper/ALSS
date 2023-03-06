#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[10];
int inputarr[10];
bool visit[10000];
void func(int cur)
{
	if (cur == m)
	{
		for (int i = 0; i <m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visit[inputarr[i]])
		{
			arr[cur] = inputarr[i];

			visit[inputarr[i]] = 1;
			func(cur + 1);
			visit[inputarr[i]] = 0;
		}
	}
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> inputarr[i];
	}
	sort(inputarr, inputarr + n);

	func(0);
}