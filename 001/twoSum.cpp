#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int,int>hash;
    vector<int>res;
    if(nums.size() < 2)
        return res;
    for(int i = 0; i < nums.size();i++){
        int numToFind = target - nums[i];
        if(hash.find(numToFind) != hash.end()){
            res.push_back(hash[numToFind]);
            res.push_back(i);
            return res;
        }
        hash[nums[i]] = i;
    }
    return res;
}

int main(){
    vector<int>nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    vector<int>res;
    res = twoSum(nums, 9);
    cout<<res[0]<<' '<<res[1]<<endl;
    return 0;
}

