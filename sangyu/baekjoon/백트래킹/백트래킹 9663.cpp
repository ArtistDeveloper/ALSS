#include<iostream>

//���� �࿡�� ���� ���� ����.
//���� ������ ���� �� �� ����.
//�밢���� x+y, x+y-n-1�� �����Ҽ��ִ�.
using namespace std;
int n;
int cnt = 0;

bool i1[30]; // y�࿡ ���� ������ �ߴ���
bool i2[30]; // ���� �Ʒ����� ������ ���� ���ϴ� �밢���� ���� ������ �ߴ���
bool i3[30]; // ������ ������ ���� �Ʒ��� ���ϴ� �밢���� ���� ������ �ߴ���

void back(int cur)
{
	//�ǿ� �ö� ���� ������ n����� ����� ���� ������ŵ�ϴ�.
	if (cur == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (i1[i] || i2[cur+i] || i3[cur - i + n - 1])
			continue;
		i1[i] = true;
		i2[cur + i] = true;
		i3[cur - i + n - 1] = true;

		back(cur+1);

		//i�� ���� ��츦 �ٸ� ��쿡�� ����ϱ� ���� false�� �ٲ��ݴϴ�.
		i1[i] = false;
		i2[cur + i] = false;
		i3[cur - i + n - 1] = false;

	}
}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n;
	back(0);

	cout << cnt;
}