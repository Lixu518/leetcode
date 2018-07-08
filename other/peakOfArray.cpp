#include<iostream>
#include<vector>
using namespace std;

int peak(vector<int>&nums, int left, int right){
    int mid = (left + right)>>1;
    if(nums[mid - 1] <= nums[mid] && nums[mid + 1] <= nums[mid])
        return mid;
    else if(mid > 0 && nums[mid - 1] > nums[mid])
        return peak(nums, left, mid - 1);
    else 
        return peak(nums, mid + 1, right);
}

int findPeak(vector<int>& nums){
    if(nums.empty() || nums.size() == 0) return 0;
    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);
    return peak(nums, 0, nums.size() - 1);
}

int main(){
    vector<int>nums = {3,2,1,0,0,0,0};
    cout<<findPeak(nums)<<endl;
    return 0;
}
