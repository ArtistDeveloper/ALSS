#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()
{
	int n, value;
	string s;
	deque<int> dq;

	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		cin >> s;
		
		if (s == "push_front")
		{
			cin >> value;
			dq.push_front(value);
		}

		else if (s == "push_back") 
		{
			cin >> value;
			dq.push_back(value);
		}

		else if (s == "pop_front") 
		{
			if (dq.empty()) 
			{
				cout << -1 << '\n';
			}
			else 
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}

		else if (s == "pop_back") {
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else 
			{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}

		else if (s == "size") 
		{
			cout << dq.size() << '\n';
		}

		else if (s == "empty") 
		{
			if (dq.empty())
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}

		else if (s == "front") 
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
			}
		}

		else if (s == "back") 
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() << '\n';
			}
		}
	}


	return 0;
}