#include<iostream>
#include<algorithm>

using namespace std;
int n,m;
int arr[100001];
int minN = 2000000001;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    sort(arr, arr + n);

    int en = 0;
    for (int st = 0; st < n; st++)
    {
        while (en < n && arr[en] - arr[st] < m) en++;
        if (en == n) break; 
        minN = min(minN, arr[en] - arr[st]);
    }
    cout << minN;
}
//n - 100000  -> O(N^2)은 안됨. 
//i-j >=m 을 만족하는 작은수. -> i>=m+j가 최소가 되는값 구한 후 i-j를 구함  
//i>=m+j
//using namespace std;
//int n, m;
//int a[100001];
//int num = 2000000001;
//
//int main()
//{
//	cin.tie(0); ios_base::sync_with_stdio(0);
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a, a + n);
//
//	
//	for (int i = 0; i < n; i++)
//	{
//		int idx = lower_bound(a, a + n, m + a[i]) - a; //m+j 가 최소가 되는 인덱스
//
//		if (idx < n)   
//		{
//			if (num > a[idx] - a[i]) //5>=3+1 , -> 5-1>=3 을 만족시켜야함. 
//				num = a[idx] - a[i];
//		}
//	}
//	cout << num;
//}