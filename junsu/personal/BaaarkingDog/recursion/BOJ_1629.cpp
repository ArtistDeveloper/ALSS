#include <iostream>

using namespace std;

using ll = long long;

// ��ʹ� ������ �����ϸ� �ȴ�.
// 1. �ڱ� �ڽ��� ȣ������ �ʴ� base condition�� �ʿ��ϴ�.
// 2. base condition���� ������ �� �ֵ��� �ؾ� �Ѵ�.

// 1���� ����� �� �ִ�.
// "k���� ���������" 2k�°� 2k+1�µ� O(1)�� ����� �� �ִ�. (k�±��� ���� ���� O(1)�� �ƴϴ�.)

// ������Ģ : a^(n+m) = a^n * a^m
// ��ⷯ ���� : (a*b) % c = (a%c * b%c) % c

// ��� �Լ��� ���� b�� �������� ��� ������ ���Ѵ�
ll pow(ll a, ll b, ll m)
{
	if (b == 1) return a % m; // base condition // "1���� ����� �� �ִ�."�� ���ǿ� �����Ѵ�.
	
	ll val = pow(a, b / 2, m); // base condition���� �����ϵ��� ����
	
	// ���� ���� ������ b == 1�̶�� base condtion�� ���� �����ϰ�, 
	// val�� ���� ���� �� �Ʒ� �ڵ���� �����

	// "k���� ���������" 2k�°� 2k + 1�µ� O(1)�� ����� �� �ִ�. (k�±��� ���� ���� O(1)�� �ƴϴ�.
	if (b % 2 == 1) return (val * val % m) * a % m; // Ȧ���� ���� �� �� �� ���ؼ� ��ȯ
	return val * val % m;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a, b, mod;
	cin >> a >> b >> mod;

	ll result = pow(a, b, mod);
	cout << result;

	return 0;
}