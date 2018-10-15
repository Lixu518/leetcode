#include<iostream>
#include<vector>
using namespace std;
bool isSelfCrossing(vector<int>& x) {
    for(int i = 3; i < x.size();++i){
        if(x[i] >= x[i - 2] && x[i - 3] >= x[i - 1]){
            return true;
        }
        if(i >= 4 && x[i-1] == x[i-3] && x[i] >= x[i-2] - x[i-4]) {
            return true;
        }
        if (i >= 5 && x[i-2] >= x[i-4] && x[i-3] >= x[i-1] && x[i-1] >= x[i-3] - x[i-5] && x[i] >= x[i-2] - x[i-4]) {
            return true;
        }
    }
    return false;
}

int main(){
    vector<int> x = {1, 2, 3,1,4,3,1,3,5,6,3,1};
    cout<<"Is x self crossing ? "<<isSelfCrossing(x)<<endl;
    return 0;
}

