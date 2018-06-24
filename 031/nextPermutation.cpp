#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
void nextPermutation(vector<int>& nums){
		if(nums.empty() || nums.size() <= 1)
            return;
        int index = nums.size()-1;
        while(index > 0 && nums[index] <= nums[index-1])
            index--;
        if(index == 0){
            sort(nums.begin(), nums.end());
            return;
        }
        int idx = INT_MAX, temp = INT_MAX;
        for(int i = index;i < nums.size();i++){
            if(nums[i] > nums[index-1] && nums[i] < temp){
                temp = nums[i];
                idx = i;
            }
        }
        swap(nums[index - 1], nums[idx]);
        sort(nums.begin() + index, nums.end());
}
int main(){
	vector<int>nums = {1,3,2};
	nextPermutation(nums);
	for(int i = 0;i < nums.size();i++)
		cout<<nums[i];
	return 0;
}

