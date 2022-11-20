#include <iostream>
#include <queue>
#include <string>

using namespace std;

void push(int value, queue<int>& q)
{
	q.push(value);
}

void pop(queue<int>& q)
{
	if (q.empty())
	{
		cout << -1 << '\n';
	}
	else
	{
		cout << q.front() << '\n';
		q.pop();
	}
}

void size(queue<int>& q)
{
	cout << q.size() << '\n';
}

void empty(queue<int>& q)
{
	cout << q.empty() << '\n';
}

void front(queue<int>& q)
{
	if (q.empty()) cout << -1 << '\n';
	else cout << q.front() << '\n';
}

void back(queue<int>& q)
{
	if (q.empty()) cout << -1 << '\n';
	else cout << q.back() << '\n';
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int temp;
	string oper;

	cin >> n;

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		cin >> oper;
		if (oper == "push")
		{
			cin >> temp;
			push(temp, q);
		}
		else if (oper == "pop")
		{
			pop(q);
		}
		else if (oper == "size")
		{
			size(q);
		}
		else if (oper == "empty")
		{
			empty(q);
		}
		else if (oper == "front")
		{
			front(q);
		}
		else if (oper == "back")
		{
			back(q);
		}
	}

	return 0;
}
