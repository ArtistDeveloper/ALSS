#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> cardQ;
	int n;

	cin >> n;
	
	// 1. ť �ʱ�ȭ
	for (int i = 0; i < n; i++)
	{
		cardQ.push(i + 1);
	}

	// 2. ���� ����
	// �ݺ����� ���� 
	// == 1. while(ture)�ɰ� while�ݺ��� �ȿ��� cardQ.size()�� ����� �������� �ݺ��� break�ϱ�. (while���� ��ü�� q.size()�� ���� ������ �ɾ ��.)
	// == 2. for�� ���: n���� �����Ͱ� ť�� �ְ�, �� �ݺ��� �ϳ��� �����Ͱ� pop()�Ǿ� ������� n-1�� �ݺ��ϸ� �����Ͱ� 1���� ���� ���̶� �� ������ �� �ִ�.

	for (int i = 0; i < n - 1; i++)
	{
		cardQ.pop();
		cardQ.push(cardQ.front());
		cardQ.pop();
	}

	cout << cardQ.front();

	return 0;
}