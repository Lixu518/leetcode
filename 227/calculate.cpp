#include<iostream>
using namespace std;
int calculate(string s){
    int res = 0, curRes = 0, num = 0;
    char op = '+';
    for(int i = 0;i < s.size();i++){
        char c = s[i];
        if(c >= '0' && c <= '9')
        {
            num = num * 10 + c - '0';
        }
        if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.size() - 1){
            switch(op){
                case '+': curRes += num; break;
                case '-': curRes -= num; break;
                case '*': curRes *= num; break;
                case '/': curRes /= num; break;
            }
            if (c == '+' || c == '-' || i == s.size() - 1){
                res += curRes;
                curRes = 0;
            }
            op = c;
            num = 0;
        }
    }
    return res;
}
int main(){
    string s = "10*3 + 1 + 2*19";
    cout<<"result of "<<s<<" is:"<<calculate(s)<<endl;
    return 0;
}

