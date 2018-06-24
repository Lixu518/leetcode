#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int>&nums, int target){
   vector<vector<int>> total;
        int n = nums.size();
        if(n<4) return total;
        sort(nums.begin(),nums.end());
        for (int i=0;i<n-3;i++){
            if(i>0&&nums[i]==nums[i-1])  continue;
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for (int j = i+1;j<n-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int left = j+1, right = n-1;
                while(left<right){
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum <target)
                        left++;
                    else if(sum>target)
                        right--;
                    else{
                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        do{left++;}while(left<right&&nums[left]==nums[left-1]);
                        do{right--;}while(left<right&&nums[right]==nums[right+1]);
                    }
                }
            }
        }
        return total; 
}

int main(){
    vector<int>nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>>res = fourSum(nums, 0);
    for(int i = 0;i<res.size();i++){
        for(int j = 0;j < res[0].size();j++)
            cout<<res[i][j];
        cout<<endl;
    }
    return 0;
}
