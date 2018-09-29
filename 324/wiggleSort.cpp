#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void wiggleSort(vector<int> &nums){
    if(nums.empty())
        return;
    int n = nums.size();
    vector<int>::iterator nth = next(nums.begin(), n/2);
    nth_element(nums.begin(), nth, nums.end());
    int median = *nth;
    auto m = [n](int idx){
        return (2*idx + 1)%(n|1);
    };
    int first = 0, mid = 0, last = n - 1;
    while(mid <= last){
        if(nums[m(mid)] >median)
            swap(nums[m(first++)], nums[m(mid++)]);
        else if (nums[m(mid)] < median)
            swap(nums[m(mid)], nums[m(last--)]);
        else
            ++mid;
    }
}

int main(){
    vector<int>nums = {1, 3, 2, 2, 3, 1};
    wiggleSort(nums);
    for(auto num:nums)
        cout<<num<<" ";
    cout<<endl;
    return 0;
}
