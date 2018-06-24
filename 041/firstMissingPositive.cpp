#include<iostream>
#include<vector>
using namespace std;
int firstMissingPositive(vector<int>&nums){
   if(nums.empty() || nums.size() == 0)
            return 1;
        int i = 0;
        while(i < nums.size()){
            if(nums[i] != i+1 && nums[i] >= 1 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        for(int i = 0;i < nums.size();i++)
            if(nums[i] != (i + 1))
                return i+1;
        return nums.size() + 1; 
}

int main(){
	vector<int>nums = {1,2,0};
	cout<<firstMissingPositive(nums)<<endl;
	return 0;
}
