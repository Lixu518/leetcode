#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int largestRectangle(vector<int>&heights){
    if(heights.empty() || heights.size() == 0)
        return 0;
    stack<int>s;
    int maxArea, h, w;
    heights.push_back(0);
    for(int i = 0;i < heights.size();i++){
        if(s.empty() || heights[s.top()] < heights[i])
            s.push(i);
        else{
            while(!s.empty() && heights[s.top()] >= heights[i]){
                h = s.top();
                s.pop();
                w = s.empty()?i:i - (s.top() + 1);
                maxArea = max(maxArea, w*h);
            }
            s.push(i);
        }
    }
    return maxArea;
}

int main(){
    vector<int> heights = {2,1,2};
    cout<<"maxArea:"<<largestRectangle(heights)<<endl;
    return 0;
}
