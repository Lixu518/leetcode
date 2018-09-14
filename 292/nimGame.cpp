#include<iostream>
using namespace std;
bool canWinNim(int n){
    return n % 4;
}

int main(){
    cout<<canWinNim(8)<<endl;
}

