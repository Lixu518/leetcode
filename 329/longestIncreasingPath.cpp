#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j){
    if(dp[i][j]) return dp[i][j];
    int mx = 1, m = matrix.size(), n = matrix[0].size();
    for(auto a:dir){
        int x = i + a[0], y = j + a[1];
        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
        int len = 1 + dfs(matrix, dp, x, y);
        mx = max(mx, len);
    }
    dp[i][j] = mx;
    return mx;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    int res = 1, m = matrix.size(), n = matrix[0].size();
    vector<vector<int>>dp(m, vector<int>(n, 0));
    for(int i = 0;i < m;++i){
        for(int j = 0;j < n;++j){
            res = max(res, dfs(matrix, dp, i, j));
        }
    }
    return res;
}

int main(){
    vector<vector<int>> matrix = {{9, 9, 4}, {6, 6, 8}, {2, 2, 1}};
    cout<<longestIncreasingPath(matrix)<<endl;
    return 0;
}

