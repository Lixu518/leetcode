#include<iostream>
#include<string>
using namespace std;
bool isVowel(char c){
    if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
        return true;
    return false;
}

string reverseVowels(string s) {
    int left = 0, right = s.size() - 1;
    while(left < right){
        if(isVowel(s[left]) && isVowel(s[right])){
            swap(s[left++], s[right--]);
        }
        else if (isVowel(s[left])){
            --right;
        }else{
            ++left;
        }
    }
    return s;
}
int main(){
    string s = "hello", res = reverseVowels(s);
    cout<<res<<endl;
}
