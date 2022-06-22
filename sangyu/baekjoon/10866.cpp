#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int num;
	int storage;
	string str;
	deque<int> dq;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		cin >> str;

		if (str == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}

		else if (str == "push_front")
		{
			cin >> num;
			dq.push_front(num);
		}

		else if (str == "front")
		{
			if (dq.empty()) 
			{
				cout << -1 << '\n';
				continue;
			}
			cout << dq.front() << '\n';
		}

		else if (str == "back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << dq.back() << '\n';
		}

		else if (str == "pop_front")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << dq.front() << '\n';
			dq.pop_front();
		}

		else if (str == "pop_back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << dq.back() << '\n';
			dq.pop_back();
		}

		else if (str == "size")
		{
			cout << dq.size() << '\n';
		}
		else if (str == "empty")
		{
			cout << dq.empty() << "\n";
		}

	}
}