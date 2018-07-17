#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void rotate(vector<int>& nums, int k) {
	while(k >nums.size()) k -= nums.size();
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

int main(){
	vector<int>nums = {1,2,3,4,5,6,7,8};
	rotate(nums, 11);
	for(auto n: nums)
		cout<<n<<" ";
	cout<<endl;
	return 0;
}
