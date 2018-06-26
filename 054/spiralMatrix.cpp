#include<iostream>
#include<vector>
using namespace std;
vector<int>  spiralMatrix(vector<vector<int>>& matrix){
	vector<int>res;
    if(matrix.empty())
            return res;
    int colBegin = 0, rowBegin = 0, colEnd = matrix[0].size() - 1, rowEnd = matrix.size() - 1;
    while(colBegin <= colEnd && rowBegin <= rowEnd){
    	for(int j = colBegin; j <= colEnd;j++)
        	res.push_back(matrix[rowBegin][j]);
    	rowBegin++;
    	for(int i = rowBegin; i <= rowEnd;i++)
            res.push_back(matrix[i][colEnd]);
    	colEnd--;
    	if(rowBegin <= rowEnd){
    		for(int j = colEnd; j >= colBegin;j--)
            	res.push_back(matrix[rowEnd][j]);  
    	}
    	rowEnd--;
        if(colBegin <= colEnd){
            for(int i = rowEnd;i >= rowBegin;i--)
                res.push_back(matrix[i][colBegin]);	
        }
        colBegin++;
	}
    return res;    
}

int main(){
	vector<vector<int>> matrix = {
  								{1, 2, 3, 4},
  								{5, 6, 7, 8},
  								{9,10,11,12}
								};
	vector<int> res = spiralMatrix(matrix);
	for(int i = 0;i < res.size();i++)
        cout<<res[i]<<' ';
	cout<<endl;
}
