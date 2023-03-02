#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int result = 0;
	stack<int> stk;
	string inputData;
	char buffer = ' ';

	cin >> inputData;

	// 로직 수행
	for (int i = 0; i < inputData.length(); i++)
	{
		// '('가 입력되었을 때
		if (inputData[i] == '(')
		{
			stk.push('(');
			buffer = '(';
		}
		// ')'가 입력 되었을 때
		else if (inputData[i] == ')')
		{
			// 레이저인 경우
			if (buffer == '(')
			{
				buffer = ')';
				stk.pop();

				result += stk.size();
			}
			// 막대의 끝인 경우
			else
			{
				buffer = ')';
				stk.pop();
				result += 1;
			}
		}
	}

	cout << result;

	return 0;
}