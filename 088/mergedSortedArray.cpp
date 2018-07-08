#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>&nums1, int m, vector<int>&nums2, int n){
    while(n > 0)
        nums1[m+n-1] = (m == 0 || nums2[n-1] > nums1[m-1]) ? nums2[--n]:nums1[--m];
}

int main(){
    vector<int> nums1 = {0,0,3,0,0,0,0,0,0};
    vector<int> nums2 = {-1,1,1,1,2,3};
    merge(nums1, 2, nums2, 6);
    for(auto a : nums1)
        cout<<a;
    cout<<endl;
    return 0;
}
