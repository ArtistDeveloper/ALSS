#include<iostream>

using namespace std;

int n, m;
int arr[10];
bool visit[10];

void recursion(int k)
{
	//m�� 3�̶��
	//1->2->3�� ���� , �ٽ� 1->2->���� 4�� ���Ե˴ϴ�.
	if (k == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	
	//n���� ���� ���� ���� ���մϴ�.
	//���� �� ���� Ȯ���ϰ�, ����� �� ��, ��� ��쿡 ���� Ȯ���ߴٸ� �ٽ� ������� �ʾҴٰ� ǥ�����ݴϴ�.
	for (int i = 1; i <= n; i++) //1~n�� ����
	{
		if (!visit[i]) // i�� ������ �ʾҴٸ�
		{
			arr[k] = i; //k��° ���� i�� �������ݴϴ�.
			visit[i] = true; //i�� ����� ǥ�⸦ �� ��
			recursion(k + 1);//��������� �������� �� ���� ���ϰԵ˴ϴ�.
			visit[i] = false;//i�� ���� ����� ���� �� Ȯ��������, ���� i�� ���� Ȯ���ϱ� ���� �ٽ� �湮ǥ�ø� false���ݴϴ�. ex) (1,2) -> (2,1) 
		}
			}
	
}

int main()
{
	cin >> n >> m;

	recursion(0);

}
