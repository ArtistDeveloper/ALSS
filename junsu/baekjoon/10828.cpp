// 개행안넣어서 틀린 문제

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int num, temp;
	string operation;
	stack<int> stk;
	
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> operation;

		if (operation == "push")
		{
			cin >> temp;
			stk.push(temp);
		}

		else if (operation == "pop")
		{
			if (stk.empty())
			{
				cout << -1 << endl;
				continue;
			}

			cout << stk.top() << endl;
			stk.pop();
		}

		else if (operation == "size")
		{
			cout << stk.size() << endl;
		}

		else if (operation == "empty")
		{
			if (stk.empty())
			{
				cout << 1 << endl;
				continue;
			}
			cout << 0 << endl;
		}

		else if (operation == "top")
		{
			if (stk.empty())
			{
				cout << -1 << endl;
				continue;
			}
			cout << stk.top() << endl;
		}
	}
	

	return 0;
}