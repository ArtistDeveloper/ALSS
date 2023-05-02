#include<iostream>
#include<deque>
using namespace std;

int arr[9][9];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t;
	for (int tc = 0; tc < 10; tc++)
	{
		deque<int> dq;
		cin >> t;
		for (int i = 0; i < 8; i++)
		{
			int n;
			cin >> n;
			dq.push_back(n);
		}

		while (true)
		{
			bool flag = false;
			for (int i = 1; i <= 5; i++)
			{
				int temp = dq.front();
				dq.pop_front();

				if (temp - i > 0)
					dq.push_back(temp - i);
				else
				{
					flag = true;
					dq.push_back(0);
					break;
				}
			}
			if (flag)
				break;
		}

		for (auto i : dq)
			cout << i << ' ';
		cout << endl;
	}
}