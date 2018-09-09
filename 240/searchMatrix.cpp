#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0)return false;
	int row = matrix.size() - 1, col = 0;
	while(row >= 0 && col < matrix[0].size()){
		if (matrix[row][col] == target)return true;
		else if(matrix[row][col] > target) row--;
		else col++;
		if (row < 0 || col >= matrix[0].size())break;
	}
	return false;
}

int main(){
	vector<vector<int>> matrix = {
			  {1,   4,  7, 11, 15},
			  {2,   5,  8, 12, 19},
			  {3,   6,  9, 16, 22},
			  {10, 13, 14, 17, 24},
			  {18, 21, 23, 26, 30}
			};
    cout<<searchMatrix(matrix, 20)<<endl;
	return 0;
}
