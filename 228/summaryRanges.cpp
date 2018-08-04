#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> summaryRanges(vector<int>& nums){
    vector<string>res;
    if(nums.empty() || nums.size() == 0) return res;
    for(int i = 0;i < nums.size();i++){
        int start = i, end = i;
        while(end + 1 < nums.size() && nums[end] + 1 == nums[end+1]) end++;
        if(end > start)
            res.push_back(to_string(nums[start])+ "->" + to_string(nums[end]));
        else
            res.push_back(to_string(nums[start]));
        i = end + 1;
    }
    return res;
}

int main(){
    vector<int>nums = {1,2,3,5,6,8,9,10};
    vector<string>res = summaryRanges(nums);
    for(auto s: res)
        cout<<s<<" ";
    cout<<endl;
    return 0;
}
