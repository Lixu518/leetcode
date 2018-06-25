#include<iostream>
#include<vector>
using namespace std;
int maxSubArray(vector<int>&nums){
	if(nums.empty() || nums.size() == 0)
    	return 0;
    int res = nums[0], maxsub = nums[0];
    for(int i = 1;i < nums.size();i++){
        maxsub = max(nums[i] + maxsub, nums[i]);
        res = max(res, maxsub);
    }
    return res;
}

int main(){
	vector<int>nums = {-2,1,-3,4,-1,2,1,-5,4};
	cout<<"The max subarray is: "<<maxSubArray(nums)<<endl;
	return 0;
}
