#include <iostream>
#include <vector>
using namespace std;
bool search(vector<int>&nums, int target){
    if(nums.empty() || nums.size() == 0) return false;
    int left = 0, right = nums.size() - 1, mid;
    while(left <= right){
        mid = (left + right)>>1;
        if(nums[mid] == target) return true;
        if(nums[left] == nums[mid] && nums[mid] == nums[right]){
            left++;
            right--;
        }
        else if(nums[left] <= nums[mid]){
                if(nums[left] <= target && nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
        }
        else {
            if(nums[right] >= target && nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}

int main(){
    vector<int>nums = {1};
    cout<<"Has: "<<search(nums, 1)<<endl;
    return 0;
}
