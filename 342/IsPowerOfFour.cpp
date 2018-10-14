#include<iostream>
#include<cmath>
using namespace std;
bool isPowerOfFour1(int n){
    return (n > 0 && int(log10(n) / log10(4)) - log10(n)/log10(4) == 0);
}

bool isPowerOfFour2(int n){
    return n > 0 && !(n & (n - 1)) && (n & 0x55555555) == n;
}

bool isPowerOfFour3(int n){
    return n > 0 && !(n & (n - 1)) && (n - 1) % 3 == 0;
}

int main(){
    int n = 64;
    cout<<"64 is pour of four ?"<<isPowerOfFour1(n)<<" "<<isPowerOfFour2(n)<<" "<<isPowerOfFour3(n)<<endl;
    return 0;
}

