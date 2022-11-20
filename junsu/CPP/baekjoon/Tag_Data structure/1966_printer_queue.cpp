#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    int count = 0;
    int importance;
    int docnum;
    int target_location;
   
    cin >> n;

    for (int i = 0; i < n; i++) {
        count = 0;
        cin >> docnum;
        cin >> target_location;

        queue<pair<int,int>> q; 
        priority_queue<int> pq; 

        for (int j = 0; j < docnum; j++){
            cin >> importance;
            q.push({j, importance});
            pq.push(importance);
        }

        while (!q.empty()) {
            int location = q.front().first;
			int value = q.front().second;
			q.pop();

            if (pq.top() == value) {
				pq.pop();
				++count;
				if (target_location == location) {
					cout << count << '\n';
					break;
				}
			}

			else q.push({ location, value });
        }
    }
}
