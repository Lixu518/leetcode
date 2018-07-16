#include<iostream>
#include<vector>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int>res;
	if(nums.empty() || nums.size() <= 1) return res;
	int left = 0, right = nums.size() - 1;
	while(nums[left] + nums[right] != target){
		if(nums[left] + nums[right] < target) left++;
		else right--;
	}
	res.push_back(left+1);
	res.push_back(right+1);
	return res;
}

int main(){
	vector<int>nums = {2,7,11,15};
	vector<int>res = twoSum(nums, 9);
	cout<<"First index: "<<res[0]<<endl;
	cout<<"Second index: "<<res[1]<<endl;
	return 0;
}
