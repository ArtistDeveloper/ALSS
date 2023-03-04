#include<iostream>

using namespace std;

int n, s;
int arr[23];
bool issue[23];
int cnt = 0;
void fuc(int idx,int sum)
{
	//idx가 n이라면 return합니다. 이때 조건에 만족하면 cnt를 증가시킵니다.
	if (idx == n)
	{
		if (sum == s)
		{
			cnt++;
		}
		return;
	}
	
	//두가지 상태로 분기합니다 - 집합을 더했을때, 더하지 않았을때.
	fuc(idx + 1, sum);
	fuc(idx + 1,sum+arr[idx]);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;


	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	fuc(0,0);
	if (s == 0) cnt--;
	cout << cnt;
}