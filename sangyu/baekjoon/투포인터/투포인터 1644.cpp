#include<iostream>
#include<vector>
using namespace std;

const int minNum = 4000002;
int n;
vector<bool> isPrime(minNum, true);
vector<int> primeNum;
//2초기 때문에 에라토네스 체를 사용해 소수를 판별하고 투포인터를 사용합니다.
int main()
{
	cin >> n;

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= n; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= n; j = j + i)
			{
				isPrime[j] = false;
			}
		}
	}


	for (int i = 2; i <= n+1; i++)
	{
		if (isPrime[i])
			primeNum.push_back(i);
	}

	int ans = 0;
	int st = 0, en = 1 , sum=primeNum[st];

	while (1)
	{
		if (sum == n)
			ans++;

		if (sum <= n)
		{
			sum += primeNum[en];
			en++;
		}

		if (sum > n)
		{
			sum -= primeNum[st];
			st++;
		}
		if (en == primeNum.size())
			break;
	}

	std::cout << ans;
}
