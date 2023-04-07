#include<iostream>
#include<vector>
using namespace std;

int r, c, t,upx,downx,total;
int map[51][51];
int check[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool bCanSpread[1001][1001];
//Ȯ���� �Ͼ�°��� �Ͼ�� �ʴ°��� ���ؾ��մϴ�.
void spread(int x, int y)
{
    //(r,c)�� �ִ� �̼������� ���� 4�������� Ȯ��˴ϴ�.
    //Ȯ���� �� �ִ� ���⿡ ���� Ž���� ��, Ȯ���ؾ��մϴ�.
    vector<pair<int, int>> np;
    int spreadAble = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c)
            continue;
        if (map[nx][ny] == -1)
            continue;

        np.push_back({ nx,ny });
        spreadAble++;
    }

    //Ȯ���� �� �ִ� ������ ���ٸ� return �մϴ�.
    if (spreadAble == 0)
        return;

    //Ȯ���ϴ� ���� ���ϰ�,Ȯ���մϴ�. �̶� Ȯ��� ������ ������ �迭�� ���� �ʿ��ϳ�
    int spreadNum = floor(map[x][y] / 5);
    map[x][y] -= spreadNum * spreadAble;
    check[x][y] += map[x][y];
    for (int i = 0; i < spreadAble; i++)
    {
        check[np[i].first][np[i].second] += spreadNum;
    }

    

}

int main()
{
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if(map[i][j]==-1)
                downx = i;
            else if (map[i][j] != 0 &&map[i][j] != -1)
            {
                total += map[i][j];
            }

        }
    }
    upx = downx - 1;


    while (t--)
    {
        //0�� �κ��� ���� �ð����� Ȯ���� �Ͼ�� �ȵ˴ϴ�.
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (map[i][j] != 0)
                    bCanSpread[i][j] = true;
            }
        }

        //�̼������� Ȯ���� ���� �Ͼ�ϴ�.
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (map[i][j] != 0)
                {
                    if (bCanSpread[i][j])
                        spread(i, j);
                }
            }
        }

        //�ʿ� �ű�� �ʱ�ȭ
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                map[i][j] = check[i][j];
                check[i][j] = 0;
            }
        }

        //����û���Ⱑ �۵��մϴ�. �̶� ����û����� �ٽ� ���ٸ� �̼������� ��ȭ��.
        total -= map[upx - 1][0];
        total -= map[downx + 1][0];



       // ������ �ݽð� �������� ��ȯ�մϴ�.
        for (int i = upx - 1; i > 0; i--)
        {
            map[i][0] = map[i - 1][0];
        }

        for (int i = 0; i < c - 1; i++)
        {
            map[0][i] = map[0][i + 1];
        }

        for (int i = 1; i <= upx; i++)
        {
            map[i - 1][c - 1] = map[i][c - 1];
        }

        for (int i = c - 1; i > 1; i--)
        {
            map[upx][i] = map[upx][i - 1];
        }
        map[upx][1] = 0;
        //�Ʒ����� �ð� �������� ��ȯ�մϴ�.

        for (int i = downx + 1; i < r - 1; i++)
        {
            map[i][0] = map[i + 1][0];
        }
        
        for (int i = 0; i < c - 1; i++)
        {
            map[r - 1][i] = map[r - 1][i + 1];
        }
        
        for (int i = r - 1; i >= downx; i--)
        {
            map[i][c - 1] = map[i - 1][c - 1];
        }
     
        for (int i = c - 1; i > 1; i--)
        {
            map[downx][i] = map[downx][i - 1];
        }
        map[downx][1] = 0;
    }

    cout << total << endl;
}