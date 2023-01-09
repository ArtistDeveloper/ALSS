#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

//보석을 고를땐 가격이 1. 높은 보석을 확인하고 2. 가방 중 최대 무게가 가장 작은 가방을 이용
//가방 배열, 보석 배열시 -> NK , 이분탐색으로 가방을 찾는다 ->log K, 하지만 제거가 K , 
//이진검색트리 이용 -> find, erase O(lg k)
#define price first
#define weight second
int n, k;
pair<int, int> j[300001];
multiset<int> beg;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		//가격순으로 정렬하기 위해선 바꿔입력받는게 날듯
		cin >> j[i].weight >> j[i].price;
	}


	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;
		beg.insert(c);
	}

	sort(j, j + n);
	long long ans = 0;
	//가격이 비싼순 부터 가방에 넣어야함.
	for (int i = n-1; i >= 0; i--)
	{
		auto iter = beg.lower_bound(j[i].weight);
		if (iter == beg.end())
			continue;

		ans += j[i].price;
		beg.erase(iter);
	}

	cout << ans;

}