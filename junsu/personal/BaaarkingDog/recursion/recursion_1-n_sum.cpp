#include <iostream>

using namespace std;

/// n���� 1���� ����ϴ� �Լ�
// print(1)�� 1�� ��µ� ���� �ڸ��ϴ�.
// print(k)�� k, k-1, k-2 ... 1�� ����ϸ� print(k+1)�� k+1, k, k-1 .. 1�� ����Ѵ�.
// k+1ȣ�� -> print(k) ȣ�� = k, k-1, k-2 ... 1���
// k+1ȣ���� ���� k+1�� ��µǴ� ���� �ڸ��ϴ�.
// k+1ȣ���� ���� print(k)�� ȣ��ȴ�. print(k)�� ���� ������ �����ִ� �״���̴�.
// ��, k+1���� 1���� ��µȴٴ� ����� �ڸ��ϴ�.
void print(int n)
{
	if (n == 0) return;
	cout << n << ' ';
	print(n - 1);
	// cout << n << ' '; // ���� ������ 1, 2, 3���
}


/// 1���� n������ ���� ���ϴ� �Լ�
// n�� 0�� �� 0�� �����شٴ� ���� �ڸ��ϴ�.
// n + sum(n-1)���� n�� 5��� 5 + 4�� �� ���� �ڸ��ϴ�.
// �׷��� �װ� �ݺ��Ǿ� ���� 1���� ������ ���� �ڸ��ϴ�.
// �׷� ��������� n���� 1������ ������ ����� ����� ���̴�.
int sum(int n)
{
	if (n == 0) return 0;
	return n + sum(n - 1);
}

int main()
{
	cout << sum(5) << '\n';
	print(3);

	return 0;
}