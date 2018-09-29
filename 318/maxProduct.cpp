#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;
int maxProduct(vector<string>& words) {
	int res = 0;
	unordered_map<int, int>m;
	for(string word:words){
		int mask = 0;
		for(auto c:word){
			mask |= 1<<(c - 'a');
			
		}
		m[mask] = max(m[mask], int(word.size()));
		for(auto a:m){
			if(!(mask & a.first)){
				res = max(res, (int)word.size() * a.second);
			}
		}
	}
	return res;
}

int main(){
	vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
	cout<<"maxProduct: "<<maxProduct(words)<<endl;
	return 0;
}
