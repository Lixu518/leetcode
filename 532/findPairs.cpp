#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int findPairs(vector<int>&nums, int k){
   	if(nums.empty() || nums.size() == 0 || k < 0) return 0;
	unordered_map<int, int>m;
	for(auto num : nums)m[num]++;
	int res = 0;
	for(auto n:m){
		if((!k && n.second > 1) || (k && m.find(n.first + k)!= m.end()))
		   res++;
	}
	return res;  
}

int main(){
	vector<int>nums = {1,2,3,4,5};
	cout<<"k-diff pairs:"<<findPairs(nums, 1)<<endl;
	return 0;
}
