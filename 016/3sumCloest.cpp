#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int threeSumCloest(vector<int>&nums, int target){
    if(nums.empty() || nums.size() < 3)
        return 0;
    int res = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for(int i = 0;i< nums.size()-2;i++){
        int left = i+1, right = nums.size()-1;
        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == target) return sum;
            else if(sum < target) left++;
            else right--;
            if(abs(sum - target) < abs(res - target))
                res = sum;
        }
    }
    return res;
}

int main(){
    vector<int>nums = {-1, 2, 1, -4};
    cout<<"Result is:"<<threeSumCloest(nums, 1)<<endl;
    return 0;
}
