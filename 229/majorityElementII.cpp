#include<iostream>
#include<vector>
using namespace std;
vector<int> majorityElement(vector<int>&nums){
    vector<int>res;
    if(nums.empty() || nums.size() == 0) return res;
    int m = 0, n = 0, cm = 0, cn = 0;
    for(auto a : nums){
        if(a == m) cm++;
        else if(a == n) cn++;
        else if(cm == 0){
            m = a;
            cm =1;
        }
        else if(cn == 0){
            n = a;
            cn = 1;
        }
        else{
            cn--;
            cm--;
        }
    }
    cn = 0, cm = 0;
    for(auto a : nums){
        if(a == m) cm++;
        else if(a == n) cn++;
    }
    if(cm > nums.size() / 3) res.push_back(m);
    if(cn > nums.size() / 3) res.push_back(n);
    return res;
}

int main(){
    vector<int>nums = {1,1,1,3,3,2,2,2};
    vector<int> res = majorityElement(nums);
    for(auto num : res)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}
