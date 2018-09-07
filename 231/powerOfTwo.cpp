#include<iostream>
using namespace std;
bool powerOfTwo(int n){
    return n > 0 && (!(n & (n-1)));
}
int main(){
    cout<<"16 is power of 2:"<<powerOfTwo(16)<<endl;
    cout<<"15 is power of 2:"<<powerOfTwo(15)<<endl;
}
