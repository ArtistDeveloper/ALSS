#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[10];
int inputarr[10];
bool visit[10001];

void func(int cur)
{
	if (cur == m)
	{		
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	//중복이 허용이 안되고, cur+1는 cur보다 큰값을 가져야함.
	for (int i = 0; i < n; i++)
	{
		if (cur == 0 && !visit[inputarr[i]])
		{
			visit[inputarr[i]] = 1;
			arr[cur] = inputarr[i];
			func(cur + 1);
			visit[inputarr[i]] = 0;
		}
		else if(!visit[inputarr[i]] && cur>=1)
		{
			if(inputarr[i] >=arr[cur-1])
			{
				visit[inputarr[i]] = 1;
				arr[cur] = inputarr[i];
				func(cur + 1);
				visit[inputarr[i]] = 0;
			}
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