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

	// ���� ����
	for (int i = 0; i < inputData.length(); i++)
	{
		// '('�� �ԷµǾ��� ��
		if (inputData[i] == '(')
		{
			stk.push('(');
			buffer = '(';
		}
		// ')'�� �Է� �Ǿ��� ��
		else if (inputData[i] == ')')
		{
			// �������� ���
			if (buffer == '(')
			{
				buffer = ')';
				stk.pop();

				result += stk.size();
			}
			// ������ ���� ���
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