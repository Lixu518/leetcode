#include<iostream>
#include<vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.empty() || (matrix.size() == 0 || matrix[0].size() == 0)) return false;
	int start = 0, end = matrix.size() * matrix[0].size() - 1;
	while(start <= end){
		int mid = (start + end)>>1;
		int i = mid / (matrix[0].size()), j = mid % (matrix[0].size());
		if(matrix[i][j] == target) return true;
		else if (matrix[i][j] < target)
			start = mid + 1;
		else 
			end = mid - 1;
	}
	return false;
}

int main(){
	vector<vector<int>>matrix1 = {
  									{1,   3,  5,  7},
  									{10, 11, 16, 20},
  									{23, 30, 34, 50}
								};
	vector<vector<int>>matrix2 = {
  									{1,   3,  5,  7},
  									{10, 11, 16, 20},
  									{23, 30, 34, 50}
								};
	cout<<"result1:"<<searchMatrix(matrix1, 3)<<endl;
	cout<<"result2:"<<searchMatrix(matrix2, 13)<<endl;
	return 0;
}
