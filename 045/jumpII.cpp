#include<iostream>
#include<vector>
using namespace std;
int jump(vector<int>& nums){
    int sc = 0, maxSize = 0, end = 0;
    for(int i = 0;i<nums.size() - 1;i++){
        maxSize = max(maxSize, i + nums[i]);
        if(i == end){
            sc++;
            end = maxSize;
        }
    }
    return sc;
}
int main(){
    vector<int>nums = {2,3,1,1,4};
    cout<<"Min step: "<<jump(nums)<<endl;
    return 0;
}
