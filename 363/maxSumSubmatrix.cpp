#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int maxSumSubmatrix(vector<vector<int>>& matrix, int k){
	if (matrix.empty() || matrix[0].empty()) return 0;
	int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
	vector<vector<int>> sum(m, vector<int>(n, 0));
	for(int i = 0;i < m;i++)
		for(int j = 0;j < n;j++){
			int tmp = matrix[i][j];
			if(i>0) tmp += sum[i-1][j];
			if(j>0) tmp += sum[i][j-1];
			if(i>0&&j>0) tmp -= sum[i-1][j-1];
			sum[i][j] = tmp;
			for(int r=0;r<=i;r++)
				for(int c=0;c<=j;c++){
					int d = sum[i][j];
					if(r>0) d -= sum[r-1][j];
					if(c>0) d -= sum[i][c-1];
					if(r>0&&c>0) d += sum[r-1][c-1];
					if(d<=k) res = max(res, d);
				  }
		}
	return res;
}
int main(){
    vector<vector<int>> matrix = {{1, 0, 1}, {0, -2, 3}};
    int k = 2;
    cout<<maxSumSubmatrix(matrix, k)<<endl;
    return 0;
}
