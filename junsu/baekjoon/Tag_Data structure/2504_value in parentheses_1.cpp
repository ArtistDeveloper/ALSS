#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	string expression;
	stack<char> stk;
	int temp = 1, answer = 0;

	cin >> expression;

	for (int i = 0; i < expression.length(); i++)
	{
		// '(' 또는 ')'인 경우
		if (expression[i] == '(')
		{
			temp *= 2;
			stk.push('(');
		}
		else if (expression[i] == ')')
		{
			if (stk.empty() || stk.top() != '(')
			{
				answer = 0;
				break;
			}
			else if (expression[i-1] == '(')
			{
				answer += temp;
				temp /= 2;
				stk.pop();
			}
			// 이미 값이 다 더해져 있는 상태이므로 answer에 값을 더하지 않고 temp에 2를 나눈다.
			else 
			{
				temp /= 2;
				stk.pop();
			}
		}

		// '[' 또는 ']'인 경우
		else if (expression[i] == '[')
		{
			temp *= 3;
			stk.push('[');
		}
		else if (expression[i] == ']')
		{
			if (stk.empty() || stk.top() != '[')
			{
				answer = 0;
				break;
			}
			else if (expression[i-1] == '[')
			{
				answer += temp;
				temp /= 3;
				stk.pop();
			}
			else 
			{
				temp /= 3;
				stk.pop();
			}
		}
	}

	if (!stk.empty()) // 이 예외처리 안넣었을 때 틀림
		answer = 0;

	cout << answer;

	return 0;
}