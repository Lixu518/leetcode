#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<int>&nums, vector<vector<int>>&res, vector<int>&tmp, int pos){
    res.push_back(tmp);
    for(int i = pos;i < nums.size();i++){
        if(i == pos || nums[i] != nums[i-1]){
            tmp.push_back(nums[i]);
            dfs(nums, res, tmp, i + 1);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums){
    vector<vector<int>>res;
    vector<int>tmp;
    dfs(nums, res, tmp, 0);
    return res;
}

int main(){
    vector<int>nums = {1,2,2};
    vector<vector<int>>res = subsetsWithDup(nums);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++)
            cout<<res[i][j];
        cout<<endl;
    }
    return 0;
}
