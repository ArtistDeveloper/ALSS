#include <iostream>
#include <stack>

#define NODE_COUNT 6

using namespace std;

void dfs_recursion(int adj[][NODE_COUNT], int now, bool visited[])
{
	printf("%d\n", now);
	visited[now] = true;

	for (int next = 0; next < NODE_COUNT; next++)
	{
		if (adj[now][next] == 0)
			continue;
		if (visited[next]) // 다음에 방문할 곳이 이미 방문했던 곳이라면 continue.
			continue;
		dfs_recursion(adj, next, visited);
	}
}

void dfs_stack(int adj[][NODE_COUNT], int now, bool visited[])
{
	stack<int> stk;
	stk.push(now);
	visited[now] = true;
	
	cout << stk.top() << endl;

	while (!stk.empty())
	{
		int top = stk.top();
		bool pop_flag = true;

		for (int next = 0; next < NODE_COUNT; next++)
		{
			if (adj[top][next] == 0)
				continue;
			if (visited[next])
				continue;
			
			stk.push(next);
			cout << stk.top() << endl;
			visited[next] = true;
			pop_flag = false;

			break;
		}

		// 반복문을 다 돌았다면, 기준노드와 관련된 곳을 모두 탐색했다는 뜻이므로 pop을 해준다.
		if (pop_flag)
		{
			stk.pop();
		}
	}
}

int main()
{
	int adj[NODE_COUNT][NODE_COUNT] =
	{
		{ 0, 1, 0, 1, 0, 0 },
		{ 1, 0, 1, 1, 0, 0 },
		{ 0, 1, 0, 0, 0, 0 },
		{ 1, 1, 0, 0, 1, 0 },
		{ 0, 0, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0 },
	};

	bool visited[NODE_COUNT] = { false, };
	int start_node = 0;

	//dfs_recursion(adj, start_node, visited);

	//visited[NODE_COUNT] = { false, };
	dfs_stack(adj, start_node, visited);

	return 0;
}