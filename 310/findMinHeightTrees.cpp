#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	if(n == 1) return {0};
	vector<int> res;
	vector<unordered_set<int>>adj(n);
	queue<int>q;
	for(auto edge:edges){
		adj[edge.first].insert(edge.second);
		adj[edge.second].insert(edge.first);
	}
	for(int i = 0;i < n;++i){
		if(adj[i].size() == 1){
			q.push(i);
		}
	}
	while(n > 2){
		int size = q.size();
		n -= size;
		for(int i = 0;i < size;++i){
			int t = q.front();
			q.pop();
			for(auto a:adj[t]){
				adj[a].erase(t);
				if(adj[a].size() == 1)q.push(a);
			}
		}
	}
	while(!q.empty()){
		res.push_back(q.front());
		q.pop();
	}
	return res;
}

int main(){
	int n = 6;
	vector<pair<int, int>>edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
	vector<int>res = findMinHeightTrees(n, edges);
    for(auto node : res)
		cout<<node<<" ";
	cout<<endl;
    return 0;
}
