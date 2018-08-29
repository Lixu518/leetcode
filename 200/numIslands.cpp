#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
    if(i < 0||j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] != '1'
            || visited[i][j]) return;
    visited[i][j] = true;
    dfs(grid, visited, i - 1, j);
    dfs(grid, visited, i + 1, j);
    dfs(grid, visited, i, j - 1);
    dfs(grid, visited, i, j + 1);
}

int numIsland(vector<vector<char>> & grid){
    if (grid.empty()) return 0;
    int m = grid.size(),  n = grid[0].size(), res = 0;
    vector<vector<bool>>visited(m, vector<bool>(n, false));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                dfs(grid, visited, i, j);
                res++;
            }
        }
    }
    return res;
}

int main(){
    vector<vector<char>> res ={{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}};
    cout<<numIsland(res)<<endl;
    return 0;
}
