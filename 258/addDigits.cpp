#include<iostream>
using namespace std;
int addDigits(int n){
    return (n - 1) % 9 + 1;
}
int main(){
    cout<<addDigits(1119)<<endl;
}
