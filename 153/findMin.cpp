#include<iostream>
#include<vector>
using namespace std;
int findMin(vector<int>& nums){
    int left = 0, right = nums.size() - 1;
    while(left < right){
        if(nums[left] < nums[right]) return nums[left];
        int mid = (left + right)>>1;
        if(nums[left] <= nums[mid]) left = mid + 1;
        else right = mid;
    }
    return nums[left];
}

int main(){
    vector<int>nums = {4,5,6,7,0,1,2};
    cout<<"Min num of rotate array is: "<<findMin(nums)<<endl;
    return 0;
}
