#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int h, w;

vector<int> v;

int main()
{
	cin >> h >> w;

	for (int i = 0; i < w; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}

	int ans = 0;
	//1번부터, w-1까지 비교합니다.
	for (int i = 1; i < w - 1; i++)
	{
		//현재를 기준으로 왼쪽의 가장 큰부분, 오른쪽의 가장 큰부분을 찾아 고인물을 구합니다.
		int left=0, right=0;

		//현재의 왼쪽부분 
		for (int j = 0; j < i; j++)
		{
			left = max(left, v[j]);
		}
		//오른쪽부분
		for (int j = i + 1; j < w; j++)
		{
			right = max(right, v[j]);
		}
		//왼쪽과 오른쪽 중 더작은값을 선택하고 현재의 높이를 뺍니다. 
		if (min(left, right) - v[i] < 0)
			continue;
		ans += min(left, right)-v[i];
	}

	cout << ans;
}