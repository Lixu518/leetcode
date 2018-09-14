#include<iostream>
#include<unordered_map>
#include<sstream>
using namespace std;
bool wordPattern(string pattern, string str){
    unordered_map<char, string>hash;
    istringstream in(str);
    int i = 0;
    for(string word; in >> word;++i){
        if(hash.find(pattern[i]) != hash.end()){
            if(hash[pattern[i]] != word) return false;
        }
        else{
            for(unordered_map<char, string>::iterator it = hash.begin(); it !=
                    hash.end();++it){
                if(it->second == word) return false;
            }
        }
        hash[pattern[i]] = word;
    }
    return i == pattern.size();
}

int main(){
    string pattern = "dad", str = "cat dog cat";
    cout<<wordPattern(pattern, str)<<endl;
    return 0;
}
