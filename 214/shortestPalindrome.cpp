#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string shortestPalindrome(string s){
    string r = s;
    reverse(r.begin(), r.end());
    string t = s + "#" + r;
    vector<int> next(t.size(), 0);
    for(int i = 1;i < t.size();i++){
        int j = next[i - 1];
        while(j > 0 && t[i] != t[j]) j = next[j - 1];
        next[i] = (j += t[i] == t[j]);
    }
    return r.substr(0, s.size() - next.back()) + s;
}

int main(){
    string s = "adadeq";
    cout<<shortestPalindrome(s)<<endl;
    return 0;
}
