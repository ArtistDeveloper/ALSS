#include<vector>
#include<iostream>
#include<queue>
#include<vector>
#include<queue>
using namespace std;

int vis[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int solution(vector<vector<int> > maps)
{
    int x = maps[0].size() - 1;
    int y = maps.size() - 1;

    if (maps[y - 1][x] == 0 && maps[y][x - 1] == 0)
        return -1;

    //√ ±‚»≠
    for (int i = 0; i < maps[0].size(); i++)
    {
        for (int j = 0; j < maps.size(); j++)
        {
            vis[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    q.push({ 0,0 });
    vis[0][0] = 1;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if (nx > x || ny > y || nx < 0 || ny < 0)
                continue;
            if (vis[ny][nx] != -1 || maps[ny][nx] == 0)
                continue;

            q.push({ ny,nx });
            vis[ny][nx] = vis[cur.first][cur.second] + 1;
        }
    }


    return vis[y][x];
}

int main()
{

    vector<vector<int>> map;
    map.push_back({ 1,0,1,1,1 });
    map.push_back({ 1,0,1,0,1 });
    map.push_back({ 1,0,1,1,1 });
    map.push_back({ 1,1,1,0,1 });
    map.push_back({ 0,0,0,0,1 });

    cout << solution(map);
}