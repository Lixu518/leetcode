#include <iostream>
#include <vector>
using namespace std;
void sortColors(vector<int>& nums) {
	if(nums.empty()||nums.size()<=1) return;
	int left = 0, right = nums.size()-1;
	for(int i = 0;i <= right;i++){
		while(nums[i] == 2 && i < right)swap(nums[i], nums[right--]);
		while(nums[i] == 0 && i > left)swap(nums[i], nums[left++]);
	}
}

int main(){
	vector<int>nums = {0,1,2,1,2,1,2,0,0,2,1};
	sortColors(nums);
	for(auto i:nums)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}
