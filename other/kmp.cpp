#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> getNext(string s){
    int i = 0, j = 0;
    vector<int>next(s.size(), 0);
    while(i < s.size()){
        if(j == 0 || s[i] == s[j]){
            i++;
            j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
    return next;
}

int kmp(string s, string t){
    if(s.empty() || s.size() == 0 || s.size() < t.size())return -1;
    vector<int>next = getNext(t);
    for(int i = 0, j = 0;i < s.size();i++){
        while(j > 0 && t[j] != s[i]){
            j = next[j];
        }
        if(t[j] == s[i])
            j++;
        if(j == t.size())
            return i - t.size() + 1;
    }
    return -1;
}

int main(){
    string s = "abcdabcdacbsd";
    string t = "cda";
    cout<<kmp(s,t);
    cout<<endl;
    return 0;
}
