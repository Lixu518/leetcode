#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int>&nums, int left, int right){
    if(left == right) return left;
    int mid1 = (left + right)>>1;
    int mid2= mid1 + 1;
    if(nums[mid1] > nums[mid2]) return helper(nums, left, mid1);
    else return helper(nums, mid2, right);
}

int findPeakElement(vector<int>&nums){
    return helper(nums, 0, nums.size() - 1);
}

int main(){
    vector<int>nums = {1,2,1,2,1,2,3,4,3,2,1};
    cout<<"One of the peak is:"<<findPeakElement(nums)<<endl;
    return 0;
}
