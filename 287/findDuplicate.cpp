#include<iostream>
#include<vector>
using namespace std;
int findDuplicate(vector<int>& nums){
    int slow = nums[0], fast = nums[nums[0]];
    while(fast != slow){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    fast = 0;
    while(slow != fast){
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}

int main(){
    vector<int>nums = {1,2,3,4,2};
    cout<<findDuplicate(nums)<<endl;
    return 0;
}
