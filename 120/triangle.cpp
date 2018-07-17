#include<iostream>
#include<vector>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle){
    for(int i = triangle.size() - 2;i >= 0;i--){
        for(int j = 0;j <= i;j++){
            triangle[i][j] += min(triangle[i+1][j+1],triangle[i+1][j]);
        }
    }
    return triangle[0][0];
}

int main(){
    vector<vector<int>> triangle = {
         {2},
        {3,4},
       {6,5,7},
      {4,1,8,3}
    };
    cout<<minimumTotal(triangle)<<endl;
    return 0;
}
