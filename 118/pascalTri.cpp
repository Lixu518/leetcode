#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> generate(int numRows){
    vector<vector<int>>res(numRows);
    for(int i = 0;i < numRows;i++){
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;
        for(int j = 1;j < res[i].size();j++)
            res[i][j] = res[i-1][j-1]+res[i-1][j];
    }
    return res;
}

int main(){
    vector<vector<int>> res = generate(6);
    for(auto n : res){
        for(auto c : n)
            cout<<c << " ";
        cout<<endl;
    }
    return 0;
}
