#include<iostream>
#include<vector>
using namespace std;
void moveZeroes(vector<int>&nums){
    int left = 0;
    for(int i = 0;i < nums.size();i++){
        if(nums[i] != 0)
            nums[left++] = nums[i];
    }
    for(;left < nums.size();left++)
        nums[left] = 0;
}

int main(){
    vector<int>nums = {1,0,2,0,0,3,0,4,0,5,6,0,7};
    moveZeroes(nums);
    for(auto num : nums)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}
