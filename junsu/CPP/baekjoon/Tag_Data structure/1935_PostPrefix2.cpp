#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef struct _TopValues
{
	double topFirst; // ù ��°�� �� top�� ��
	double topSecond; // �� ��°�� �� top�� ��
}TopValues;


TopValues getTopValues(stack<double>& stk)
{
	TopValues topValues;
	
	topValues.topFirst = stk.top();
	stk.pop();

	topValues.topSecond = stk.top();
	stk.pop();

	return topValues;
}

int main()
{
	stack<double> stk;
	string expression;
	int n;

	cin >> n; // �ǿ������� ���� �Է�
	cin >> expression; // ���� ǥ��� �Է�, ���� ǥ����� ���̴� 100�� ���� �ʴ´�.

	int corresponding_num[26];
	
	// �ǿ����ڿ� �����ϴ� �� �ֱ�, �ǿ����ڴ� A ~ Z�� ���� ��, 26���� ���δ�.
	for (int i = 0; i < n; i++)
	{
		cin >> corresponding_num[i];
	}

	// ������ ���� ����ǥ��� ����
	TopValues topValues;
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == '+')
		{
			topValues = getTopValues(stk);
			double pushValue = topValues.topSecond + topValues.topFirst;
			stk.push(pushValue);

			continue;
		}
		else if (expression[i] == '-')
		{
			topValues = getTopValues(stk);
			double pushValue = topValues.topSecond - topValues.topFirst;
			stk.push(pushValue);

			continue;
		}
		else if (expression[i] == '*')
		{
			topValues = getTopValues(stk);
			double pushValue = topValues.topSecond * topValues.topFirst;
			stk.push(pushValue);

			continue;
		}
		else if (expression[i] == '/')
		{
			topValues = getTopValues(stk);
			double pushValue = topValues.topSecond / topValues.topFirst;
			stk.push(pushValue);

			continue;
		}

		stk.push(corresponding_num[expression[i] - 'A']);
	}

	double result = stk.top();
	cout << fixed;
	cout.precision(2);
	cout << result;

	return 0;
}

// Ʋ�� ����
	// ������ corresponding_num �迭�� ������� �ʰ� Ǯ���� �ߴ�. 
	// ���� �����Ϳ��� A = 1, B = 2�� ���������� ���ٰ� ������ ������ �迭�� ���� �� �ʿ䰡 ���ٰ� �����ߴµ�,
	// �� ������ Ư�� ���̽������� ������ Ʋ���� ��Ȳ�� ���Դ�.
	// �׷��� A�� ���� 1���� �ٸ� �����Ǵ� ���ڰ� ���� �� �ִٰ� �����Ͽ� �迭�� ���� �����Ͽ� ����ߴ�.