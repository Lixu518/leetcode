#include<iostream>
#include<unordered_set>
#include<string>
#include<queue>
#include<vector>
using namespace std;

bool isValid(string s){
    int cnt = 0;
    for(int i = 0;i < s.size();++i){
        if(s[i] == '(') ++cnt;
        else if(s[i] == ')' && --cnt < 0) return false;
    }
    return cnt == 0;
}

vector<string> removeInvalidParenthese(string s){
    vector<string>res;
    unordered_set<string>visited({s});
    queue<string>q;
    q.push(s);
    bool found = false;
    while(!q.empty()){
        string t = q.front();
        q.pop();
        if(isValid(t)){
            res.push_back(t);
            found = true;
        }
        if(found) continue;
        for(int i = 0;i < t.size();i++){
            if(t[i] != '(' && t[i] != ')')continue;
            string str = t.substr(0, i) + t.substr(i+1);
            if(!visited.count(str)){
                q.push(str);
                visited.insert(str);
            }
        }
    }
    return res;
}

int main(){
    string s = "((())()()()(()(()()()()))(((()))))))";
    vector<string>res = removeInvalidParenthese(s);
    for(auto str : res){
        cout<<str<<" ";
    }
    cout<<endl;
}
