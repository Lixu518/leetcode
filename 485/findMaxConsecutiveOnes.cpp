#include<iostream>
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums){
    int pos = -1, res;
    for(int i = 0;i < nums.size();i++){
        if(nums[i] != 1) pos = i;
        res = max(res, i - pos);
    }
    return res;
}

int main(){
    vector<int>nums = {1,0,0,1,1,0,1,1,1,1,1,1};
    cout<<findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}
