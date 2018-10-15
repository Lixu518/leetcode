#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> intersection(vector<int>&nums1, vector<int>&nums2){
    unordered_set<int>t(nums1.begin(), nums2.begin());
    vector<int> res;
    for(auto num:nums2){
        if(t.count(num)){
            res.push_back(num);
            t.erase(num);
        }
    }
    return res;
}

int main(){
    vector<int>nums1 = {1,2,3}, nums2 = {2,3,4};
    vector<int>res = intersection(nums1, nums2);
    for(auto num: res)
        cout<<num<<" ";
    cout<<endl;
}

