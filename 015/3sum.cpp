#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>&nums){
    vector<vector<int>>res;
    if(nums.empty()|| nums.size()<3) return res;
    sort(nums.begin(), nums.end());
    for(int i = 0;i<nums.size()-2;i++){
        int target = -nums[i];
        int left = i + 1, right = nums.size()-1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum < target) left++;
            else if(sum > target) right--;
            else{
                vector<int>tmp(3,0);
                tmp[0] = nums[i];
                tmp[1] = nums[left];
                tmp[2] = nums[right];
                res.push_back(tmp);
                while(left < right && nums[left] == tmp[1]) left++;
                while(left < right && nums[right] == tmp[2]) right--;
            }
        }
        while(nums[i+1] == nums[i]) i++;
    }
    return res;
}

int main(){
    vector<int>nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = threeSum(nums);
    cout<<res.size()<<endl;
    for(int i = 0;i<res.size();i++)
        for(int j = 0;j<res[0].size();j++)
            cout<<res[i][j]<<" ";
}
