#include <iostream>

using namespace std;

using ll = long long;

// 재귀는 다음을 성립하면 된다.
// 1. 자기 자신을 호출하지 않는 base condition이 필요하다.
// 2. base condition으로 수렴할 수 있도록 해야 한다.

// 1승을 계산할 수 있다.
// "k승을 계산했으면" 2k승과 2k+1승도 O(1)에 계산할 수 있다. (k승까지 구할 때는 O(1)이 아니다.)

// 지수법칙 : a^(n+m) = a^n * a^m
// 모듈러 성질 : (a*b) % c = (a%c * b%c) % c

// 재귀 함수로 지수 b를 절반으로 계속 나눠서 구한다
ll pow(ll a, ll b, ll m)
{
	if (b == 1) return a % m; // base condition // "1승을 계산할 수 있다."의 조건에 부합한다.
	
	ll val = pow(a, b / 2, m); // base condition으로 수렴하도록 만듬
	
	// 제일 깊은 곳에서 b == 1이라는 base condtion을 만나 종료하고, 
	// val에 값을 넣은 뒤 아래 코드들이 수행됨

	// "k승을 계산했으면" 2k승과 2k + 1승도 O(1)에 계산할 수 있다. (k승까지 구할 때는 O(1)이 아니다.
	if (b % 2 == 1) return (val * val % m) * a % m; // 홀수면 값을 한 번 더 곱해서 반환
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