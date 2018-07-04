#include <iostream>
#include <vector>
using namespace std;
int uniquePath(vector<vector<int>>& obstacleGrid){
    if(obstacleGrid.empty() || obstacleGrid.size() == 0)
        return 0;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    dp[0][0] = 1;
    for(int i = 0;i < obstacleGrid.size();i++){
        for(int j = 0;j < obstacleGrid[0].size();j++){
            if(i == 0 || j == 0)
                dp[i][j] = 1;
            else if(obstacleGrid[i][j] == 1)
                dp[i][j] == 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main(){
    vector<vector<int>>obstacleGrid = {{0,0,0,0},
                                        {0,1,1,0},
                                        {0,1,0,0}};
    cout<<uniquePath(obstacleGrid)<<endl;
    return 0;
}
