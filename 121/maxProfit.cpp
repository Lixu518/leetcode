#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices){
   if(prices.size() == 0) return 0;
	int softMin = prices[0], maxprofit = 0;
	for(int i = 0;i < prices.size();i++){
		if(prices[i] > softMin){
			maxprofit = max(maxprofit, prices[i] - softMin);
		}else{
			softMin = prices[i];
		}
	}
	return maxprofit; 
}

int main(){
	vector<int>prices = {1,2,3,4,1,2,7,8,4,2};
	cout<<"max profit is: "<<maxProfit(prices);
	return 0;
}
