#include <iostream>
#include <string>
#include <vector>
using namespace std;
string  reorder(string &s){
    if(s.empty() || s.size() == 0)
        return s;
    int start = s.size() - 1, end = s.size() - 1;
    while(start >= 0 && end >= 0){
        if(s[end] != '#'){
            start--;
            end--;
        }else{
            while(start >= 0 && s[start] == '#'){
                start--;
            }
            if(start >= 0){
                swap(s[start], s[end]);
                start--;
                end--;
            }
        }
    }
    return s;
}

int main(){
    string s = "#a#bc#def#";
    string res = reorder(s);
    cout<<res<<endl;
    return 0;
}
