#include<iostream>
#include<vector>
using namespace std;

void check(vector<vector<char>>& board, int i, int j){
    if(board[i][j] == 'O'){
        board[i][j] = '1';
        if(i > 1)check(board, i - 1, j);
        if(j > 1)check(board, i, j - 1);
        if(i < board.size() - 1)check(board, i + 1, j);
        if(j < board[0].size() - 1)check(board, i, j + 1);
    }
}

void solve(vector<vector<char>>& board) {
    if(board.empty()) return ;
    int row = board.size(), col = board[0].size();
    for(int i = 0;i < row;i++){
        check(board, i, 0);
        check(board, i, col - 1);
    }
    for(int j = 1;j < col;j++){
        check(board, 0, j);
        check(board, row - 1, j);
    }
    for(int i = 0;i < row;i++){
        for(int j = 0;j < col;j++){
            if(board[i][j] == 'O') board[i][j] = 'X';
            else if (board[i][j] == '1') board[i][j] = 'O';
        }
    }
}

int main(){
    vector<vector<char> > board = {{'X','X','X','X'},
                                {'X','O','O','X'},
                                {'X','X','O','X'},
                                {'X','O','X','X'}};
    solve(board);
    for(auto row:board){
        for(auto ch : row)
            cout<<ch<<" ";
        cout<<endl;
    }
    return 0;
}
