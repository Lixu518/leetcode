#include<iostream>
#include<vector>
using namespace std;
int trap(vector<int>& height){
	if(height.empty() || height.size() <= 2) return 0;
    int left = 0, right = height.size() - 1, maxWater = 0, leftmax = 0, rightmax = 0;
    while(left < right){
    	leftmax = max(height[left], leftmax);
        rightmax = max(height[right], rightmax);
        if(leftmax < rightmax)
        	maxWater += leftmax - height[left++];
        else 
            maxWater += rightmax - height[right--];
        }
        return maxWater; 
}

int main(){
	vector<int>height = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<trap(height)<<endl;
	return 0;
}
