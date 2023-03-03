#include<iostream>

using namespace std;

int n, m;
int arr[10];
bool visit[10];

void recursion(int k)
{
	//m이 3이라면
	//1->2->3을 고르면 , 다시 1->2->에서 4를 고르게됩니다.
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	
	//n까지 수에 대해 수를 정합니다.
	//사용된 수 인지 확인하고, 사용이 된 후, 모든 경우에 대해 확인했다면 다시 사용하지 않았다고 표기해줍니다.
	for (int i = 1; i <= n; i++) //1~n에 대해
	{
		if (!visit[i]) // i가 사용되지 않았다면
		{
			arr[k] = i; //k번째 수를 i로 지정해줍니다.
			visit[i] = true; //i가 사용됬다 표기를 한 후
			recursion(k + 1);//재귀적으로 다음으로 올 수를 구하게됩니다.
			visit[i] = false;//i에 대한 경우의 수를 다 확인했으니, 다음 i에 대해 확안하기 위해 다시 방문표시를 false해줍니다. ex) (1,2) -> (2,1) 
		}
			}
	
}

int main()
{
	cin >> n >> m;

	recursion(0);

}
