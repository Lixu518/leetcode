#include<iostream>
#include<vector>
using namespace std;
vector<int> getMax(vector<int>&nums, int k){
    vector<int> vec;
    int drop = nums.size() - k;
    for(int i = 0;i < nums.size();++i){
        while(drop > 0 && vec.size() && nums[i] > vec.back()){
            --drop;
            vec.pop_back();
        }
        vec.push_back(nums[i]);
    }
    vec.resize(k);
    return vec;
}

vector<int> mergeMax(vector<int> nums1, vector<int> nums2){
    vector<int> vec;
    while(nums1.size() + nums2.size()){
        vector<int> &tmp = nums1>nums2?nums1:nums2;
        vec.push_back(tmp[0]);
        tmp.erase(tmp.begin());
    }
    return vec;
}

vector<int> maxNumber(vector<int> &nums1, vector<int>&nums2, int k){
    vector<int>res;
    int m = nums1.size(), n = nums2.size();
    for(int i = max(0, k - n);i <= min(k, m);++i){
        res = max(res, mergeMax(getMax(nums1, i), getMax(nums2, k - i)));
    }
    return res;
}

int main(){
    vector<int> nums1 = {3, 4, 6, 5}, nums2 = {9, 1, 2, 5, 8, 3};
    vector<int> res = maxNumber(nums1, nums2, 5);
    for(auto num:res)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}
