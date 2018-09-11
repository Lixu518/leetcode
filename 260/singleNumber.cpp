#include<iostream>
#include<functional>
#include<numeric>
#include<vector>
using namespace std;
vector<int> singleNumber(vector<int> &nums){
    vector<int> res(2, 0);
    int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    diff &= -diff;
    for(auto &a : nums){
        if(a & diff) res[0] ^= a;
        else res[1] ^= a;
    }
    return res;
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,6,5,4,3,2};
    vector<int> res = singleNumber(nums);
    cout<<res[0]<<" "<<res[1]<<endl;
}
