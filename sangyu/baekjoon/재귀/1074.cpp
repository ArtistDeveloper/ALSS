#include<iostream>
#include<cmath>
using namespace std;


int recusion(int n, int r, int c)
{
	if (n == 0)
		return 0;

	int half = 1<<(n-1);

	//1번 영역
	if (r < half && c < half)
		return recusion(n - 1, r, c);
	//2번 영역
	if (r < half && c >= half)
		return half * half + recusion(n - 1, r, c - half);
	//3번 영역
	if (r >= half && c < half)
		return 2*half*half + recusion(n - 1, r - half, c);
	//4번 영역
	return 3 * half * half + recusion(n - 1, r - half, c - half);
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(0);
	int n, r, c;
	cin >> n >> r >> c;

	cout<< recusion(n, r, c);
}