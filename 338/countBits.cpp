#include<iostream>
#include<vector>
using namespace std;
vector<int> countBits(int num){
    vector<int>res(num + 1, 0);
    for(int i = 1;i <= num;++i){
        res[i] = res[i >> 1] + i % 2;
    }
    return res;
}

int main(){
    int num = 5;
    vector<int>res = countBits(num);
    for(auto n : res)
        cout<<n<<" ";
    cout<<endl;
    return 0;
}

