#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int>&nums){
    int left = 0, right = nums.size() - 1;
    while(left < right){
        int mid = (left + right)>>1;
        if(nums[left] < nums[right]) right = mid;
        else if(nums[mid] > nums[right]) left = mid + 1;
        else right--;
    }
    return nums[left];
}

int main(){
    vector<int>nums = {10,10,1,10,10};
    cout<<"The min num is: "<<findMin(nums)<<endl;
    return 0;
}
