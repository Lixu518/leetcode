#include<vector>
#include<iostream>
using namespace std;
class NumMatrix{
    private:
        int row, col;
        vector<vector<int>> sum;
    public:
        NumMatrix(const vector<vector<int>> matrix){
            row = matrix.size();
            col = row > 0 ? matrix[0].size() : 0;
            sum = vector<vector<int>>(row+1, vector<int>(col+1, 0));
            for(int i = 1; i <= row; ++i){
                for(int j = 1;j <= col; ++j){
                    sum[i][j] = matrix[i-1][j-1] + sum[i-1][j] + sum[i][j-1] -
                        sum[i-1][j-1];
                }
            }
        }

        int sumRange(int row1, int col1, int row2, int col2){
            return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] +
                sum[row1][col1];
        }   
};

int main(){
    vector<vector<int>> matrix = {
                  {3, 0, 1, 4, 2},
                  {5, 6, 3, 2, 1},
                  {1, 2, 0, 1, 5},
                  {4, 1, 0, 1, 7},
                  {1, 0, 3, 0, 5}
                };
    NumMatrix nm(matrix);
    int res = nm.sumRange(1,1,2,2);
    cout<<res<<endl;
}


