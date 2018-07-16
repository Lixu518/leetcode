#include <iostream>
#include <vector>
using namespace std;
int majorityElement(vector<int>& nums) {
	int res = nums[0], cnt = 1;
	for(int i = 1;i < nums.size();i++){
		if(nums[i] == res) cnt++;
		else cnt--;
		if(cnt == 0){
			res = nums[i];
			cnt++;
		}
	}
	return res;
}

int main(){
	vector<int>nums = {2,2,1,1,1,2,2};
	cout<<"The majority num is: "<<majorityElement(nums)<<endl;
	return 0;
}
