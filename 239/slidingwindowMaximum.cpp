#include<iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k){
    vector<int>res;
    deque<int>q;
    for(int i = 0;i < nums.size();i++){
        if(!q.empty() && q.front() == i - k)q.pop_front();
        while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
        q.push_back(i);
        if(i >= k - 1)res.push_back(nums[q.front()]);
    }
    return res;
}
int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> res = maxSlidingWindow(nums, 2);
    for(auto a : res)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}

