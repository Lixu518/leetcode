#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
	int i = 0;
	for(auto n:nums){
		if(i < 2 || n > nums[i-2])
			nums[i++] = n;
	}
	return i;
}

int main(){
	vector<int> nums = {0,0,0,0,1,1,1,2,2,3,3,3,4};
	cout<<removeDuplicates(nums)<<endl;
	for(auto c:nums)
		cout<<c<<" ";
	cout<<endl;
	return 0;
}
