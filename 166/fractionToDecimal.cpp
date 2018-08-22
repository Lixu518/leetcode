#include<iostream>
#include<unordered_map>
#include<string>
#include<cstdlib>
using namespace std;
string fractionToDecimal(int numerator, int denominator) {
    int s1 = numerator > 0 ? 1 : -1;
    int s2 = denominator > 0 ? 1 : -1;
    long long num = abs((long long) numerator);
    long long den = abs((long long) denominator);
    long long out = num/den;
    long long rem = num % den;
    unordered_map<long long, int>hash;
    string res = to_string(out);
    if(s1 * s2 == -1 && (out > 0 || rem > 0)) res = "-" + res;
    if (rem == 0) return res;
    res += ".";
    string s = "";
    int pos = 0;
    while(rem != 0){
        if(hash.find(rem) != hash.end()){
            s.insert(hash[rem], "(");
            s += ")";
            return res + s;
        }
        hash[rem] = pos;
        s += to_string((rem * 10) / den);
        rem = (rem * 10) % den;
        ++pos;
    }
    return res + s;
}

int main(){
    int numberator = 4;
    int denominator = 3;
    cout<<"Result: "<<fractionToDecimal(numberator, denominator)<<endl;
    return 0;
};
