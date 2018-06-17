#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector<string> topKFeqWords(vector<string>&words,int k){
    vector<string>res;
    if(words.empty()||words.size()<k) return res;
    unordered_map<string, int>hash;
    for(auto word:words) hash[word]++;
    map<int, set<string>>mp;
    for(auto a:hash)mp[a.second].insert(a.first);
    for(auto it = mp.rbegin();it!=mp.rend();it++){
        if(k < 0) break;
        auto t = it->second;
        vector<string>v(t.begin(), t.end());
        if(k >= t.size())
            res.insert(res.end(), v.begin(), v.end());
        else
            res.insert(res.end(), v.begin(), v.begin()+k);
        k -= t.size();
    }
    return res;
}

int main(){
    vector<string>words = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string>res = topKFeqWords(words, 2);
    for(int i = 0;i<res.size();i++)
        cout<<res[i];
    return 0;
}
