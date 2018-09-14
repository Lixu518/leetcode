#include<iostream>
#include<vector>
using namespace std;
int arrayNesting(vector<int>& nums) {
	size_t res = 0;
	for(int i = 0;i < nums.size();i++){
		size_t s = 0;
		for(int j = i;nums[j] >= 0;s++){
			int temp = nums[j];
			nums[j] = -1;
			j = temp;
		}
		res = max(res, s);
	}
	return res;
}

int main(){
	vector<int>nums = {5,4,0,3,1,6,2};
	cout<<"len: "<<arrayNesting(nums)<<endl;
	return 0;
}
