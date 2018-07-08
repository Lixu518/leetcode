#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int largestRectangle(vector<int> heights){
	if(heights.empty() || heights.size() == 0)return 0;
	stack<int>s;
    int h, w, maxArea = 0;
    heights.push_back(0);
	for(int i = 0;i < heights.size();i++){
		if(s.empty() || heights[s.top()] < heights[i])
			s.push(i);
		else{
			while(!s.empty() && heights[s.top()] >= heights[i]){
				h = heights[s.top()];
                s.pop();
        		w = s.empty() ? i:(i - (s.top() + 1));
				maxArea = max(maxArea, h*w);
			}
            s.push(i);
		}
	}
	return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
	if(matrix.empty() || matrix.size() == 0 || matrix[0].size() == 0) return 0;
	vector<int>heights(matrix[0].size(), 0);
	int maxRect = 0;
	for(int i = 0;i < matrix.size();i++){
		for(int j = 0;j < matrix[0].size();j++){
			heights[j] = (matrix[i][j] == '0')?0:(1 + heights[j]);
        }
		maxRect = max(maxRect, largestRectangle(heights));
	}
	return maxRect;
}

int main(){
    vector<char> v1 = {'1','0','1','0','0'}, v2 = {'1','0','1','1','1'}, v3 = {'1','1','1','1','1'}, v4 = {'1','0','0','1','0'};
	vector< vector<char> > matrix = { v1, v2, v3, v4 };
    cout<<maximalRectangle(matrix);
	return 0;
}
