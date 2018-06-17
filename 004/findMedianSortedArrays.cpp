#include<iostream>
#include<vector>
using namespace std;
double findkth(vector<int>nums1, vector<int>nums2, int k){
    int m = nums1.size(), n = nums2.size();
    if(m > n) return findkth(nums2, nums1, k);
    if(m == 0) return nums2[k-1];
    if(k == 1) return min(nums1[0], nums2[0]);
    int i = min(k/2, m), j = min(k/2, n);
    if(nums1[i-1] > nums2[j-1])
        return findkth(nums1, vector<int>(nums2.begin()+j, nums2.end()), k - j);
    else
        return findkth(vector<int>(nums1.begin()+i, nums1.end()), nums2, k - i);
}

double findMeidanSortedArrays(vector<int>&nums1, vector<int>&nums2){
    int m = nums1.size(), n = nums2.size();
    return (findkth(nums1, nums2, (m+n+1)/2) + findkth(nums1, nums2, (m+n+2)/2))/2.0;
}

int main(){
    vector<int>nums1 = {1,2}, nums2 = {3,4};
    cout<<findMeidanSortedArrays(nums1, nums2);
    return 0;
}
