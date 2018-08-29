#include<iostream>
using namespace std;
int rangeBitwiseAnd(int m, int n){
    int i = 0;
    while(m != n){
        m >>= 1;
        n >>= 1;
        i++;
    }
    return m << i;
}

int main(){
    int m = 5, n = 7;
    cout<<rangeBitwiseAnd(m, n)<<endl;
    return 0;
}

