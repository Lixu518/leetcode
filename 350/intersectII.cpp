#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> intersect(vector<int>&nums1, vector<int>&nums2){
    unordered_map<int,int>t;
    vector<int>res;
    for(int i = 0;i<nums1.size();i++)t[nums1[i]]++;
    for(auto num:nums2){
        if(--t[num] >= 0){
            res.push_back(num);
        }
    }
    return res;
}

int main(){
    vector<int>nums1 = {1,2,3,4,4,5,5,6}, nums2 = {1,2,3,4,4,6};
    vector<int>res = intersect(nums1, nums2);
    for(auto num : res)
        cout<<num<<" ";
    return 0;
}
