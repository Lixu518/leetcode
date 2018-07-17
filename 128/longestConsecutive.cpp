#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int longestConsecutive(vector<int>& nums){
    if(nums.empty() || nums.size() == 0) return 0;
    int res = 0;
    unordered_set<int>s(nums.begin(), nums.end());
    for(auto num : nums){
        if(s.erase(num)){
            int pre = num - 1, next = num + 1;
            while(s.erase(pre)) pre--;
            while(s.erase(next)) next++;
            res = max(res, next - pre -1);
        }
    }
    return res;
}

int main(){
    vector<int>nums = {100, 4, 200, 1, 3, 2};
    cout<<"The longest consecutive sequence is: "<<longestConsecutive(nums)<<endl;
    return 0;
}
