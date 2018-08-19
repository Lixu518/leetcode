#include<iostream>
#include<vector>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
    int total = 0, start = 0, sum = 0;
    for(int i = 0;i < gas.size(); i++){
        total += gas[i] - cost[i];
        sum += gas[i] - cost[i];
        if(sum < 0){
            start = i + 1;
            sum = 0;
        }
    }
    return  total < 0 ? -1 : start;
}

int main(){
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout<<"start pos:"<<canCompleteCircuit(gas, cost)<<endl;
    return 0;
}
