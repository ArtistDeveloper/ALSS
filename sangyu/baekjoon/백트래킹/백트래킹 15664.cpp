#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int input[10];
int arr[10];
bool issue[10005];
void func(int cur)
{
	if (cur == m)
	{
		for (int i = 0; i < m; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	//직전에 온 수가 오면안됨.
	int check = 0;
	for (int i = 0; i < n; i++)
	{
		if (cur >= 1)
		{
			if (!issue[i] && check != input[i])
			{
				if (input[i] >= arr[cur - 1])
				{
					arr[cur] = input[i];
					check = input[i];

					issue[i] = 1;
					func(cur + 1);
					issue[i] = 0;
				}
			}
		}
		else
		{
			if (!issue[i] && check != input[i])
			{
				arr[cur] = input[i];
				check = input[i];

				issue[i] = 1;
				func(cur + 1);
				issue[i] = 0;
			}
		}

	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	sort(input, input + n);

	func(0);
}