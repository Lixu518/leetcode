#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<pair<int, int> >&prerequisites){
    vector<int> res;
    vector<vector<int> > graph(numCourses, vector<int>(0));
    vector<int>in(numCourses, 0);
    for(auto &a: prerequisites){
        graph[a.second].push_back(a.first);
        in[a.first]++;
    }
    queue<int>q;
    for(int i = 0;i < numCourses;i++){
        if(in[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int t = q.front();
        res.push_back(t);
        q.pop();
        for(auto a:graph[t]){
            in[a]--;
            if(in[a] == 0)q.push(a);
        }
    }
    if(res.size() != numCourses) res.clear();
    return res;
}

int main(void){
    int numCourses = 4;
    vector<pair<int, int> >prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 0));
    prerequisites.push_back(make_pair(3, 1));
    prerequisites.push_back(make_pair(3, 2));
    vector<int> res = findOrder(numCourses, prerequisites);
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}

