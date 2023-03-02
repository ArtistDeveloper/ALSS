#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef struct _TopValues
{
	double topFirst; // 첫 번째로 뺀 top의 값
	double topSecond; // 두 번째로 뺀 top의 값
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

	cin >> n; // 피연산자의 개수 입력
	cin >> expression; // 후위 표기식 입력, 후위 표기식의 길이는 100을 넘지 않는다.

	int corresponding_num[26];
	
	// 피연산자에 대응하는 값 넣기, 피연산자는 A ~ Z의 개수 즉, 26개가 쓰인다.
	for (int i = 0; i < n; i++)
	{
		cin >> corresponding_num[i];
	}

	// 스택을 통한 후위표기식 연산
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

// 틀린 이유
	// 원래는 corresponding_num 배열을 사용하지 않고 풀려고 했다. 
	// 예제 데이터에서 A = 1, B = 2가 고정적으로 들어간다고 보였기 때문에 배열을 굳이 쓸 필요가 없다고 생각했는데,
	// 이 때문에 특정 케이스에서는 맞지만 틀리는 상황이 나왔다.
	// 그래서 A에 값이 1말고도 다른 대응되는 숫자가 들어올 수 있다고 생각하여 배열에 값을 저장하여 사용했다.