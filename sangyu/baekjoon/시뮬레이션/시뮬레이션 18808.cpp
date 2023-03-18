#include<iostream>
#include<vector>
using namespace std;
int n, m, k;

int note[41][41];
int sticker[11][11];
int h, w;

//스티커를 왼쪽상단에 붙일 수 있는지 확인해야합니다.
bool TryAttachSticker(int x,int y)
{
	//붙일 수 있는지 확인합니다.
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

	//스티커를 붙입니다.
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

//직사각형 회전시 h,w도 바꿔야 합니다.
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
		//4번의 회전동안 붙여야합니다.
		for (int rot = 0; rot < 4; rot++)
		{
			//스티커가 붙을 수 없으면 다음 스티커로 넘어갑니다.
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