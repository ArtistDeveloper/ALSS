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

	// ��������
	for (int i = 0; i < n; i++)
	{
		cin >> value;

		// 1. push ����
		// maxValue���� ū ���� �ԷµǸ� "maxValue + 1 <= value"������ ���� �ԷµǾ� �Ѵ�.
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

		// 2. pop ����
		else if (maxValue > value)
		{
			// 2.1 ������ ������� �ʰ�, stack�� top�� ã���� �ϴ� ���� ���� ������ �ݺ��� ����
			
			// �ٸ� �ڵ�� while���� �����ϴ��� �� ��Ī
			while (!stk.empty() && (stk.top() != value)) 
			{
				stk.pop();
				output += "-\n";

				printf("�� ���� �־�� \n");
			}

			// while���� �����ٴ� �� : ������ ����ִ� or stack�� top�� ã���� �ϴ� ���� �ִ�.
			// 2.2 ������ ����ִٴ� ���� ã���� �ϴ� ���� ���� ���̴�.
			if (stk.empty())
			{
				output = "NO";
				cout << output;
				exit(0);
			}

			// stack�� ������� �ʰ�, ���ÿ� ã���� �ϴ� ���� ������ ����
			// 2.3 ������ top�� ã���� �ϴ� ���� ������ pop()����
			if (stk.top() == value)
			{
				stk.pop();
				output += "-\n";
			}
		}

		// (maxvalue == value)�� �Ͼ�� �ʴ� �����̴�. ������ �Է¿��� ���� ������ 2�� ������ ��찡 ���ٰ� �߱� �����̴�.
	}

	cout << output;

	return 0;
}