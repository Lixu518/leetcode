#include<iostream>
#include<vector>
#include<stack>
#include<cstdlib>
#include<string>
using namespace std;
int evalRPN(vector<string>& tokens){
    if(tokens.size() == 1) return atoi(tokens[0].c_str());
    stack<int>s;
    int a = 0,b = 0;
    for(int i = 0;i < tokens.size();i++){
        if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" and tokens[i] != "/"){
            s.push(atoi(tokens[i].c_str()));
        }else{
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            if(tokens[i] == "+") s.push(a+b);
            else if(tokens[i] == "-")s.push(a-b);
            else if(tokens[i] == "*")s.push(a*b);
            else if(tokens[i] == "/")s.push(a/b);
        }
    }
    return s.top();
}

int main(){
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*",
        "17", "+", "5", "+"};
    cout<<"eval RPN reult:"<<evalRPN(tokens)<<endl;
    return 0;
}
