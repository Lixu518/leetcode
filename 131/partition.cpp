#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isPalindrome(string s, int start, int end){
    while(start < end){
        if(s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
}

void dfs(string s, vector<vector<string>> &res, vector<string>&temp, int start){
    if(start == s.size()){
        res.push_back(temp);
        return;
    }
    for(int i = start;i < s.size();i++){
        if(isPalindrome(s, start, i)){
            temp.push_back(s.substr(start, i-start+1));
            dfs(s, res, temp, i  + 1);
            temp.pop_back();
        }

    }

}
vector<vector<string>> partition(string s) {
    vector<vector<string>>res;
    vector<string>temp;
    if(s.empty()) return res;
    dfs(s, res, temp, 0);
    return res;
}

int main(){
    string s = "aabbba";
    vector<vector<string>> res = partition(s);
    for(auto row:res){
        for(auto str:row)
            cout<<str<<" ";
        cout<<endl;
    }
    return 0;
}
