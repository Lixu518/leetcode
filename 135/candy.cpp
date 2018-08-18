#include<iostream>
#include<vector>
using namespace std;

int candy(vector<int>& ratings){
    if(ratings.empty()) return 0;
    int res = 1, pre = 1, cnt = 0;
    for(int i = 1;i < ratings.size();i++){
        if(ratings[i] >= ratings[i - 1]){
            if(cnt > 0){
                res += cnt * (cnt + 1)/2;
                res += (cnt >= pre)?(cnt - pre + 1):0;
                pre = 1;
                cnt = 0;
            }
            pre = (ratings[i] == ratings[i-1]) ? 1 : pre + 1;
            res += pre;
        }
        else{
            cnt++;}
    }
    if(cnt > 0){
        res += cnt * (cnt + 1)/2;
        res += (cnt >= pre)?(cnt - pre + 1):0;
    }
    return res;
}

int main(){
    vector<int> ratings = {1, 2, 3, 3, 2, 1};
    cout<<"candy cnt:"<<candy(ratings)<<endl;
    return 0;
}

