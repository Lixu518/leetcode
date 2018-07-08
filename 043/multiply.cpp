#include<iostream>
#include<vector>
#include<string>
using namespace std;
string multiply(string s1, string s2){
    string res = "";
    vector<int>temp(s1.size() + s2.size() - 1, 0);
    for(int i = 0;i < s1.size();i++){
        int a = s1[i] - '0';
        for(int j = 0;j < s2.size();j++){
            int b = s2[j] - '0';
            temp[i+j] = a*b;
        }
    }
    int extra = 0;
    for(int i = temp.size() - 1;i >= 0;i--){
        int sum = extra + temp[i];
        temp[i] = sum % 10;
        extra = sum/10;
    }
    while(extra != 0){
        int t = extra % 10;
        extra /=10;
        temp.insert(temp.begin(), t);
    }
    for(auto n : temp)
        res += to_string(n);
    if(res.size() > 0 && res[0] == '0') return "0";
    return res;
}

int main(){
    string s1 = "12345", s2 = "2";
    cout<<multiply(s1, s2)<<endl;
    return 0;
}
