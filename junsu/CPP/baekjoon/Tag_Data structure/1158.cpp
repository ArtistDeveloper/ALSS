// ����Ʋ�� ���� 
// n���� 1�� �־����� ��������� �̻���.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	const int FIRST = 0;
	int LAST;
	
	queue<int> josephusQ;

	cin >> n >> k;

	LAST = n-1;

	// 1. queue�� �ʱ�ȭ
	for (int i = 0; i < n; i++)
	{
		josephusQ.push(i + 1);
	}

	// 2. �˰��� ����
	for (int i = 0; i < n; i++)
	{
		// !! Ʋ�� ���� : ��谪 �ݷ� üũ ����� ������.
		if (n == 1)
		{
			cout << "<1>";
			break;
		}

		// 2.1 K-1�� Ƚ����ŭ dequeue() �� enqueue()����
		for (int j = 0; j < k-1; j++)
		{
			josephusQ.push(josephusQ.front());
			josephusQ.pop();
		}

		// 2.2 k-1�� Ƚ����ŭ �ݺ��� ������ ��� �� dequeue()�� ����
		if (i == FIRST)
		{
			cout << "<" << josephusQ.front() << ", ";
		}
		else if (i == LAST)
		{
			cout << josephusQ.front() << ">";
		}
		else
		{
			cout << josephusQ.front() << ", ";
		}

		josephusQ.pop();
	}

	return 0;
}