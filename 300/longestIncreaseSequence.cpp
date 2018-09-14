#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lengthOfLIS(vector<int>& nums){
    if(nums.empty() || nums.size() == 0) return 0;
    int res = 1, n = nums.size();
    vector<int>dp(n, 1);
    for(int i = 0;i < n;++i){
        for(int j = 0;j < i;++j){
            if(nums[i] > nums[j] && dp[i] < 1 + dp[j]){
                dp[i] = dp[j] + 1;
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main(){
    vector<int> nums = {1,2,3,4,1,2,3,1,2,5,7,8,5,5,3,6};
    cout<<"length of LIS:"<<lengthOfLIS(nums)<<endl;
}
