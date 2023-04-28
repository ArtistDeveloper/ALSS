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
	//1������, w-1���� ���մϴ�.
	for (int i = 1; i < w - 1; i++)
	{
		//���縦 �������� ������ ���� ū�κ�, �������� ���� ū�κ��� ã�� ���ι��� ���մϴ�.
		int left=0, right=0;

		//������ ���ʺκ� 
		for (int j = 0; j < i; j++)
		{
			left = max(left, v[j]);
		}
		//�����ʺκ�
		for (int j = i + 1; j < w; j++)
		{
			right = max(right, v[j]);
		}
		//���ʰ� ������ �� ���������� �����ϰ� ������ ���̸� ���ϴ�. 
		if (min(left, right) - v[i] < 0)
			continue;
		ans += min(left, right)-v[i];
	}

	cout << ans;
}