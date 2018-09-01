#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
vector<string> findRepeatedDnaSequences(string s){
    set<string>st, res;
    for(int i = 0;i + 9< s.size();i++){
        string t = s.substr(i, 10);
        if(st.count(t)) res.insert(t);
        else st.insert(t);
    }
    return vector<string>(res.begin(), res.end());
}

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string>res = findRepeatedDnaSequences(s);
    for(auto t:res)
        cout<<t<<" ";
    cout<<endl;
    return 0;
}
