#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int>& prices) {
	if(prices.empty() || prices.size() <= 1) return 0;
	vector<int>global(3,0);
	vector<int>local(3,0);
	for(int i = 0;i < prices.size() - 1;i++){
		int diff = prices[i+1] - prices[i];
		for(int j = 2; j >= 1; j--){
			local[j] = max(global[j - 1] + (diff > 0 ? diff :0), local[j] + diff);
			global[j] = max(local[j], global[j]);
		}
	}
	return global[2];
}

int main(){
	vector<int> prices = {1,2,31,2,42,12,42,14,53,24,10};
	cout<<"maxProfit: "<<maxProfit(prices)<<endl;
	return 0;
}
