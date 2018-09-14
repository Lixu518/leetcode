#include<iostream>
using namespace std;
string getHint(string secret, string guass){
    int m[256] = {0}, bulls = 0, cows = 0;
    for(int i = 0;i < secret.size();++i){
        if(guass[i] == secret[i]){
            ++bulls;
        }else{
            if(m[secret[i]]++ < 0) ++cows;
            if(m[guass[i]]-- > 0) ++cows;
        }
    }
    return to_string(bulls)+"A"+to_string(cows)+"B";
}

int main(){
    string secret = "12345", guass = "54291";
    cout<<getHint(secret, guass)<<endl;
}
