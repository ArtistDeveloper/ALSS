#include<iostream>
#include<vector>
using namespace std;

int r, c, t,upx,downx,total;
int map[51][51];
int check[51][51];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool bCanSpread[1001][1001];
//확산이 일어나는곳과 일어나지 않는곳을 정해야합니다.
void spread(int x, int y)
{
    //(r,c)에 있는 미세먼지가 인접 4방향으로 확산됩니다.
    //확산할 수 있는 방향에 대해 탐색한 후, 확산해야합니다.
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

    //확산할 수 있는 방향이 없다면 return 합니다.
    if (spreadAble == 0)
        return;

    //확산하는 양을 구하고,확산합니다. 이때 확산된 정보를 저장할 배열이 따로 필요하네
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
        //0인 부분은 현재 시간에서 확산이 일어나면 안됩니다.
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (map[i][j] != 0)
                    bCanSpread[i][j] = true;
            }
        }

        //미세먼지의 확산이 먼저 일어납니다.
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

        //맵에 옮기고 초기화
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                map[i][j] = check[i][j];
                check[i][j] = 0;
            }
        }

        //공기청정기가 작동합니다. 이때 공기청정기로 다시 들어간다면 미세먼지가 정화됨.
        total -= map[upx - 1][0];
        total -= map[downx + 1][0];



       // 위쪽은 반시계 방향으로 순환합니다.
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
        //아래쪽은 시계 방향으로 순환합니다.

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