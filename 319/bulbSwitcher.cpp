#include<iostream>
#include<cmath>
using namespace std;
int bulbSwitch(int n) {
    return sqrt(n);
}
int main(){
    int n = 5;
    cout<<"bulb on: "<<bulbSwitch(n)<<endl;
    return 0;
}
