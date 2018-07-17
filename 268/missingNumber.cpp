#include<iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int>&nums){
    int n = nums.size(), sum = 0;
    for(auto num : nums)
        sum += num;
    return n*(n+1)/2 - sum;
}

int main(){
    vector<int>nums = {9,6,4,2,3,5,7,0,1};
    cout<<"Missing Number: "<<missingNumber(nums)<<endl;
    return 0;
}
