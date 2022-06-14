#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int num;
	stack<char> stk_left_parenthesis;
	string data;

	bool isVPS = true;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> data;
		
		for (int j = 0; j < data.length(); j++)
		{
			if (data[j] == '(')
			{
				stk_left_parenthesis.push('(');
			}

			else
			{
				if (stk_left_parenthesis.empty())
				{
					isVPS = false;
					break;
				}
				else
				{
					stk_left_parenthesis.pop();
				}
			}
		}

		if (isVPS && stk_left_parenthesis.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;


		while (!stk_left_parenthesis.empty())
		{
			stk_left_parenthesis.pop();
		}

		isVPS = true;
	}

	return 0;
}