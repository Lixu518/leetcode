#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>&nums, int left, int right){
    int pivot = nums[left];
    while(left < right){
        while(left < right && nums[right] > pivot) right--;
        nums[left] = nums[right];
        while(left<right && nums[left] < pivot) left++;
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    return left;
}
int quickSort(vector<int>& nums, int left, int right){
    if(left < right ){
        int pivotPos = partition(nums, left, right);
        quickSort(nums, left, pivotPos-1);
        quickSort(nums, pivotPos+1, right);
    }
}
int main(){
    vector<int>nums;
    for(int i = 0; i<20;i++){
        nums.push_back(20-i);
    }
    quickSort(nums, 0, nums.size()-1);
    for(int i = 0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
