#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	vector<vector<string>> res;
	unordered_set<string>dict(wordList.begin(), wordList.end());
	vector<string>temp{beginWord};
	queue<vector<string>>paths;
	paths.push(temp);
	int level = 1, minLevel = INT_MAX;
	unordered_set<string>words;
	while(!paths.empty()){
		auto t = paths.front();
		paths.pop();
		if(t.size() > level){
			for(string w:words) dict.erase(w);
			words.clear();
			level = t.size();
			if(level > minLevel) break;
		}
		string last = t.back();
		for(int i = 0;i < last.size();i++){
			string newLast = last;
			for(char ch = 'a'; ch <= 'z';ch++){
				newLast[i] = ch;
				if(!dict.count(newLast)) continue;
				words.insert(newLast);
				vector<string>nextPath = t;
				nextPath.push_back(newLast);
				if (newLast == endWord) {
					res.push_back(nextPath);
					minLevel = level;
				} else paths.push(nextPath);
			}
		}
	}
	return res;
}

int main(){
	string beginWord = "hit", endWord = "cog";
	vector<string>wordList = {"hot","dot","dog","lot","log","cog"};
	vector<vector<string>>res = findLadders(beginWord, endWord, wordList);
	for(auto a : res){
		for(auto b:a)
            cout<<b<<" ";
		cout<<endl;
	}
}
