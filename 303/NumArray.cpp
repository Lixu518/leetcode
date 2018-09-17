#include<iostream>
#include<vector>
using namespace std;
class NumArray {
public:
    NumArray(const vector<int> nums) {
        sum.push_back(0);
        for(int num:nums){
            sum.push_back(sum.back()+num);
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
private:
    vector<int> sum;
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8};
    NumArray na(nums);
    cout<<na.sumRange(1,5)<<endl;
}
