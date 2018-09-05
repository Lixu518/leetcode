#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
bool containsNearByAlomostDuplicates(vector<int>&nums, int k, int t){
    map<long long, int>m;
    int j = 0;
    for(int i = 0;i < nums.size();i++){
        if(i - j > k) m.erase(nums[j++]);
        auto a = m.lower_bound((long long)nums[i] - t);
        if(a != m.end() && abs(nums[i] - a->first) <= t) return true;
        m[nums[i]] = i;
    }
    return false;
}

int main(){
    vector<int> nums = {1,5,9,1,5,9};
    cout<<containsNearByAlomostDuplicates(nums, 2, 3)<<endl;
    return 0;
}

