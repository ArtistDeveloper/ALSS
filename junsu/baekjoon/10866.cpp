#include <iostream>
#include <deque>
#include <string>

using namespace std;

void redefine_push_front(deque<int>& dq, int value)
{
	dq.push_front(value);
}

void redefine_push_back(deque<int>& dq, int value)
{
	dq.push_back(value);
}

void pop_front(deque<int>& dq)
{
	if (!dq.empty())
	{
		cout << dq.front() << '\n';
		dq.pop_front();
	}
	else
	{
		cout << -1 << '\n';
	}
}

void pop_back(deque<int>& dq)
{
	if (!dq.empty())
	{
		cout << dq.back() << '\n';
		dq.pop_back();
	}
	else
	{
		cout << -1 << '\n';
	}
}

void size(deque<int>& dq)
{
	cout << dq.size() << '\n';
}

void empty(deque<int>& dq)
{
	cout << dq.empty() << '\n';
}

void redefine_front(deque<int>& dq)
{
	if (!dq.empty())
	{
		cout << dq.front() << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}
}

void redefine_back(deque<int>& dq)
{
	if (!dq.empty())
	{
		cout << dq.back() << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}
}


int main()
{
	int n, value;
	string oper;
	deque<int> dq;

	cin >> n;

	//redefine_push_back(dq, 1);
	//redefine_push_front(dq, 2);
	//redefine_front(dq);
	//redefine_back(dq);

	for (int i = 0; i < n; i++)
	{
		cin >> oper;

		if (oper == "push_front")
		{
			cin >> value;
			redefine_push_front(dq, value);
		}
		else if (oper == "push_back")
		{
			cin >> value;
			redefine_push_back(dq, value);
		}
		else if (oper == "pop_front")
		{
			pop_front(dq);
		}
		else if (oper == "pop_back")
		{
			pop_back(dq);
		}
		else if (oper == "size")
		{
			size(dq);
		}
		else if (oper == "empty")
		{
			empty(dq);
		}
		else if (oper == "front")
		{
			redefine_front(dq);
		}
		else if (oper == "back")
		{
			redefine_back(dq);
		}
	}

	return 0;
}

