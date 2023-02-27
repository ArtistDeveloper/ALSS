#include<iostream>

using namespace std;

char star[1025][1025];
void draw(int y,int x,int n)
{
	if (n == 0)
	{
		star[y][x] = '*';
		return;
	}
	int size = 1 << (n - 1);

	draw(y, x, n - 1);
	draw(y, x + size, n - 1);
	draw(y + size, x, n - 1);
}
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < 1 << n; i++)
	{
		for (int j = 0; j < 1 << n; j++)
		{
			star[i][j]=' ';
		}
	}
	draw(0, 0, n);

	int size = 1 <<n;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j <size-i; j++)
		{
			cout <<star[i][j];
		}
		cout <<'\n';
	}
}
