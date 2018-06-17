#include<vector>
#include<iostream>

using namespace std;

int nthUglyNum(int n){
    vector<int>res(1,1);
    int i2 = 0, i3 = 0, i5 = 0;
    while(res.size()< n){
        res.push_back(min(res[i2]*2, min(res[i3]*3, res[i5]*5)));
        if(res.back() % 2 == 0) i2++;
        if(res.back() % 3 == 0) i3++;
        if(res.back() % 5 == 0) i5++;
    }
    return res[n-1];
}
int main(){
    cout<<nthUglyNum(100)<<endl;
    return 0;
}
