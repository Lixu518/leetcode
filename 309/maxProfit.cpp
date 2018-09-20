#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxProfit(vector<int> &prices){
    if(prices.empty() || prices.size() == 0) return 0;
    int len = prices.size();
    vector<int>sell(len, 0), buy(len, INT_MIN);
    buy[0] = -prices[0];
    for(int i = 1;i < len; ++i){
        sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        buy[i] = max(buy[i - 1], (i > 1?sell[i - 2]:0) - prices[i]);
    }
    return sell[len - 1];
}

int main(){
    vector<int> prices = {1,2,3,0,2};
    cout<<"maxProfit: "<<maxProfit(prices)<<endl;
    return 0;
}

