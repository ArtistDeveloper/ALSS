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
		// '(' �Ǵ� ')'�� ���
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
			// �̹� ���� �� ������ �ִ� �����̹Ƿ� answer�� ���� ������ �ʰ� temp�� 2�� ������.
			else 
			{
				temp /= 2;
				stk.pop();
			}
		}

		// '[' �Ǵ� ']'�� ���
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

	if (!stk.empty()) // �� ����ó�� �ȳ־��� �� Ʋ��
		answer = 0;

	cout << answer;

	return 0;
}