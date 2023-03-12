#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<int> input;
int arr[10];

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

	for (int i = 0; i < input.size(); i++)
	{
		if (cur >= 1)
		{
			if (arr[cur-1] <= input[i])
			{
				arr[cur] = input[i];
				func(cur + 1);
			}
		}
		else
		{
			arr[cur] = input[i];
			func(cur + 1);
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		input.push_back(num);
	}

	sort(input.begin(),input.end());
	input.erase(unique(input.begin(), input.end()), input.end());
	func(0);
}