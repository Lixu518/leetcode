#include<iostream>
#include<vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int> nums) {
        num.resize(nums.size() + 1);
        bit.resize(nums.size() + 1);
        for(int i = 0;i < nums.size();++i){
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - num[i + 1];
        for(int j = i + 1;j < num.size(); j += (j & -j)){
            bit[j] += diff;
        }
        num[i + 1] = val;
    }
    
    int sumRange(int i, int j) {
        return getSum(j+1) - getSum(i);
    }
    
    int getSum(int i){
        int res = 0;
        for(int j = i;j > 0; j -= (j&-j))
            res += bit[j];
        return res;
    }
private:
    vector<int>num;
    vector<int>bit;
};

int main(){
    vector<int> nums = {1, 3, 5};
    NumArray na(nums);
    cout<<"na.sumRange(0, 2): "<<(na.sumRange(0, 2))<<endl;
    na.update(1, 2);
    cout<<"na.sumRange(0, 2): "<<(na.sumRange(0, 2))<<endl;
    return 0;
}

