#include<iostream>
#include<climits>
#include<vector>
using namespace std;
bool increasingTriplet(vector<int>& nums) {
    int m1 = INT_MAX, m2 = INT_MAX;
    for(auto a:nums){
        if(m1 >= a) m1 = a;
        else if(m2 >= a)m2 = a;
        else return true;
    }
    return false;
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    cout<<"[1,2,3,4,5] has increasing triplet? "<<increasingTriplet(nums)<<endl;
    return 0;
}
