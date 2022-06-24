#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int maxValue = 0;
	stack<int> stk;
	string output = "";
	int n, value;

	cin >> n;

	// 로직수행
	for (int i = 0; i < n; i++)
	{
		cin >> value;

		// 1. push 연산
		// maxValue보다 큰 값이 입력되면 "maxValue + 1 <= value"까지의 값이 입력되야 한다.
		if (maxValue < value)
		{
			for (int j = maxValue + 1; j <= value; j++)
			{
				stk.push(j);
				output += "+\n";
			}

			stk.pop();
			output += "-\n";
			maxValue = value;
		}

		// 2. pop 연산
		else if (maxValue > value)
		{
			// 2.1 스택이 비어있지 않고, stack의 top이 찾고자 하는 값과 같지 않으면 반복문 수행
			
			// 다른 코드는 while문을 사용안하던데 왜 글칭
			while (!stk.empty() && (stk.top() != value)) 
			{
				stk.pop();
				output += "-\n";

				printf("저 여기 있어요 \n");
			}

			// while문이 끝났다는 뜻 : 스택이 비어있다 or stack의 top에 찾고자 하는 값이 있다.
			// 2.2 스택이 비어있다는 것은 찾고자 하는 값이 없는 것이다.
			if (stk.empty())
			{
				output = "NO";
				cout << output;
				exit(0);
			}

			// stack이 비어있지 않고, 스택에 찾고자 하는 값이 있으면 수행
			// 2.3 스택의 top과 찾고자 하는 값이 같으면 pop()수행
			if (stk.top() == value)
			{
				stk.pop();
				output += "-\n";
			}
		}

		// (maxvalue == value)는 일어나지 않는 조건이다. 문제의 입력에서 같은 정수가 2번 나오는 경우가 없다고 했기 때문이다.
	}

	cout << output;

	return 0;
}