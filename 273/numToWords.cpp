#include<iostream>
#include<vector>
#include<string>
using namespace std;
string convertHundred(int num){
    vector<string> v1 = {"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen", "Nineteen"};
    vector<string> v2 = {"", "", "Twenty", "Thirty", "Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    int a = num / 100, b = num % 100, c = num % 10;
    string res;
    res = (b < 20) ? v1[b] : v2[b /10]+ (c ? " " + v1[c]:"");
    if(a > 0)res = v1[a] + " Hundred"+ (b ? " " + res : res);
    return res;
}

string numberToWords(int num) {
    vector<string> v = {"Thousand","Million","Billion"};
    string res = convertHundred(num%1000);
    for(int i = 0;i < 3;i++){
        num = num /1000;
        res = (num % 1000) ?(convertHundred(num % 1000) + " " + v[i] + " " + res): res;
    }
    while(res.back() == ' ') res.pop_back();
    return res.empty()?"Zero":res;
}

int main(){
    int n = 123456789;
    cout<<n<<" to words is: "<<numberToWords(n)<<endl;
    return 0;
}
