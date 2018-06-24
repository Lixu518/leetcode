#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    if(nums.empty() || nums.size() <= 1)
        return nums.size();
    int len = 0;
    for(int i = 0;i < nums.size();i++){
        if(nums[i] != nums[len])
            nums[++len] = nums[i];
    }
    return ++len;
}
int main(){
    vector<int>nums = {1, 1, 2};
    cout<<removeDuplicates(nums)<<endl;
}
