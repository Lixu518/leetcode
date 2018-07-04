#include<iostream>
#include<vector>
using namespace std;
vector<int> plusOne(vector<int>& digits){
	int n = digits.size();
	for(int i = n-1; i >= 0;i--){
		if(digits[i] < 9){
			digits[i] += 1;
			return digits;
		}
		digits[i] = 0;
	}
	digits.insert(digits.begin(), 1);
	return digits; 
}
int main(){
	vector<int>digits = {9,9,9,9,9};
	vector<int>res = plusOne(digits);
	for(int i = 0;i < res.size();i++)
		cout<<res[i];
	cout<<endl;
	return 0;
}
