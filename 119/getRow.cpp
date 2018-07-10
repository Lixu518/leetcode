#include<iostream>
#include<vector>
using namespace std;
vector<int> getRow(int rowIndex) {
	vector<int>res;
	for(int i = 0;i <= rowIndex;i++){
		res.resize(i+1);
		res[0] = res[i] = 1;
		for(int j = i-1; j > 0;j--)
			res[j] = res[j] + res[j-1];
	}
	return res;
}

int main(){
	vector<int>res = getRow(7);
	for(auto num :res)
		cout<<num<<" ";
	return 0;
}
