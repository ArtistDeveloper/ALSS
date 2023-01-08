#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

//������ ���� ������ 1. ���� ������ Ȯ���ϰ� 2. ���� �� �ִ� ���԰� ���� ���� ������ �̿�
//���� �迭, ���� �迭�� -> NK , �̺�Ž������ ������ ã�´� ->log K, ������ ���Ű� K , 
//�����˻�Ʈ�� �̿� -> find, erase O(lg k)
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
		//���ݼ����� �����ϱ� ���ؼ� �ٲ��Է¹޴°� ����
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
	//������ ��Ѽ� ���� ���濡 �־����.
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