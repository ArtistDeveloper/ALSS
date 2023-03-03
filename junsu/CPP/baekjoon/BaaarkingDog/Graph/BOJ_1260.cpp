// vis 체크하는 것에서 어떤 차이가 발생하는지 알아보기

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, start;
vector<int> adj[1001];
bool vis[1001];

// 비재귀
void dfs1()
{
    stack<int> stk;
    stk.push(start);

    while (!stk.empty())
    {
        int curNode = stk.top(); stk.pop();
        if (vis[curNode]) continue;
        vis[curNode] = true;
        cout << curNode << ' ';

        int singleAdjSize = adj[curNode].size();
        for (int i = 0; i < singleAdjSize; i++)
        {
            int next = adj[curNode][singleAdjSize - 1 - i];
            if (vis[next]) continue;
            stk.push(next);
        }
    }
}

// 재귀사용
void dfs2(int cur)
{
    if (vis[cur]) return;
    vis[cur] = true;
    cout << cur << ' ';
    
    for (int next = 0; next < adj[cur].size(); next++)
    {
        dfs2(adj[cur][next]);
    }
}

// 빠킹독 dfs 재귀 버전
// 결국 base condition위치 차이 밖에 없음.
// 내 코드가 좀 더 비효율 적일 것. 내 코드는 함수가 호출되서 무조건 스택이 쌓이게 되는데, 
// 빠킹독 버전은 방문한 곳은 함수가 호출되지도 않음.
void dfs3(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        dfs2(nxt);
    }
}

void bfs()
{
    queue<int> q;
    q.push(start);
    vis[start] = true;

    while (!q.empty())
    {
        int curNode = q.front(); q.pop();
        cout << curNode << ' ';

        for (int i = 0; i < adj[curNode].size(); i++)
        {
            int next = adj[curNode][i];

            if (vis[next]) continue;
            vis[next] = true;
            q.push(next);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> start;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // 번호가 작은 것 부터 방문하기 위해 정렬
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
    }
        
    //dfs1(); 
    dfs2(start);
    cout << '\n';
    fill(vis + 1, vis + n + 1, false);
    bfs();
}
