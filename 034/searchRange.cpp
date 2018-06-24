#include<iostream>
#include<vector>
using namespace std;

int searchLeft(vector<int>& nums, int target){
        if(nums.empty() || nums.size() == 0) return -1;
        int left = 0, right = nums.size(), mid;
        while(left < right){
                    mid = (left + right)>>1;
                    if(nums[mid] < target) left = mid + 1;
                    else right = mid;
                }
        return left;
}

vector<int> searchRange(vector<int>& nums, int target){ 
        int start = searchLeft(nums, target);
        if(start == -1 || start == nums.size() || nums[start] != target)
            return vector<int>{-1, -1};
        return vector<int>{start, searchLeft(nums, target + 1) - 1};
}

int main(){
	vector<int>nums = {5,7,7,8,8,10};
	vector<int>res = searchRange(nums, 8);
	cout<<res[0]<<" "<<res[1]<<endl;
	return 0;
}
