#include<iostream>
#include<algorithm>
int n, m;
int input[10];
int arr[10];
bool issue[10005]; //�湮 üũ
void func(int cur)
{
	if (cur == m)
	{
		for (int i = 0; i < m; i++)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
		return;
	}

	//������ �� ���� ����ȵ�.
	int check=0;
	for (int i = 0; i < n; i++)
	{
		if (!issue[i] && check!=input[i])
		{
			arr[cur] = input[i];
			check = input[i];
			issue[i] = 1;
			func(cur + 1);
			
			issue[i] = 0;
		}
	}

}

int main()
{
	std::cin.tie(0); std::ios_base::sync_with_stdio(0);
	std::cin >> n>>m;
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> input[i];
	}
	std::sort(input, input + n);

	func(0);
}