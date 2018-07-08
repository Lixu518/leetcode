#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    if(n == 0)
        return matrix;
    int startRow = 0, startCol = 0;
    int endRow = n - 1, endCol = n - 1;
    int num = 1;
    while(startRow <= endRow && startCol <= endCol){
        for(int i = startCol;i <= endCol;i++)
            matrix[startRow][i] = num++;
        startRow++;
        for(int i = startRow;i <= endRow;i++)
            matrix[i][endCol] = num++;
        endCol--;
        for(int i = endCol;i >= startCol;i--)
            matrix[endRow][i] = num++;
        endRow--;
        for(int i = endRow; i >= startRow;i--)
            matrix[i][startCol] = num++;
        startCol++;
    }
    return matrix;
}

int main(){
    vector<vector<int>>matrix = generateMatrix(10);
    for(int i = 0;i<matrix.size();i++){
        for(int j = 0;j<matrix[0].size();j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}
