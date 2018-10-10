#include<iostream>
#include<cmath>
using namespace std;
bool powerOfThree(int n){
    return (n > 0 && int(log10(n)/log10(3)) - log10(n)/log10(3) == 0);
}

int main(){
    int n = 81;
    cout<<"81 is power of three? "<<powerOfThree(n)<<endl;
}

