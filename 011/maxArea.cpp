#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>&heights){
    int maxArea = 0;
    int i = 0, j = heights.size()-1;
    while(i<j){
        maxArea = max(maxArea, min(heights[i], heights[j])*(j-i));
        if(heights[i] < heights[j]) i++;
        else j--;
    }
    return maxArea;
}
int main(){
    vector<int>heights = {1,4,9,11};
    cout<<maxArea(heights);
    return 0;
}
