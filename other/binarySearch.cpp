#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int>& nums, int target){
    if(nums.size() == 0)
        return -1;
    int left = 0, right = nums.size()-1;
    int mid;
    while(left < right){
        cout<<left<<" "<<right<<endl;
        mid =left +( (right-left)>>1);
        cout << "mid" << mid << endl;
        if(nums[mid] > target)
            right = mid - 1;
        else
            left = mid;
    }
    cout<<"left"<<endl;
    if(nums[left]== target) return left;
    return -1;
}

int main(){
    vector<int>nums;
    for(int i = 0;i<10;i++){
        if (i>2&& i<8)nums.push_back(5);
        else nums.push_back(i);
    }
    cout<<nums[9]<<endl;
    int res = binarySearch(nums, 5);
    cout<<res;
    return 0;
}
