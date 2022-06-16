#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	queue<int> que;
	string operation;
	int test_case, input_num;
	
	cin >> test_case;
	
	for (int i = 0; i < test_case; i++)
	{
		cin >> operation;

		if (operation == "push")
		{
			cin >> input_num;
			que.push(input_num);
		}

		else if (operation == "pop")
		{
			if (que.empty())
			{
				cout << -1 << '\n';
				continue;
			}

			cout << que.front()<<'\n';
			que.pop();
		}

		else if (operation == "size")
		{
			cout << que.size()<<'\n';
		}

		else if (operation == "empty")
		{
			if (que.empty())
			{
				cout << 1<<'\n';
				continue;
			}

			cout << 0 << '\n';
		}

		else if (operation == "front")
		{
			if (que.empty())
			{
				cout << -1 << '\n';
				continue;
			}

			cout << que.front()<<'\n';
		}

		else if (operation == "back")
		{
			if (que.empty())
			{
				cout << -1 << '\n';
				continue;
			}

			cout << que.back()<<'\n';
		}
	}
}