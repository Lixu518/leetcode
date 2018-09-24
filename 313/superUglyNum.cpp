#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int nthSuperUglyNumber(int n, vector<int> &primes){
    vector<int>dp(n, 1), idx(primes.size(), 0);
    for(int i = 1;i < n;++i){
        dp[i] = INT_MAX;
        for(int j = 0;j < primes.size();++j){
            dp[i] = min(dp[i], dp[idx[j]] * primes[j]);
        }
        for(int j = 0;j < primes.size();++j){
            if(dp[i] == dp[idx[j]] * primes[j])++idx[j];
        }
    }
    return dp.back();
}

int main(){
    int n = 12;
    vector<int> primes = {2,7,13,19};
    cout<<"result: "<<nthSuperUglyNumber(n, primes)<<endl;
    return 0;
}

