#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int subarraySum(vector<int>&nums, int k){
    if(nums.empty() || nums.size() == 0) return 0;
    int sum = 0, res = 0;
    unordered_map<int, int>mp{{0,1}};
    for(int i = 0;i < nums.size();i++){
        sum += nums[i];
        res += mp[sum-k];
        mp[sum]++;
    }
    return res;
}

int main(){
    vector<int>nums = {1,2,3,3,4,5,1,2};
    cout<<"res:"<<subarraySum(nums, 7)<<endl;
    return 0;
}
