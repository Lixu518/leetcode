#include<iostream>
#include<vector>
using namespace std;
int minPatchs(vector<int>&nums, int n){
    long miss = 1, res = 0, i = 0;
    while(miss <= n){
        if(i < nums.size() && nums[i] <= miss){
            miss += nums[i++];
        }else{
            miss += miss;
            ++res;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {1, 5, 10};
    int n = 20;
    cout<<"min patchs: "<<minPatchs(nums, n)<<endl;
    return 0;
}

