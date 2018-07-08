#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& res, vector<int>& tmp,vector<int>& nums,int m){
    res.push_back(tmp);
    for (int i=m;i<nums.size();i++){
        tmp.push_back(nums[i]);
        dfs(res,tmp,nums,i+1);                                                                                                                 
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res;
	vector<int> tmp;
	dfs(res,tmp,nums,0);
	return res;
}

int main(){
	vector<int>nums = {1,2,3,4,5,0};
	vector<vector<int>> res = subsets(nums);
	for(int i = 0;i < res.size();i++){
		for(int j = 0;j < res[i].size();j++)
			cout<<res[i][j];
		cout<<endl;
	}
	return 0;
}
