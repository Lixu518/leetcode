#include<iostream>
#include<vector>
using namespace std;

int single(vector<int>& nums){
    int res = 0;
    for(int i = 0; i < 32;i++){
        int sum = 0;
        for(int j = 0;j < nums.size();j++){
            sum += (nums[j]>>i) & 1;
        }
        res |= (sum%3)<<i;
    }
    return res;
}

int single2(vector<int>& nums){
    int a = 0, b = 0;
    for(int i = 0;i < nums.size();i++){
        b = (b^nums[i]) & ~a;
        a = (a^nums[i]) & ~b;
    }
    return b;
}

int main(){
    vector<int>nums = {1, 2,3,3,2,1,1,3,2,4};
    cout<<"solution 1:"<<single(nums)<<endl;
    cout<<"solution 2:"<<single2(nums)<<endl;
    return 0;
}
