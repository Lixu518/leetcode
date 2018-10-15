#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include<utility>
#include<unordered_map>
using namespace std;
vector<string> findItinerary(vector<pair<string, string>> tickets) {
    vector<string>res;
    unordered_map<string, multiset<string>>m;
    stack<string>st{{"JFK"}};
    for(auto t:tickets){
        m[t.first].insert(t.second);
    }
    while(!st.empty()){
        string t = st.top();
        if(m[t].empty()){
            res.insert(res.begin(), t);
            st.pop();
        }else{
            st.push(*m[t].begin());
            m[t].erase(m[t].begin());
        }
    }
    return res;
}

int main(){
    vector<pair<string, string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    vector<string> res = findItinerary(tickets);
    for(auto t:res)
        cout<<t<<" ";
    cout<<endl;
    return 0;
}

