#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int minSubArrayLen(int s, vector<int>& nums){
    int left = 0, sum = 0, res = INT_MAX;
    for(int i = 0;i < nums.size();i++){
        sum += nums[i];
        while(left <= i && sum >= s){
            res = min(res, i - left + 1);
            sum -= nums[left++];
        }
    }
    return res == INT_MAX ? 0 : res;
}

int main(){
    vector<int>nums = {2,3,1,2,4,3};
    cout<<"Res: "<<minSubArrayLen(7,nums)<<endl;
    return 0;
}
