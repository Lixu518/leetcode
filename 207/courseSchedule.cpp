#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites){
    vector<vector<int>>graph(numCourses, vector<int>(0));
    vector<int>in(numCourses, 0);
    for(auto a: prerequisites){
        graph[a.second].push_back(a.first);
        in[a.first]++;
    }
    queue<int>q;
    for(int i = 0;i < numCourses;i++){
        if(in[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(auto a:graph[t]){
            in[a]--;
            if(in[a] == 0)q.push(a);
        }
    }
    for(int i = 0;i < numCourses;i++)
        if(in[i] != 0) return false;
    return true;
}

int main(){
    vector<pair<int, int>> prerequisites;
    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(0, 1));
    cout<<canFinish(2, prerequisites)<<endl;
    return 0;
}
