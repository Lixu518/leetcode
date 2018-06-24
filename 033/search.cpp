#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>&nums, int target){
    if(nums.empty() || nums.size() == 0)
        return -1;
    int left = 0, right = nums.size() - 1, mid;
    while(left <= right){
        mid = (left + right)>>1;
        if(nums[mid] == target) return mid;
        if(nums[left] <= nums[mid]){
            if(nums[left] <= target && target < nums[mid])right = mid - 1;
            else left = mid + 1;
        }else
            if(nums[mid] < target && nums[right] >= target) left = mid + 1;
            else right = mid - 1;
    }
    return -1;
}
int main(){
    vector<int>nums = {4,5,6,7,0,1,2};
    cout<<search(nums, 0);
    return 0;
}
