#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void reverseWords(string &s){
    int storeIndex = 0;
    reverse(s.begin(), s.end());
    for(int i = 0;i < s.size(); i++){
        if(s[i] != ' '){
            if(storeIndex != 0)s[storeIndex++] = ' ';
            int j = i;
            while(j < s.size() && s[j] != ' ')s[storeIndex++] = s[j++];
            reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
            i = j;
        }
    }
    s.resize(storeIndex);
}

int main(){
    string s = "hi july hello welcome";
    reverseWords(s);
    cout<<s<<endl;
    return 0;
}
