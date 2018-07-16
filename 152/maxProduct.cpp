#include <iostream>
#include <vector>
using namespace std;
int maxProduct(vector<int>& nums){
    if(nums.empty() || nums.size() == 0) return 0;
    vector<int>minsub(nums.size(), 0);
    vector<int>maxsub(nums.size(), 0);
    int res = nums[0];
    minsub[0] = nums[0], maxsub[0] = nums[0];
    for(int i = 1;i < nums.size();i++){
        minsub[i] = min(min(minsub[i-1]*nums[i], maxsub[i-1]*nums[i]), nums[i]);
        maxsub[i] = max(max(minsub[i-1]*nums[i], maxsub[i-1]*nums[i]), nums[i]);
        res = max(res, maxsub[i]);
    }
    return res;
}

int main(){
    vector<int>nums = {2,3,-2,4};
    cout<<"The max product is:"<<maxProduct(nums)<<endl;
    return 0;
}
