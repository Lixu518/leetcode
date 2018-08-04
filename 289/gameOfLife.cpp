#include<iostream>
#include<vector>
using namespace std;
void gameOfLife(vector<vector<int>>& board) {
	int m = board.size(), n = board[0].size();
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			int lives = 0;
			if(i > 0){
				lives += (board[i-1][j] == 1 || board[i-1][j] == 2)?1:0;
			}
			if(j > 0){
				lives += (board[i][j-1] == 1 || board[i][j-1] == 2)?1:0;
			}
			if(i < m-1){
				lives += (board[i+1][j] == 1 || board[i+1][j] == 2)?1:0;
			}
			if(j < n-1){
				lives += (board[i][j+1] == 1 || board[i][j+1] == 2)?1:0;
			}
			if(i > 0 && j > 0){
				lives += (board[i-1][j-1] == 1 || board[i-1][j-1] == 2)?1:0;
			}
			if(i < m-1 && j < n-1){
				lives += (board[i+1][j+1] == 1 || board[i+1][j+1] == 2)?1:0;
			}
			if(i > 0 && j < n-1){
				lives += (board[i-1][j+1] == 1 || board[i-1][j+1] == 2)?1:0;
			}
			if(i < m-1 && j > 0){
				lives += (board[i+1][j-1] == 1 || board[i+1][j-1] == 2)?1:0;
			}
			if(board[i][j] == 0 && lives == 3){
				board[i][j] = 3;
			}
			else if(board[i][j] == 1){
				if(lives < 2 || lives > 3)
					board[i][j] = 2;
			}
		}
	}
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			board[i][j] %= 2;
		}
	}
}

int main(){
	vector<vector<int>> board = {{0,1,0},
  								{0,0,1},
  								{1,1,1},
  								{0,0,0}};
	gameOfLife(board);
	for(auto row : board){
		for(auto state: row)
			cout<<state<<" ";
		cout<<endl;
	}
	return 0;
}
