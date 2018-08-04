#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	if(nums.empty() || nums.size() <= 1) return false;
	unordered_map<int,int>mp;
	for(int i = 0;i < nums.size();i++){
		if(mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k)return true;
		mp[nums[i]] = i;
	}
	return false;
}

int main(){
	vector<int>nums = {1,2,3,1,2,3};
	cout<<containsNearbyDuplicate(nums,2)<<endl;
	return 0;
}
