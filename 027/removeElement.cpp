#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>&nums, int val){
    if(nums.empty() || nums.size() == 0)
        return 0;
    int len = 0;
    for(int i = 0;i < nums.size();i++){
        if(nums[len] != val)
            nums[len++] = nums[i];
    }
    return len;
}
int main(){
    vector<int>nums = {0,1,2,2,3,0,4,2};
    cout<<removeElement(nums, 2)<<endl;
    cout<<nums[4];
}
