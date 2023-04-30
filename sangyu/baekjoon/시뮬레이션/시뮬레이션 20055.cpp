#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;
int arr[201];
bool hasRobot[201];

int main()
{
	cin >> n >> k;
	
	int len = 2 * n;
	for (int i = 0; i < len; i++)
	{
		cin >> arr[i];
	}


	int ans = 0;
	while (true)
	{	
		int flag = 0;
		for (int i = 0; i < len; i++)
		{
			if (arr[i] <= 0)
				flag++;
		}

		if (flag >= k)
			break;

		ans++;

		//��Ʈ�� ȸ���մϴ�.
		rotate(arr, arr + len - 1, arr + len);
		rotate(hasRobot, hasRobot + len - 1, hasRobot + len);

		if (hasRobot[n - 1])
			hasRobot[n - 1] = false;
		for (int i = len-2; i >=0 ; i--)
		{
			if (hasRobot[i] && (arr[i + 1] > 0) && !hasRobot[i + 1])
			{
				//�κ��� �̵��մϴ�.
				arr[i + 1]--;
				hasRobot[i] = false;
				hasRobot[i + 1] = true;
			}
		}
		if (hasRobot[n - 1])
			hasRobot[n - 1] = false;



		//�κ��� �ø��ϴ�.
		if (arr[0] > 0 && !hasRobot[0])
		{
			arr[0]--;
			hasRobot[0] = true;
		}

	}

	cout << ans;
}