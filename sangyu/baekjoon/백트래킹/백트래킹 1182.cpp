#include<iostream>

using namespace std;

int n, s;
int arr[23];
bool issue[23];
int cnt = 0;
void fuc(int idx,int sum)
{
	//idx�� n�̶�� return�մϴ�. �̶� ���ǿ� �����ϸ� cnt�� ������ŵ�ϴ�.
	if (idx == n)
	{
		if (sum == s)
		{
			cnt++;
		}
		return;
	}
	
	//�ΰ��� ���·� �б��մϴ� - ������ ��������, ������ �ʾ�����.
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