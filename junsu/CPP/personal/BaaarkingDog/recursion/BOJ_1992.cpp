#include <iostream>
#include <string>

using namespace std;

char board[64][64];

// 지정된 영역에서 다른 것이 있는지 판별하는 함수
// 여기서 다른 부분이 있으면 분할해서 다시 탐색
void judge(int row, int col, int n)
{
    char criteria = board[row][col];
    
    for (int i = row; i < row + n; i++) {
        for (int j = col; j < col + n; j++) {
            if (criteria != board[i][j]){
                cout << "(";
                judge(row, col, n/2);
                judge(row, col + n/2, n/2);
                judge(row + n/2, col, n/2);
                judge(row + n/2, col + n/2, n/2);
                cout << ")";
                return;
            }   
        }
    }

    cout << criteria;
}

int main()
{
    int n;
    char temp;
    
    // 1. 입력
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> temp;
            board[i][j] = temp;
        }
    }

    // 2.로직 수행
    judge(0, 0, n);
    
    return 0;
}
