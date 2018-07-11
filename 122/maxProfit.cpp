#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices){
   if(prices.empty() || prices.size() <= 1)return 0;
	int maxprofit = 0;
	for(int i = prices.size() - 1;i > 0 ;i--)
		maxprofit += (prices[i] > prices[i-1])?(prices[i] - prices[i-1]):0;
	return maxprofit; 
}

int main(){
	vector<int>prices = {1,2,3,1,3,4,6,3,1,4,9,10};
	cout<<"max profit: "<<maxProfit(prices)<<endl;
	return 0;
}
