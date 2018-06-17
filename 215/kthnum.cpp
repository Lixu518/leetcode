#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int kthNum(vector<int>&nums, int k){
    if(nums.empty()||nums.size()<k)
        return -1;
    make_heap(nums.begin(), nums.end());
    int res;
    for(int i = 0;i<k;i++){
        res = nums.front();
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
    }
    return res;
}
int main(){
    vector<int>nums;
    for(int i = 0;i<100;i++)
        nums.push_back(i);
    int res = kthNum(nums, 50);
    cout<<res;
    return 0;
}
