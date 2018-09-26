#include<iostream>
#include<string>
using namespace std;
string removeDuplicateLetters(string s) {
	int m[256] = {0}, visited[256] = {0};
	string res = "0";
	for(auto a:s)   ++m[a];
	for(auto a:s){
		--m[a];
		if(visited[a])continue;
		while(a < res.back() && m[res.back()]){
			visited[res.back()] = 0;
			res.pop_back();
		}
		res += a;
		visited[a] = 1;
	}
	return res.substr(1);
}

int main(){
	string s = "cbacdcbc";
	cout<<"remove Duplicate Letters:"<<removeDuplicateLetters(s)<<endl;
	return 0;
}

