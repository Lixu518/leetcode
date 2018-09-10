#include<iostream>
#include<vector>
using namespace std;
int hIndex(vector<int>& citations){
    int n = citations.size(), left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right)>>1;
        if(citations[mid] == n - mid) return n - mid;
        else if(citations[mid] > n - mid) right = mid - 1;
        else left = mid + 1;
    }
    return n - left;
}

int main(){
    vector<int> citations = {0,1,3,5,6};
    cout<<"h index of citations is: "<<hIndex(citations)<<endl;
    return 0;
}

