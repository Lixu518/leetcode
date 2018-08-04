#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
	if(nums.empty() || nums.size() == 0) return false;
	unordered_map<int,int>mp;
	for(int i = 0;i < nums.size();i++){
		mp[nums[i]]++;
		if(mp[nums[i]] > 1) return true;
	}
	return false;
}

int main(){
	vector<int>nums = {1,2,3,1,3,};
	cout<<"Contain Duplcates?"<<containsDuplicate(nums)<<endl;
	return 0;	
}
