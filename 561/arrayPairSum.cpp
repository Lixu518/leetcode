#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arrayPairSum(vector<int>& nums) {
	int sum = 0;
	sort(nums.begin(), nums.end());
	for(int i = 0;i < nums.size();i += 2){
		sum += nums[i];
	}
	return sum;
}

int main(){
	vector<int> nums = {1,4,3,2};
	cout<<"res: "<<arrayPairSum(nums)<<endl;
	return 0;
}
