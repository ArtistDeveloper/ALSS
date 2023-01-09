#include<iostream>
#include<algorithm>

int n,m;
int arr[100001];
int target[100001];

int binarysearch(int target)
{
	int st = 0;
	int en = n - 1;

	while (st <= en)
	{
		int mid = (st + en) / 2;

		if (arr[mid] < target)
		{
			st = mid + 1;
		}
		else if (arr[mid] > target)
		{
			en = mid - 1;
		}
		else
			return 1;
	}
	return 0;
}

int main()
{
	using namespace std;
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> m;

	sort(arr, arr + n); // nlogn

	while (m--)
	{
		int target;
		cin >> target;
		//cout << binarysearch(target)<<'\n';
		cout << binary_search(arr, arr + n, target)<<'\n';
	}


}