#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
	if(grid.empty() || grid.size() == 0 || grid[0].size() == 0)
		return 0;
	int m = grid.size(), n = grid[0].size();
	vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
	dp[0][0] = grid[0][0];
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			if(i == 0 && j > 0)
				dp[i][j] = dp[i][j-1] + grid[i][j];
			else if(i > 0 && j == 0)
				dp[i][j] = dp[i-1][j] + grid[i][j];
			else if(i > 0 && j > 0){
				dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
			}
		}
	}
	return dp[m-1][n-1];
}

int main(){
	vector<vector<int>> grid = {
	  {1,3,1},
	  {1,5,1},
	  {4,2,1}
	};
	cout<<"minPathSum:"<<minPathSum(grid)<<endl;
	return 0;
}
