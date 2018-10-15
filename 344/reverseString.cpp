#include<iostream>
#include<string>
using namespace std;
string reverseString(string s){
    int left = 0, right = s.size() - 1;
    while(left < right){
        swap(s[left++], s[right--]);
    }
    return s;
}
int main(){
    string s = "hello", res = reverseString(s);
    cout<<res<<endl;
    return 0;
}

