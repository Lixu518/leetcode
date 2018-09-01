#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int countPrimes(int n){
    int res = 0, limit = sqrt(n);
    vector<bool>num(n-1, true);
    num[0] = false;
    for(int i = 0;i <= limit;i++){
        if(num[i-1]){
            for(int j = i*i;j < n;j += i)
                num[j-1] =false;
        }
    }
    for(int i = 0;i < n - 1;i++){
        if(num[i-1])res++;
    }
    return res;
}
int main(){
    int n = 100;
    cout << n << countPrimes(n) << endl;
    return 0;
}

