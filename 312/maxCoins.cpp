#include<iostream>
#include<vector>
using namespace std;
int maxCoins(vector<int> &nums){
    if(nums.empty() || nums.size() == 0)return 0;
    int len = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>>dp(len + 2, vector<int>(len + 2, 0));
    for(int i = 1;i <= len;++i){
        for(int left = 1;left <= len - i + 1;++left){
            int right = left + i - 1;
            for(int k = left;k <= right;++k){
                dp[left][right] = max(dp[left][right],
                        nums[left-1]*nums[k]*nums[right+1] + dp[left][k-1] +
                        dp[k+1][right]);
            }
        }
    }
    return dp [1][len];
}
int main(){
    vector<int> nums = {3,1,5,8};
    cout<<"mac Coins:"<<maxCoins(nums)<<endl;
    return 0;
}


