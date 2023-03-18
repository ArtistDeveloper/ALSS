#include<iostream>
#include<vector>
using namespace std;
int n, m, k;

int note[41][41];
int sticker[11][11];
int h, w;

//��ƼĿ�� ���ʻ�ܿ� ���� �� �ִ��� Ȯ���ؾ��մϴ�.
bool TryAttachSticker(int x,int y)
{
	//���� �� �ִ��� Ȯ���մϴ�.
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (note[x + i][y + j] == 1 && sticker[i][j] == 1)
			{
				return false;
			}
		}
	}

	//��ƼĿ�� ���Դϴ�.
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (sticker[i][j] == 1)
			{
				note[x + i][y + j] = 1;
			}
		}
	}
	return true;
}

//���簢�� ȸ���� h,w�� �ٲ�� �մϴ�.
void RotateSticker()
{
	int tempArr[11][11];
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			tempArr[j][h-i-1] = sticker[i][j];
		}
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			sticker[i][j] = tempArr[i][j];
		}
	}

	int temp = h;
	h = w;
	w = temp;
	
}

int main()
{
	cin >> n >> m >> k;

	for (int tc = 0; tc < k; tc++)
	{
		cin >> h >> w;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> sticker[i][j];
			}
		}
		//4���� ȸ������ �ٿ����մϴ�.
		for (int rot = 0; rot < 4; rot++)
		{
			//��ƼĿ�� ���� �� ������ ���� ��ƼĿ�� �Ѿ�ϴ�.
			bool isAttached = false;
			for (int i = 0; i <= n - h; i++)
			{
				if (isAttached)
				{
					break;
				}
				
				for (int j = 0; j <= m - w; j++)
				{
					if (TryAttachSticker(i, j))
					{
						isAttached = true;
						break;
					}
				}
			}
			
			if (isAttached)
				break;
			RotateSticker();
		}

	}

	int ans=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (note[i][j] ==1)
				ans++;
		}
	}

	cout << ans;
}