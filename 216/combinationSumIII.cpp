#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<int>>& res, vector<int>&temp,int n, int k){
	if(n < 0 || k < 0)return;
	if(n == 0 && temp.size() == k){
		res.push_back(temp);
		return;
	}
	if(temp.size() < k){
		for(int i = (temp.empty() ? 1 : temp.back() + 1);i <= 9;i++){
			if(n - i < 0)break;
			temp.push_back(i);
			dfs(res, temp, n - i, k);
			temp.pop_back();
		}
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>>res;
	vector<int>temp;
	dfs(res, temp, n, k);
	return res;
}

int main(){
	vector<vector<int>>res = combinationSum3(3, 9);
	for(int i = 0;i < res.size();i++){
		for(int j = 0;j < res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
