#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void combination(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>tmp, int pos){
    if(!target){
        res.push_back(tmp);
        return;
    }
    for(int i = pos;i<candidates.size() && target >= candidates[i];i++){
        tmp.push_back(candidates[i]);
        combination(candidates, target - candidates[i], res, tmp, i);
        tmp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>>res;
    if(candidates.empty() || candidates.size() == 0)
        return res;
    vector<int>tmp;
    sort(candidates.begin(), candidates.end());
    combination(candidates, target, res, tmp, 0);
    return res;
}

int main(){
    vector<int> candidates = {2, 3, 5};
    vector<vector<int>> res = combinationSum(candidates, 8);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++){
            cout<<res[i][j];
        }
        cout<<endl;
    }
}
