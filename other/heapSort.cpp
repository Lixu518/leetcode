#include<iostream>
#include<vector>
using namespace std;
void adjustDown(vector<int>&nums, int i, int len){
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;
    if(l< len && nums[i] < nums[l]){
        largest = l;
    }
    if(r < len && nums[largest] < nums[r]){
        largest = r;
    }
    if(largest != i){
        swap(nums[largest], nums[i]);
        adjustDown(nums, largest, len);
    }
}

void buildHeap(vector<int>&nums, int len){
    for(int i = len/2 - 1; i >= 0;i--)
        adjustDown(nums, i, len);
}

void heapSort(vector<int>&nums, int len){
    buildHeap(nums, len);
    for(int i = len - 1; i > 0;i--){
        swap(nums[0], nums[i]);
        adjustDown(nums, 0, i);
    }
}
int main(){
    vector<int>nums = {1,3,1,2,1,5,4,3,9,8,6,5,7};
    heapSort(nums, nums.size());
    for(auto a:nums)
        cout<<a;
    cout<<endl;
    return 0;
}
