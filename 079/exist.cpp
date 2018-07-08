#include <iostream>
#include <vector>
using namespace std;

bool has(vector<vector<char>>& board, string word, int i, int j, int pos){                                                                     
    if(pos == word.size()) return true;
    if(i < 0 || j < 0 || i == board.size() || j == board[i].size())
        return false;
    if(board[i][j] != word[pos]) return false;
    char tmp = board[i][j];
    board[i][j] = '#';
    if(has(board, word, i - 1, j, pos + 1) || has(board, word, i + 1, j, pos + 1) || 
       has(board, word, i, j - 1, pos + 1) || has(board, word, i, j + 1, pos + 1))
        return true;
    board[i][j] = tmp;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
	if(board.empty() || board.size() == 0 || board[0].size() == 0 || word.size() == 0)
		return false;
	for(int i = 0;i < board.size();i++)
		for(int j = 0;j < board[0].size();j++)
			if(has(board, word, i, j, 0))
				return true;
	return false;
}

int main(){
	vector<vector<char>> board = {
  								{'A','B','C','E'},
  								{'S','F','C','S'},
  								{'A','D','E','E'}
								};
	cout<<"exist?"<<exist(board, "SEE");
	return 0;
}
