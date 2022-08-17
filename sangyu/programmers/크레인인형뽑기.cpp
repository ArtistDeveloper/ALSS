#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    //0 ºóÄ­
 
    vector<int> basket;
    int anwser = 0;

    for (int i = 0; i < moves.size(); ++i)
    {
        int col = moves[i] - 1;
        for (int j = 0; j < board.size(); ++j)
        {
            if (board[j][col] != 0)
            {
                basket.push_back(board[j][col]);
                board[j][col] = 0;
                
                if (basket.size() >= 2)
                {
                    if (basket[basket.size() - 1] == basket[basket.size() - 2])
                    {
                        anwser += 2;
                        basket.pop_back();
                        basket.pop_back();
                    }
                }
                break;
            }
        }
    }


    return anwser;
} 

int main()
{
    vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };
    vector<int> move = { 1,5,3,5,1,2,1,4 };
    
    cout<<solution(board, move);
}  
