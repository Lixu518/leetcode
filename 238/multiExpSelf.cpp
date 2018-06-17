#include <iostream>
#include <vector>
using namespace std;
vector<int> multiExpSelf(vector<int>&nums){
    if(nums.empty()||nums.size()<=1)
        return nums;
    vector<int>res(nums.size(),1);
    for(int i = 1;i<nums.size();i++)
        res[i] = res[i-1]*nums[i-1];
    int tmp = nums.back();
    for(int i = nums.size()-2;i>=0;i--){
        res[i] = res[i]*tmp;
        tmp *= nums[i];
    }
    return res;
}

int main(){
    vector<int>nums = {1,2,3,4};
    vector<int> res = multiExpSelf(nums);
    for(int i = 0;i<res.size();i++)
        cout<<res[i]<<" ";
    return 0;
}
