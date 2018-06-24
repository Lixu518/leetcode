#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int>&nums, int target){
   	if(nums.empty() || nums.size() == 0)return 0;
  	if(nums[nums.size() - 1] < target) return nums.size();
   	int left = 0, right = nums.size() - 1, mid;
   	while(left < right){
   		mid = (left + right)>>1;
     	if(nums[mid] < target) left = mid + 1;
        else right = mid;
   	}
   	return left; 
}
int main(){
	vector<int>nums = {1,3,5,7};
	cout<<searchInsert(nums, 0);
	cout<<searchInsert(nums, 3);
	cout<<searchInsert(nums, 8)<<endl;
}
