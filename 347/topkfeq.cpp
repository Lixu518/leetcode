#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<unordered_map>
using namespace std;
vector<int> topKFrequent(vector<int>&nums, int k){
    unordered_map<int,int>m;
    for(int i = 0;i < nums.size();i++){
        m[nums[i]]++;
    }
    vector<int>res;
    priority_queue<pair<int, int>>pq;
    for(auto it = m.begin(); it != m.end();it++){
        pq.push(make_pair(it->second, it->first));
        if(pq.size() > (int)(m.size() - k)){
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    return res;
}

int main(){
    vector<int>nums = {1,1,2,2,1,2,3,1,4,3,1,2,1,1,4,5,4,4,};
    vector<int>res = topKFrequent(nums, 4);
    for(auto a : res)
        cout<<a;
    cout<<endl;
    return 0;
}
